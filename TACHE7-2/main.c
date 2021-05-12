#include<stdio.h>
#include<string.h>

#include "geom2d.h"
#include "image.h"
#include "option.h"
#include "contour_image.h"
#include "tab_variable.h"
#include "mod_eps.h"
#include "simplification.h"

/*
 ./main [OPTION] <Image>
 
 Options:
  -h,       --help              Affiche ce message et s'arrete.
  -b2       --simpBezier2       simplifie l'image grace a des courbe de type Bezier2
  -b3       --simpBezier3       simplifie l'image grace a des courbe de type Bezier3
*/

int main(int argc , char *argv[]){
    int arg;
    char *f_image = NULL;

    int simp_bezier_2 = 0;
    int simp_bezier_3 = 0;
    
    Image I;
    
    tab_points t;
    tab_contour contour;
    init_tab(&t);
    init_tab_contour(&contour);

    if (argc < 2) {
        usage(argv[0]);
        return 1;
    }

    arg = 1;
    while (arg < argc) {
        if (strcmp(argv[arg], "--help") == 0 || strcmp(argv[arg], "-h") == 0){
            usage(argv[0]);
            return 1;
        }
        else if (strcmp(argv[arg], "--simpBezier2") == 0 || strcmp(argv[arg], "-b2") == 0){
              arg++;
              simp_bezier_2 = 1;
        }
        else if (strcmp(argv[arg], "--simpBezier3") == 0 || strcmp(argv[arg], "-b3") == 0){
              arg++;
              simp_bezier_3 = 1;
        }
       
        else if (argv[arg][0] == '-') {
            fprintf(stderr, "Option inconnue : '%s'\n -h pour plus de details\n", argv[arg]);
            return 1;
        }
        
         else if (f_image == NULL) {
            f_image = argv[arg];
            printf("%s\n\n", f_image);
            arg++;
        }
        else{
            printf("nom de l'image incorrect");
            usage(argv[0]);
            return 1;
        }
    }

    if (f_image != NULL){
        I = lire_fichier_image(f_image);
    }else{
        usage(argv[0]);
        return 1;
    }

        /*recuperation du coutour */

    Robot R;
    double x,y;
    Point p;

    Image masque = calculer_masque_image(I);
    printf("travail en cour ....\n");

    while (pixels_noir_image(masque) == 1) {
        init_tab(&t);
        trouver_pixel_depart(&x,&y,masque);
        x--;
        y--;
            
        R = intitialiser_robot(x,y,EST);
            
        do {
            p = set_point(R.x , R.y);
            add_cell_tab(&t, p);
            maj_masque(&masque, R.o , p);

                
            avancer(&R);
            nouvelle_orientation(&R, I);
                
        } while(!( (R.x == x) && (R.y ==y) && (R.o == EST) ));
        add_cell_tab(&t, t.t[0]);

        add_cell_tab_contour(&contour, t);
    }

        /*========================*/


    if (simp_bezier_2 == 1){
        tab_bezier2 tab_p;
        
        tab_contour_bezier2 tab_c;
        init_tab_contour_bezier2(&tab_c);

        int distance_seuil;
        printf("taille de la distance seuil : ");
        scanf("%d",&distance_seuil);

        for (int i = 0; i < contour.taille; i++) {
            init_tab_bezier2(&tab_p);
            tab_p = simplification_douglas_peucker_2(contour.t[i],0,contour.t[i].taille-1, distance_seuil);
            add_cell_tab_contour_bezier2(&tab_c,tab_p);
        }

        int nb_segments = 0;
        for (size_t i = 0; i < tab_c.taille; i++) {
          nb_segments = tab_c.t[i].taille + nb_segments;
        }
         printf("il y a %d courbes dans le fichier.\n", nb_segments/2);

        /*=================*/
        FILE *file_eps = NULL;
        Bezier3 courbe;
      printf("ecriture du fichier .eps ....\n");

      file_eps = fopen("out.eps", "w");
      entete_eps(file_eps, largeur_image(I), hauteur_image(I));
      for (int c = 0; c < tab_c.taille; c++) {
          courbe = conversion_bezier2_in_bezier3(tab_c.t[c].t[0]);
          move_to_bezier3(file_eps, courbe, hauteur_image(I));
        for(int i = 1 ; i < tab_c.t[c].taille ; i++){
            courbe = conversion_bezier2_in_bezier3(tab_c.t[c].t[i]);
            trace_bezier3(file_eps, courbe, hauteur_image(I));
        }
      }

      end_eps(file_eps); 
      
      fclose(file_eps);
    }

    if (simp_bezier_3 == 1){
        tab_bezier3 tab_p;
        
        tab_contour_bezier3 tab_c;
        init_tab_contour_bezier3(&tab_c);

        int distance_seuil;
        printf("taille de la distance seuil : ");
        scanf("%d",&distance_seuil);

        for (int i = 0; i < contour.taille; i++) {
            init_tab_bezier3(&tab_p);
            tab_p = simplification_douglas_peucker_3(contour.t[i],0,contour.t[i].taille-1, distance_seuil);
            add_cell_tab_contour_bezier3(&tab_c,tab_p);
        }

        int nb_segments = 0;
        for (size_t i = 0; i < tab_c.taille; i++) {
          nb_segments = tab_c.t[i].taille + nb_segments;
        }
         printf("il y a %d courbes dans le fichier.\n", nb_segments/2);

        /*=================*/
        FILE *file_eps = NULL;
      printf("ecriture du fichier .eps ....\n");

      file_eps = fopen("out.eps", "w");
      entete_eps(file_eps, largeur_image(I), hauteur_image(I));
      for (int c = 0; c < tab_c.taille; c++) {
          move_to_bezier3(file_eps, tab_c.t[c].t[0], hauteur_image(I));
        for(int i = 1 ; i < tab_c.t[c].taille ; i++){
            trace_bezier3(file_eps, tab_c.t[c].t[i], hauteur_image(I));
        }
      }
      end_eps(file_eps); 
      fclose(file_eps);
    }
    return 0;
}
#include<stdio.h>
#include<string.h>

#include "geom2d.h"
#include "image.h"
#include "option.h"
#include "contour_image.h"
#include "tab_variable.h"
#include "mod_eps.h"

/*
 ./main [OPTION] <Image>
 
 Options:
  -h,       --help              Affiche ce message et s'arrete.
  -ct       --contourT          stock le contour dans un tableau a taille variable et l'affiche.
  -s        --save              auvegarde le contour au format ".contour.txt"
  -eps      --fichierEps        cree un fichier eps pour l'image en parametre.
*/

int main(int argc , char *argv[]){
    int arg;
    char *f_image = NULL;

    int contour_tab = 0;
    int f_eps = 0;
    int save_contour_txt = 0;
    
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
        else if (strcmp(argv[arg], "--contourT") == 0 || strcmp(argv[arg], "-ct") == 0){
            arg++;
            contour_tab = 1;
        }
        else if (strcmp(argv[arg], "--fichierEps") == 0 || strcmp(argv[arg], "-eps") == 0){
              arg++;
              f_eps = 1;
              contour_tab = 1;
        }
        else if (strcmp(argv[arg], "--save") == 0 || strcmp(argv[arg], "-s") == 0){
              arg++;
              save_contour_txt = 1;
              contour_tab = 1;
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

    if(contour_tab){
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
            //printf("%f %f", x, y);
            
            R = intitialiser_robot(x,y,EST);
            
            do {
                p = set_point(R.x , R.y);
                add_cell_tab(&t, p);
                maj_masque(&masque, R.o , p);

                
                avancer(&R);
                nouvelle_orientation(&R, I);
                
            } while(!( (R.x == x) && (R.y ==y) && (R.o == EST) ));

            add_cell_tab_contour(&contour, t);
            //suppr_tab(&t);

        }

    printf("%s:\n", f_image);
    printf("\t%d contours\n" , taille_tab_contour(contour));
    int nb_points = 0;
    for (int i = 0; i < contour.taille; i++) {
        nb_points = nb_points + contour.t[i].taille;
    }
    printf("\t%d segments\n", nb_points);

    }

    
    if(f_eps == 1){
      FILE *file_eps = NULL;

      printf("ecriture du fichier .eps ....\n");

      file_eps = fopen("out.eps", "w");
      entete_eps(file_eps, largeur_image(I), hauteur_image(I));
      for (int c = 0; c < contour.taille; c++) {
        move_to_eps(file_eps, contour.t[c].t[0], hauteur_image(I));
        for(int i = 1 ; i < contour.t[c].taille ; i++){
            line_to_eps(file_eps, contour.t[c].t[i], hauteur_image(I));
        }
      }

      end_eps(file_eps); 
      
      fclose(file_eps);
    }

    if (save_contour_txt == 1){
    save_tab_contour_fichier("out", contour);
    }
    return 0;
}
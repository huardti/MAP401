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
  -epss     --fichierEpsS       cree un fichier eps avec comme parametre une ligne pour l'image en argument.
  -epssp    --fichierEpsSp      cree un fichier eps avec comme parametre ligne + point pour l'image en argument.
  -eps      f--fichierEpsF      cree un fichier eps avec comme parametre fill pour l'image en argument.
*/

int main(int argc , char *argv[]){
    int arg;
    char *f_image = NULL;

    int contour_tab = 0;
    param_eps f_eps = VOID;
    
    Image I;
    
    tab t;
    init_tab(&t);

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
        else if (strcmp(argv[arg], "--fichierEpsS") == 0 || strcmp(argv[arg], "-epss") == 0){
            arg++;
            f_eps = S;
            contour_tab = 1;
        }
        else if (strcmp(argv[arg], "--fichierEpsSp") == 0 || strcmp(argv[arg], "-epssp") == 0){
              arg++;
              f_eps = SP;
              contour_tab = 1;
        }
        else if (strcmp(argv[arg], "--fichierEpsF") == 0 || strcmp(argv[arg], "-epsf") == 0){
              arg++;
              f_eps = F;
              contour_tab = 1;
        }
       
        else if (argv[arg][0] == '-') {
            fprintf(stderr, "Option inconnue : '%s'\n", argv[arg]);
            return 1;
        }
         else if (f_image == NULL) {
            f_image = argv[arg];
            printf("%s\n\n", f_image);
            arg++;
        }
        else{
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

        trouver_pixel_depart(&x,&y,I);

        x--;
        y--;
        
        R = intitialiser_robot(x,y,EST);
        
        do {
            p = set_point(R.x , R.y);
            add_cell_tab(&t, p);
            
            avancer(&R);
            nouvelle_orientation(&R, I);
            
        } while(!( (R.x == x) && (R.y ==y) && (R.o == EST) ));

        for (int i = 0; i < taille_tab(t); i++) {
            printf("%.1f %.1f\n", t.t[i].x, t.t[i].y);
        }
        printf("il y a %d points dans le tableau\n" , taille_tab(t));
    }
    
    if(!(f_eps == VOID)){
      FILE *file_eps = NULL;
      
      file_eps = fopen("out.eps", "w");
      
      entete_eps(file_eps, largeur_image(I), hauteur_image(I));
      
      int i = 0;
      move_to_eps(file_eps, t.t[0], hauteur_image(I));
      for(i = 1 ; i < taille_tab(t) ; i++){
        line_to_eps(file_eps, t.t[i], hauteur_image(I));
      }
      end_eps(file_eps,f_eps);  
      
      fclose(file_eps);
    }
    
    
    //suppr_tab(&t);
    return 0;
}
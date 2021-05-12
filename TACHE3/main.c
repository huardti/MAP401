#include<stdio.h>
#include<string.h>

#include "geom2d.h"
#include "image.h"
#include "option.h"
#include "contour_image.h"
#include "tab_variable.h"

/*
 ./main [OPTION] <Image>
 
 Options:
  -h, --help          Affiche ce message et s'arrete.
  -c, --contour       Affiche sur la sortie standard la liste des points qui compose le contour de l'image.
  -ct --contourT      stock le contour dans un tableau a taille variable et l'affiche
  -p, --printImg      tAffiche l'image <Image> avec des 0 pour representer le blanc et 1 pour le noir.
*/


int main(int argc , char *argv[]){
    int arg;
    char *f_image = NULL;

    int contour = 0;
    int ecrire_img = 0;
    int contour_tab = 0;
    Image I;

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
        else if (strcmp(argv[arg], "--contour") == 0 || strcmp(argv[arg], "-c") == 0){
            arg++;
            contour = 1;
        }
        else if (strcmp(argv[arg], "--contourT") == 0 || strcmp(argv[arg], "-ct") == 0){
            arg++;
            contour_tab = 1;
        }
        else if (strcmp(argv[arg], "--printImg") == 0 || strcmp(argv[arg], "-p") == 0){
            arg++;
            ecrire_img = 1;
        }
       
        else if (argv[arg][0] == '-') {
            fprintf(stderr, "Option inconnue : '%s'\n", argv[arg]);
            return 1;
        }
         else if (f_image == NULL) {
            f_image = argv[arg];
            printf("%s\n\n", f_image);
            arg++;
        }else{
            usage(argv[0]);
            return 1;
        }
    }

    if (f_image != NULL){
        I = lire_fichier_image(f_image);
    }else{
        usage(argv[0]);
    }

    if(ecrire_img){
        ecrire_image(I);
        printf("\n");
    }

    if (contour){
        Robot R;
        double x,y;
        trouver_pixel_depart(&x,&y,I);

        x--;
        y--;
        
        R = intitialiser_robot(x,y,EST);
        
        do {
            print_position(R);
            avancer(&R);
            nouvelle_orientation(&R, I);
            
        } while(!( (R.x == x) && (R.y ==y) && (R.o == EST) ));
        printf("\n");
    }

    if(contour_tab){
        Robot R;
        double x,y;
        tab t;
        Point p;
        init_tab(&t);

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

        suppr_tab(&t);
    }
    return 0;
}
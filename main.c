#include<stdio.h>
#include<string.h>

#include "geom2d.h"
#include "image.h"
#include "option.h"
#include "contour_image.h"


int main(int argc , char *argv[]){
    int arg;
    char *f_image = NULL;

    int contour = 0;
    int ecrire_img = 0;

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
            memoriser_position(R);
            avancer(&R);
            nouvelle_orientation(&R, I);
            
        } while(!( (R.x == x) && (R.y ==y) && (R.o == EST) ));
        printf("\n");
    }

    return 0;
}
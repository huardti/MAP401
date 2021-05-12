#include <stdio.h>
#include "image.h"
#include "types_macros.h"

int main(int argc , char ** argv){
	Image I;
	Image J;
	Pixel p;
	
	if (argc != 2){
		printf("Erreur d'arguments");
		exit(0);
	}
	I = lire_fichier_image(argv[1]);
	ecrire_image(I);
	
	J = creer_image(9,9);
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			if(i==j){
				set_pixel_image(J,j,i,NOIR);
			}
		}
	}
	printf("\n");
	ecrire_image(J);
	printf("\n");
	
	p=get_pixel_image(J,1,1);
	if(p == NOIR){
		printf("noir\n");}
	else{
		printf("blanc\n");}
	
	supprimer_image(&I);
	supprimer_image(&J);
	return 0;
}

#include <stdio.h>
#include "geom2d.h"

int main(){

	Vecteur V,W,X,Y,Z;
	Point A,B;
	
	A = set_point(0.0 , -2.0);
	B = set_point(1.5 , 1.0);
	
	V = set_vecteur(1.0 , 3.0);
	W = set_vecteur(-1.0 , -1.0);
	
	X = vect_bipoint(A ,B);
	
	Y = multiplier_vecteur(V, 0.5);
	Z = somme_vecteur(V,W);
	
	printf("la somme des point a et b est :");print_point(add_point(A,B));printf("\n");
	
	printf("le vecteur X vaut : "); print_vecteur(X); printf("\n");
	printf("le vecteur Y vaut : "); print_vecteur(Y); printf("\n");
	printf("le vecteur Z vaut : "); print_vecteur(Z); printf("\n");
	
	printf("Le produit scalair des vecteurs V et W est : %f \n",p_scalaire_vecteur(V,W));
	printf("La norme du vecteurs V est : %f \n",norme_vecteur(V));

return 0;
}

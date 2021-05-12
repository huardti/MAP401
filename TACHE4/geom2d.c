#include <math.h>
#include <stdio.h>

#include "geom2d.h"

/* cree le point de coordonnées x,y */
Point set_point(double x , double y){
	Point P = {x,y};
	return P;
}

/* somme P1 + P2 */
Point add_point(Point P1 , Point P2){
	return set_point(P1.x + P2.x , P1.y + P2.y);
}

/* vecteur correspondant au bipoint AB */
Vecteur vect_bipoint(Point A , Point B){
	Vecteur V = {B.x-A.x,B.y-A.y};
	return V;
}

/* cree un veceur a partir de x et y */
Vecteur set_vecteur(double x , double y){
	Vecteur V;
	V.x=x;
	V.y=y;
	return V;
}

/* miliplication de vecteur */
Vecteur multiplier_vecteur(Vecteur V, double r){
	V.x=r*(V.x);
	V.y=r*(V.y);
	return V;
}

/* retourne la norme d'un vecteur */
double norme_vecteur(Vecteur V){
	return sqrt((V.x * V.x)+(V.y * V.y));
}

/* produit scalaire de v1 et v2 */
double p_scalaire_vecteur(Vecteur V1 , Vecteur V2){
	return V1.x*V2.x + V1.y*V2.y;
}

/*Somme de deux vecteurs*/
Vecteur somme_vecteur(Vecteur V1, Vecteur V2){
	Vecteur V;
	V.x = V1.x + V2.x;
	V.y = V1.y + V2.y;
	return V;
}

void print_vecteur(Vecteur V){
	printf("(%f , %f)", V.x , V.y);
}

void print_point(Point P){
	printf("(%f , %f)", P.x , P.y);
}

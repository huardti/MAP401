#ifndef _GEOM2D_H_
#define _GEOM2D_H_

typedef struct Vecteur_ {
	double x,y; 
}Vecteur;

typedef struct Point_ {
	double x,y;
}Point;

/* cree le point de coordonnées x,y */
Point set_point(double x , double y);

/* somme P1 + P2 */
Point add_point(Point P1 , Point P2);

/* soustrait p2 a p1*/
Point sub_point(Point P1 , Point P2);

/* vecteur correspondant au bipoint AB */
Vecteur vect_bipoint(Point A , Point B);

/* cree un veceur a partir de x et y */
Vecteur set_vecteur(double x , double y);

/* miliplication de vecteur */
Vecteur multiplier_vecteur(Vecteur V, double r);

/* retourne la norme d'un vecteur */
double norme_vecteur(Vecteur V);

/* produit scalaire de v1 et v2 */
double p_scalaire_vecteur(Vecteur V1 , Vecteur V2);

Vecteur somme_vecteur(Vecteur V1, Vecteur V2);

void print_vecteur(Vecteur V);

void print_point(Point P);

double distance_point_segment(Point P, Point A, Point B);
#endif /* _GEOM2D_H_ */

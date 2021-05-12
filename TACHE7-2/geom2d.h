#ifndef _GEOM2D_H_
#define _GEOM2D_H_

typedef struct Vecteur_ {
	double x,y; 
}Vecteur;

typedef struct Point_ {
	double x,y;
}Point;

typedef struct Bezier2_ {
	Point C0, C1, C2;
}Bezier2;

typedef struct Bezier3_ {
	Point C0, C1, C2, C3;
}Bezier3;

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

/*  Multiplier Points*/
Point mult_point(Point pa, double r);

/* Div point*/
Point div_point(Point pa, double r);


/* miliplication de vecteur */
Vecteur multiplier_vecteur(Vecteur V, double r);

/* retourne la norme d'un vecteur */
double norme_vecteur(Vecteur V);

/* produit scalaire de v1 et v2 */
double p_scalaire_vecteur(Vecteur V1 , Vecteur V2);

/* effectue la somme de 2 vecteurs */
Vecteur somme_vecteur(Vecteur V1, Vecteur V2);

/* affiche un vecteur */
void print_vecteur(Vecteur V);

/* affiche un point */
void print_point(Point P);

/* calcul la distance d'un point avec un segment */
double distance_point_segment(Point P, Point A, Point B);

/* cree une courbe de bezier2 */
Bezier2 cree_bezier2 (Point c0, Point c1, Point c2);

/* cree une courbe de bezier3 */
Bezier3 cree_bezier3 (Point c0, Point c1, Point c2, Point c3);

/* calcul la valeur de c(t) pour t entre [0,1] pour une bezier de degres 2 */
Point calcul_point_bezier_2(Bezier2 C , double t);

/* calcul la valeur de c(t) pour t entre [0,1] pour une bezier de degres 3 */
Point calcul_point_bezier_3(Bezier3 C, double t);

/* conversion bezier2 en bezier3 */
Bezier3 conversion_bezier2_in_bezier3 (Bezier2 C);

/* calcul de la distance entre deux points*/
double distance_point_point ( Point Pa, Point Pb);

/*  calcul de la ditance point courbe de bezier 2*/
double distance_point_courbe( Point Pj,Bezier2 B ,double ti);

double distance_point_courbe_b3(Point Pj,Bezier3 B ,double ti);

#endif /* _GEOM2D_H_ */
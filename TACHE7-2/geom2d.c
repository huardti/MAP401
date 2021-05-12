#include <math.h>
#include <stdio.h>

#include "geom2d.h"

/* cree le point de coordonnÃ©es x,y */
Point set_point(double x , double y){
	Point P = {x,y};
	return P;
}

/* somme P1 + P2 */
Point add_point(Point P1 , Point P2){
	return set_point(P1.x + P2.x , P1.y + P2.y);
}
Point sub_point(Point P1 , Point P2){
	return set_point(P1.x - P2.x , P1.y - P2.y);
}
Point mult_point(Point P1, double l){
	return set_point(P1.x * l , P1.y * l);
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

double distance_point_segment(Point P, Point A, Point B){
	if (A.x == B.x && A.y == B.y){
		return norme_vecteur(vect_bipoint(A , P));
	}
	else {
		Vecteur AP = vect_bipoint(A,P);
		Vecteur AB = vect_bipoint(A, B);

		double lambda = p_scalaire_vecteur(AP, AB)/p_scalaire_vecteur(AB,AB);

		if (lambda < 0){
			return norme_vecteur(vect_bipoint(A , P));
		}
		else if (lambda > 1){
			return norme_vecteur(vect_bipoint(B , P));
		}
		else{
			Point Q = add_point(A , mult_point((sub_point(B, A)), lambda));
			return norme_vecteur(vect_bipoint(Q, P));
		}
	}
}

/* cree une courbe de bezier2 */
Bezier2 cree_bezier2 (Point c0, Point c1, Point c2){
	Bezier2 C;
	C.C0 = c0;
	C.C1 = c1;
	C.C2 = c2;

	return C;

}

/* cree une courbe de bezier3 */
Bezier3 cree_bezier3 (Point c0, Point c1, Point c2, Point c3){
	Bezier3 C;
	C.C0 = c0;
	C.C1 = c1;
	C.C2 = c2;
	C.C3 = c3;

	return C;
}


Point calcul_point_bezier_2(Bezier2 C , double t){
	Point retour;
	retour.x = C.C0.x*pow((1-t),2) + C.C1.x*2*t*(1-t) + C.C2.x*pow(t,2);
	retour.y = C.C0.y*pow((1-t),2) + C.C1.y*2*t*(1- t) + C.C2.y*pow(t,2);
	return retour;
}


Point calcul_point_bezier_3(Bezier3 C, double t){
	Point retour;
	retour.x = C.C0.x*pow((1-t),3) + C.C1.x*3*t*pow((1-t), 2) + C.C2.x*3*pow(t,2)*(1-t) + C.C3.x*pow(t,3);
	retour.y = C.C0.y*pow((1-t),3) + C.C1.y*3*t*pow((1-t), 2) + C.C2.y*3*pow(t,2)*(1-t) + C.C3.y*pow(t,3);
	return retour;
}

Bezier3 conversion_bezier2_in_bezier3 (Bezier2 C){
    Bezier3 C3;
    C3.C0 = C.C0;
    C3.C1.x = (C.C0.x + 2*C.C1.x) / 3;
    C3.C1.y = (C.C0.y + 2*C.C1.y) / 3;

    C3.C2.x = (2*C.C1.x + C.C2.x) / 3;
    C3.C2.y = (2*C.C1.y + C.C2.y) / 3;
    C3.C3 = C.C2;
    return C3;
}

double distance_point_point ( Point Pa, Point Pb){
    Vecteur V;
    V = vect_bipoint(Pa,Pb);
    return norme_vecteur(V);
}

double distance_point_courbe(Point Pj,Bezier2 B ,double ti){
    Point P;
    P = calcul_point_bezier_2(B, ti);
    return distance_point_point (Pj,P);
}
double distance_point_courbe_b3(Point Pj,Bezier3 B ,double ti){
    Point P;
    P = calcul_point_bezier_3(B, ti);
    return distance_point_point (Pj,P);
}

Point div_point(Point pa, double r){
    pa.x = pa.x/r;
    pa.y = pa.y/r;
    return pa;
}

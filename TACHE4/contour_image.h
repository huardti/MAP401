#ifndef _CONTOUR_IMAGE_H_
#define _CONTOUR_IMAGE_H_

#include "image.h"
#include "tab_variable.h"



typedef enum {NORD, EST, SUD, OUEST} Orientation;

typedef struct robot_{
  Orientation o;
  double x,y;
  }Robot;

/*cr�e et intialise un robot*/
Robot intitialiser_robot(double x,double y,Orientation o);

/* Fonction de recherche du pixel de d�part */
void trouver_pixel_depart(double *x,double *y, Image I); 

/*Fonction du deplacement du robot*/
void avancer(Robot *r);

/* Tourne le robot a droite */
void tourner_a_droite(Robot *r);

/* Tourne le robot a gauche */
void tourner_a_gauche(Robot *r);

/*change l'orientation du robot */
void nouvelle_orientation(Robot *r, Image I);

/*Ecrit a l'ecran les positions successive du robot a stocker aussi en memoire */
void print_position(Robot r);

/* retourne les pixels avant gauche et avant droite du robot */
void pixel_devant_robot(Robot r, Image I, Pixel *a_g, Pixel *a_d);

#endif /* _CONTOUR_IMAGE_H_ */
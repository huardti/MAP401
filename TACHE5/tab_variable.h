#ifndef _TAB_VARIABLE_H
#define _TAB_VARIABLE_H
#include "geom2d.h"
#include <stdio.h>
#include <string.h>

typedef struct tab_points_ {
    Point *t;
    int taille;
}tab_points;

typedef struct tab_contour_ {
    int taille;
    tab_points *t;
}tab_contour;

void init_tab(tab_points *a);
void add_cell_tab(tab_points *a , Point p);
int taille_tab(tab_points t);
void suppr_tab(tab_points *a);


void init_tab_contour(tab_contour *a);
void add_cell_tab_contour(tab_contour *a , tab_points p);
int taille_tab_contour(tab_contour t);
void suppr_tab_contour(tab_contour *a);

void save_tab_contour_fichier(char *file_name , tab_contour contour);


#endif // _TAB_VARIABLE_H
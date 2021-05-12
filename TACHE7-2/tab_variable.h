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


typedef struct tab_bezier2_ {
    int taille;
    Bezier2 *t;
}tab_bezier2;
typedef struct tab_contour_bezier2_ {
    int taille;
    tab_bezier2 *t;
}tab_contour_bezier2;


typedef struct tab_bezier3_ {
    int taille;
    Bezier3 *t;
}tab_bezier3;
typedef struct tab_contour_bezier3_ {
    int taille;
    tab_bezier3 *t;
}tab_contour_bezier3;

/*============= TAB_POINT ====================*/
void init_tab(tab_points *a);
void add_cell_tab(tab_points *a , Point p);
int taille_tab(tab_points t);
tab_points cat_tab(tab_points a, tab_points b);
void suppr_tab(tab_points *a);

/*============= TAB_contour ====================*/
void init_tab_contour(tab_contour *a);
void add_cell_tab_contour(tab_contour *a , tab_points p);
int taille_tab_contour(tab_contour t);
void suppr_tab_contour(tab_contour *a);
void save_tab_contour_fichier(char *file_name , tab_contour contour);

/*============= TAB_BEZIER2 + TAB_CONTOUR_BEZIER_2 ============ */
void init_tab_bezier2(tab_bezier2 *a);
void add_cell_tab_bezier2(tab_bezier2 *a , Bezier2 p);
int taille_tab_bezier2(tab_bezier2 t);
tab_bezier2 cat_tab_bezier2(tab_bezier2 a, tab_bezier2 b);
void suppr_tab_bezier2(tab_bezier2 *a);

void init_tab_contour_bezier2(tab_contour_bezier2 *a);
void add_cell_tab_contour_bezier2(tab_contour_bezier2 *a , tab_bezier2 p);
int taille_tab_contour_bezier2(tab_contour_bezier2 t);
void suppr_tab_contour_bezier2(tab_contour_bezier2 *a);

/*============= TAB_BEZIER3 + TAB_CONTOUR_BEZIER_3 ============ */
void init_tab_bezier3(tab_bezier3 *a);
void add_cell_tab_bezier3(tab_bezier3 *a , Bezier3 p);
int taille_tab_bezier3(tab_bezier3 t);
tab_bezier3 cat_tab_bezier3(tab_bezier3 a, tab_bezier3 b);
void suppr_tab_bezier3(tab_bezier3 *a);

void init_tab_contour_bezier3(tab_contour_bezier3 *a);
void add_cell_tab_contour_bezier3(tab_contour_bezier3 *a , tab_bezier3 p);
int taille_tab_contour_bezier3(tab_contour_bezier3 t);
void suppr_tab_contour_bezier3(tab_contour_bezier3 *a);


#endif // _TAB_VARIABLE_H
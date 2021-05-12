#ifndef _TAB_VARIABLE_H
#define _TAB_VARIABLE_H
#include "geom2d.h"

typedef struct tab_ {
    Point *t;
    int taille;
}tab;

void init_tab(tab *a);

void add_cell_tab(tab *a , Point p);
int taille_tab(tab t);

void suppr_tab(tab *a);


#endif // _TAB_VARIABLE_H
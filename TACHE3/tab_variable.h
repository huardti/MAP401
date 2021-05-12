#ifndef _TAB_VARIABLE_H
#define _TAB_VARIABLE_H
#include "geom2d.h"

typedef struct tab_ {
    Point *t;
    int taille;
}tab;

/* cree un tableau */
void init_tab(tab *a);

/*ajoute une cellule dans le tableau */
void add_cell_tab(tab *a , Point p);

/* retourne la taille du tableau */
int taille_tab(tab t);

/* supprime le tableau */
void suppr_tab(tab *a);


#endif // _TAB_VARIABLE_H
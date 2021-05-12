#include "tab_variable.h"

#include <malloc.h>

void init_tab(tab *a){
    a->taille = 0;
    a->t = NULL;
}

void add_cell_tab(tab *a , Point p){
    a->t = realloc(a->t, sizeof(Point)*(a->taille+1));
    a->t[a->taille] = p;
    a->taille++;
}

int taille_tab(tab t){
    return t.taille;
}

void suppr_tab(tab *a){
  free(a);
}
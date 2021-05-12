#include "tab_variable.h"

#include <malloc.h>
#include <assert.h>

void init_tab(tab_points *a){
    a->taille = 0;
    a->t = NULL;
}
void add_cell_tab(tab_points *a , Point p){
    a->t = realloc(a->t, sizeof(Point)*(a->taille+1));
    a->t[a->taille] = p;
    a->taille++;
}
int taille_tab(tab_points t){
    return t.taille;
}
tab_points cat_tab(tab_points a, tab_points b){
    tab_points out;
    out.taille = a.taille + b.taille;
    out.t = malloc(sizeof(Point)*(out.taille));
    int i = 0;
    for ( i ; i < a.taille; i++) {
        out.t[i] = a.t[i];
    }
    for (int j = 0; j < b.taille; j++) {
        out.t[i] = b.t[j];
        i++;
    }
    return out;
}

void suppr_tab(tab_points *a){
  free(a->t);
  a->taille = 0;
}


void init_tab_contour(tab_contour *a){
    a->taille = 0;
    a->t = NULL;
}
void add_cell_tab_contour(tab_contour *a , tab_points p){
    a->t = realloc(a->t, sizeof(tab_points)*(a->taille+1));
    a->t[a->taille] = p;
    a->taille++;
}

int taille_tab_contour(tab_contour t){
    return t.taille;
}

void suppr_tab_contour(tab_contour *a){
  free(a->t);
}

void save_tab_contour_fichier(char *file_name , tab_contour contour){
    FILE *f = NULL;
    f = fopen("out.contour.txt", "w");

    assert(f != NULL);

    fprintf(f , "%d\n" , contour.taille);
    for (int i = 0; i < contour.taille; i++) {
        fprintf(f, "\n%d\n" , contour.t[i].taille);
        for (int j = 0; j < contour.t[i].taille; j++) {
            fprintf(f, "%.1f %.1f\n", contour.t[i].t[j].x , contour.t[i].t[j].y);
        }
    }

    fclose(f);
}
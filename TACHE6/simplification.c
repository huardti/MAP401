#include "simplification.h"

void ajout_segment(tab_points *L , Point p1, Point p2){
    if (L->taille == 0){
        add_cell_tab(L, p1);
        if( !( (L->t[L->taille-1].x == p2.x ) && (L->t[L->taille-1].y == p2.y) ) ){
            add_cell_tab(L, p2);
        }
    }
    else{
        add_cell_tab(L, p2);
    }
}

tab_points simplification_douglas_peucker(tab_points C, int j1 ,int j2, double d){
    double dj;
    tab_points L, L1, L2;
    init_tab(&L);
    init_tab(&L1);
    init_tab(&L2);
    
    double dmax = 0;
    int k = j1;
    for (int j = j1+1; j < j2; j++) {
        dj = distance_point_segment(C.t[j], C.t[j1], C.t[j2]);
        if (dmax < dj){
            dmax = dj;
            k = j;
        }
    }

    if (dmax <= d){

        ajout_segment(&L, C.t[j1], C.t[j2]);
    }
    else{
        L1 = simplification_douglas_peucker(C,j1,k,d);
        L2 = simplification_douglas_peucker(C,k,j2,d);

        //suppr_tab(&L1);
        //suppr_tab(&L2);

        L = cat_tab(L1,L2);
    }
    return L;
}

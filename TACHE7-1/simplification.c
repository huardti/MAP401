#include "simplification.h"

#include <math.h>
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

Point somme_points_bezier2(tab_points C, int n, int j1, int j2){
    Point P1 = {0, 0};
    for(int i = 1; i<=n-1; i++){
        P1.x = P1.x + C.t[i + j1].x;
        P1.y = P1.y + C.t[i + j1].y;
        
    }
    return P1;
}

Bezier2 approx_bezier(tab_points CONT, int j1, int j2){
    Point C0 = CONT.t[j1];
    Point C2 = CONT.t[j2];
    Point C1;
    Point P1;

    Bezier2 B;
    int n = j2-j1;
    double nr = (double)n;
    double alpha = (3*nr) / (nr*nr - 1);
    double beta = (1 - 2*nr) / (2*nr + 2);
    
    //Cas 1) cas simple
    if (n == 1){
        C1.x = (C0.x + C2.x)/2;
        C1.y = (C0.y + C2.y)/2;

        B.C0 = C0;
        B.C1 = C1;
        B.C2 = C2;
    }
    //Cas 2
    else{
          P1 = somme_points_bezier2(CONT,n,j1,j2);
          C1.x = alpha*P1.x + beta*(C0.x + C2.x);
          C1.y = alpha*P1.y + beta*(C0.y + C2.y);
          B.C0 = C0;
          B.C1 = C1;
          B.C2 = C2;
    }
    return B;
}

tab_bezier2 simplification_douglas_peucker_2(tab_points CONT, int j1 ,int j2, double d){
    double dj = 0;
    double ti = 0;
    int i = 0;
    int k = 0;
    int n = j2 - j1;
    Bezier2 B;
    
    tab_bezier2 L, L1, L2;
    init_tab_bezier2(&L);
    init_tab_bezier2(&L1);
    init_tab_bezier2(&L2);
    
    B = approx_bezier(CONT,j1,j2);

    double dmax = 0;
    k = j1;
    for (int j = j1+1; j < j2; j++) {
        i = j - j1;
        ti = (double)i / (double)n;
        dj = distance_point_courbe(CONT.t[j],B,ti);
        if (dmax < dj){
            dmax = dj;
            k = j;
        }
    }

    if (dmax <= d){

        add_cell_tab_bezier2(&L, B);
    }
    else{
        L1 = simplification_douglas_peucker_2(CONT,j1,k,d);
        L2 = simplification_douglas_peucker_2(CONT,k,j2,d);

        L = cat_tab_bezier2(L1, L2);
        
        free(L1.t);
        free(L2.t);
    }
    return L;
}


        

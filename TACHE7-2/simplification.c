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

Bezier2 approx_bezier(tab_points CONT, int j1, int j2){
    Point C0 = CONT.t[j1];
    Point C2 = CONT.t[j2];

    Point C1;
    Point C11;
    Point C12 =  set_point(0,0);

    Bezier2 B;

    double wi;
    double Swi = 0;
    int n = j2-j1;
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
        for (int i=1 ;i <= n-1; i++){
            double i_n = (double)i/(double)n;
            wi = (double)2.0*i_n *(1.0-(i_n));
           
            C11.x = (CONT.t[i].x - pow((1.0 - ((double)i/(double)n)),2)*C0.x - pow(((double)i/(double)n),2)*C2.x) / wi;
            C11.y = (CONT.t[i].y - pow((1.0 - ((double)i/(double)n)),2)*C0.y - pow(((double)i/(double)n),2)*C2.y) / wi;
            Swi = Swi + wi;
            C12.x = C12.x + C11.x * wi;
            C12.y = C12.y + C11.y * wi;
        }
        C1.x = C12.x / Swi;
        C1.y = C12.y / Swi;
        B.C0 = C0;
        B.C1 = C1;
        B.C2 = C2;
    }
    return B;
}

tab_bezier2 simplification_douglas_peucker_2(tab_points CONT, int j1 ,int j2, double d){
    double dj;
    double ti;
    int i;
    int k;
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
    }
    return L;
}


double gam(double k, double nr) {
    return 6*k*k*k*k - 8*nr*k*k*k + 6*k*k - 4*nr*k + nr*nr*nr*nr -nr*nr;
}

Point somme_point_gamma_C1(tab_points CONT, int i0, int n) {
    Point P = {0, 0};
    for (size_t i = 1; i < n; i++) {
        P = add_point(P, mult_point(CONT.t[i0 + i], gam((double)i, (double)n)));
    }
    return P;
}

Point somme_point_gamma_C2(tab_points CONT, int i0, int n) {
    Point P = {0, 0};
    for ( size_t i = 1; i < n; i++) {
        P = add_point(P, mult_point(CONT.t[i0 + i], gam((double)n-i, (double)n)));
    }
    return P;
}



Bezier3 approx_bezier_3(tab_points CONT, int j1, int j2){
    int n = j2 - j1;
    Bezier3 B;

    if (n < 3) {
        Bezier2 B2 = approx_bezier(CONT, j1, j2);
        B = conversion_bezier2_in_bezier3(B2);
    } else {
        double nr = (double)n;
        double alpha = ((-15)*nr*nr*nr + 5*nr*nr + 2*nr + 4) / (3*(nr+2)*(3*nr*nr+1));
        double beta = (10*nr*nr*nr - 15*nr*nr + nr + 2) / (3*(nr+2)*(3*nr*nr+1));
        double lambda = (70*nr) / (3*(nr*nr-1)*(nr*nr-4)*(3*nr*nr+1));

        B.C0 = CONT.t[j1];
        B.C3 = CONT.t[j2];

        B.C1 = add_point(
               add_point(
                mult_point(CONT.t[j1], alpha),
                mult_point(somme_point_gamma_C1(CONT, j1, n), lambda)),
                mult_point(CONT.t[j2], beta));

        B.C2 = add_point(
               add_point(
                mult_point(CONT.t[j1], beta),
                mult_point(somme_point_gamma_C2(CONT, j1, n), lambda)),
                mult_point(CONT.t[j2], alpha));

    }
    return B;
}

tab_bezier3 simplification_douglas_peucker_3(tab_points CONT, int j1 ,int j2, double d){
    double dj;
    double ti;
    int i;
    int k;
    int n = j2 - j1;
    Bezier3 B;
    
    tab_bezier3 L, L1, L2;
    init_tab_bezier3(&L);
    init_tab_bezier3(&L1);
    init_tab_bezier3(&L2);
    
    B = approx_bezier_3(CONT,j1,j2);

    double dmax = 0;
    k = j1;
    for (int j = j1+1; j < j2; j++) {
        i = j - j1;
        ti = (double)i / (double)n;
        dj = distance_point_courbe_b3(CONT.t[j],B,ti);
        if (dmax < dj){
            dmax = dj;
            k = j;
        }
    }

    if (dmax <= d){

        add_cell_tab_bezier3(&L, B);
    }
    else{
        L1 = simplification_douglas_peucker_3(CONT,j1,k,d);
        L2 = simplification_douglas_peucker_3(CONT,k,j2,d);

        L = cat_tab_bezier3(L1, L2);
    }
    return L;
}


        

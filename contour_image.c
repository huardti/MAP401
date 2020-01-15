#include <stdio.h>
#include "contour_image.h"
#include "types_macros.h"

Robot intitialiser_robot(double x,double y, Orientation o){
    Robot r;
    r.x = x;
    r.y = y;
    r.o = o;
    return r;
}


void trouver_pixel_depart(double *x,double *y , Image I){
    UINT H,L;
    H = hauteur_image(I);
    L = largeur_image(I);

    for (UINT i = 1; i < H; i++) {
        for (UINT j = 1; j < L; j++) {
            if (get_pixel_image(I,j,i) == NOIR && get_pixel_image(I,j,i-1) == BLANC){
                *x = (double) j;
                *y = (double) i;
                return;
            }
        }
    }

    printf("auccun pixel noir avec un blanc au nord n'a ete trouve");
}


void avancer(Robot *r){
    switch (r->o)
    {
    case NORD:
        r->y--;
        break;
    case OUEST:
        r->x--;
        break;
    case SUD:
        r->y++;
        break;
    case EST:
        r->x++;
        break;
    default:
        ERREUR_FATALE("Probleme sur l'orientation")
        break;
    }
}


void tourner_a_droite(Robot *r){
    if (r->o == 3){
        r->o = 0;
    }else{
        r->o++;
    }
}


void tourner_a_gauche(Robot *r){
    if (r->o == 0){
        r->o = 3;
    }else{
        r->o--;
    }
}


void nouvelle_orientation(Robot *r, Image I){
    Pixel a_g, a_d;
    pixel_devant_robot(*r, I, &a_g, &a_d);
    
    if (a_g == BLANC && a_d == BLANC){
        tourner_a_droite(r);
        return;
    }else if (a_g == BLANC && a_d == NOIR){
        return;
    }else if (a_g == NOIR && a_d == BLANC){
        tourner_a_gauche(r);
        return;
    }else if (a_g == NOIR && a_d == NOIR){
        tourner_a_gauche(r);
        return;
    }
}


void memoriser_position(Robot r){
    printf("%.1f  %.1f\n", r.x , r.y);
}

void pixel_devant_robot(Robot r, Image I, Pixel *a_g, Pixel *a_d){
    switch (r.o){
        case NORD:
            *a_g = get_pixel_image(I, r.x, r.y);
            *a_d = get_pixel_image(I, r.x+1, r.y);
            break;
        case SUD:
            *a_g = get_pixel_image(I, r.x+1, r.y+1);
            *a_d = get_pixel_image(I, r.x, r.y+1);
            break;
        case OUEST:
            *a_g = get_pixel_image(I, r.x, r.y+1);
            *a_d = get_pixel_image(I, r.x, r.y);
            break;
        case EST:
            *a_g = get_pixel_image(I, r.x+1, r.y);
            *a_d = get_pixel_image(I, r.x+1, r.y+1);
            break;
        
    default:
        break;
    }
}
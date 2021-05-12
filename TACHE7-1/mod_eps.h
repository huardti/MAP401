#ifndef _MOD_EPS_H_
#define _MOD_EPS_H_

#include <stdio.h>
#include "geom2d.h"
#include "tab_variable.h"

void entete_eps(FILE *f, int x , int y);

void move_to_eps(FILE *f,Point p , int taille_y);

void line_to_eps(FILE *f,Point p , int taille_y);

void trace_bezier3(FILE *f, Bezier3 b, int taille_y);

void color_width_eps(FILE *f, int r ,int g, int b , int width);

void move_to_bezier3(FILE *f, Bezier3 b, int taille_y);

void end_eps(FILE *f);

#endif //_MOD_EPS_H_
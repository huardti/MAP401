#include "mod_eps.h"

void entete_eps(FILE *f, int x , int y){
  char a = '%';
  fprintf(f, "%c!PS-Adobe-3.0 EPSF-3.0\n", a);
  fprintf(f, "%c%cBoundingBox: 0 0 %d %d\n",a,a, x ,y );
}

void move_to_eps(FILE *f,Point p, int taille_y){
  fprintf(f, "\n%.0f %.0f moveto " , p.x , taille_y - p.y);
}

void line_to_eps(FILE *f,Point p, int taille_y){
  fprintf(f, "%.0f %.0f lineto " , p.x , taille_y - p.y);
}

void end_eps(FILE *f){
  fprintf(f, "\n");
  fprintf(f, "fill\n\n");
  fprintf(f, "showpage");
}
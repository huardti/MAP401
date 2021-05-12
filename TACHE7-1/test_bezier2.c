#include <stdio.h>
#include "geom2d.h"
#include "tab_variable.h"
#include "simplification.h"


int main(){
  Point P0 = set_point(0.0,0.0);
  Point P1 = set_point(1.0,0.0);
  Point P2 = set_point(1.0,1.0);
  Point P3 = set_point(1.0,2.0);
  Point P4 = set_point(2.0,2.0);
  Point P5 = set_point(3.0,2.0);
  Point P6 = set_point(3.0,3.0);
  Point P7 = set_point(4.0,3.0);
  Point P8 = set_point(5.0,3.0);
  
	tab_points CONT;
  init_tab(&CONT);
  add_cell_tab(&CONT , P0);
  add_cell_tab(&CONT , P1);
  add_cell_tab(&CONT , P2);
  add_cell_tab(&CONT , P3);
  add_cell_tab(&CONT , P4); 
  add_cell_tab(&CONT , P5);
  add_cell_tab(&CONT , P6);
  add_cell_tab(&CONT , P7);
  add_cell_tab(&CONT , P8);
  
  int j1=0;
  int j2=8;
  int n = j2-j1;
  
  Bezier2 B;
  B = approx_bezier(CONT,j1,j2);
  double dj ;
  dj = distance_point_courbe(P2,B, 2.0/(double)n);
  printf("valeur de dj : %f\n",dj);
  printf("valeur de C1 : ");
  printf("%f ; %f ",B.C1.x,B.C1.y);


return 0;
}
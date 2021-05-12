#include <stdio.h>
#include "geom2d.h"
#include "tab_variable.h"

int main(){
	Point C0,C1,C2,Ptest;
  double d;
  Ptest = set_point(1,2);
	C0 = set_point(0,0);
	C1 = set_point(1,1);
	C2 = set_point(0,2);

	Bezier2 c;
	c = cree_bezier2(C0 ,C1, C2);
  d = distance_point_courbe(Ptest,c,0.5);
  printf("la distance point courbe : %f \n",d);
  
	print_point(calcul_point_bezier_2(c, 0.5));
	printf("\n");
	printf("\n");

	Bezier3 c2;

	c2 = conversion_bezier2_in_bezier3(c);

	print_point(c2.C0);
	print_point(c2.C1);
	print_point(c2.C2);
	print_point(c2.C3);

	printf("\n");

	print_point(calcul_point_bezier_3(c2, 0.5));

return 0;
}

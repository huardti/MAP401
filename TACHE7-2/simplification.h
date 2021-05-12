#include "geom2d.h"
#include "tab_variable.h"

tab_points simplification_douglas_peucker(tab_points C, int j1 ,int j2, double d);

Bezier2 approx_bezier(tab_points CONT, int j1, int j2);
Bezier3 approx_bezier_3(tab_points CONT, int j1, int j2);

tab_bezier2 simplification_douglas_peucker_2(tab_points CONT, int j1 ,int j2, double d);

tab_bezier3 simplification_douglas_peucker_3(tab_points CONT, int j1 ,int j2, double d);
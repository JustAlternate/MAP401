#ifndef _SIMPLIFICATION_BEZIER2_H_
#define _SIMPLIFICATION_BEZIER2_H_

#include "geometrie.h"
#include "bezier.h"

// Permet de transformer un segment en courbe de bezier 2, puisque nous utilisons des liste chainées, on donne la cellule qui correspond au premier point du segment et au dernier, ainsi que le nombre de points pour l'optimisation.
Bezier2 approx_bezier2(Cellule_Point* depart, Cellule_Point* fin, int nombre_cellule);

Contour simplification_douglas_peucker_Bezier2(Cellule_Point* Pj1, Cellule_Point* Pj2, int d);
Contour enrobage_douglas_Bezier2(Contour Cont, int d);


#endif

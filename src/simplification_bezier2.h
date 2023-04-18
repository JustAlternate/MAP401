#ifndef _SIMPLIFICATION_CONTOUR_H_
#define _SIMPLIFICATION_CONTOUR_H_

#include "geometrie.h"
#include "contour.h"
#include "bezier.h"

// Permet de transformer un segment en courbe de bezier 2, puisque nous utilisons des liste chainées, on donne la cellule qui correspond au premier point du segment et au dernier, ainsi que le nombre de points pour l'optimisation.
Bezier2 approx_bezier2(Cellule_Point* depart, Cellule_Point* fin, int nombre_cellule);



#endif

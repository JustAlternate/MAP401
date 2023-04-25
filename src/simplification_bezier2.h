#ifndef _SIMPLIFICATION_BEZIER2_H_
#define _SIMPLIFICATION_BEZIER2_H_

#include "geometrie.h"
#include "sequence_bezier2.h"
#include "sequence_point.h"
#include "bezier.h"

// Permet de transformer un segment en courbe de bezier 2, puisque nous utilisons des liste chainées, on donne la cellule qui correspond au premier point du segment et au dernier, ainsi que le nombre de points pour l'optimisation.
Bezier2 approx_bezier2(Cellule_Point* depart, Cellule_Point* fin, int nombre_cellule);

Motif_Bezier2 simplification_douglas_peucker_Bezier2(Cellule_Point* Pj1, Cellule_Point* Pj2, double d, int nb_elem);
Dessin_Bezier2 *simplification_Bezier2(Liste_Contour *LCont, float d);

#endif

#ifndef _SIMPLIFICATION_CONTOUR_H_
#define _SIMPLIFICATION_CONTOUR_H_

#include "geometrie.h"
#include "contour.h"

Contour simplification_douglas_peucker(Cellule_Point* Pj1, Cellule_Point* Pj2, double d);
Contour enrobage_douglas(Contour Cont,double d);
Liste_Contour *simplification_segment(Liste_Contour *LCont, double d);

#endif

#ifndef _SIMPLIFICATION_CONTOUR_H_
#define _SIMPLIFICATION_CONTOUR_H_

#include "geometrie.h"
#include "contour.h"

Contour simplification_douglas_peucker(Cellule_Point* Pj1, Cellule_Point* Pj2, int d);
Contour enrobage_douglas(Contour Cont, int d);

#endif

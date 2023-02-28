/****************************************************************************** 
  Interface du module image
******************************************************************************/

#ifndef _CONTOUR_H_
#define _CONTOUR_H_

#include "image.h"
#include "geometrie.h"
#include "sequence_point.h"

typedef enum {Nord,Sud,Ouest,Est} Orientation;

Point trouver_pixel_depart(Image I);

Point avancer(Point pos, Orientation ori);
Orientation nouvelle_orientation(Point pos, Orientation ori, Image I);
Contour recherche_contour(Point depart, Image I);
Liste_Contour tout_les_contour(Image I);
Liste_Contour* recherche_tous_les_contours(Image img);

#endif /* _CONTOUR_H_ */

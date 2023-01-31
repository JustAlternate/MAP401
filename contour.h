/****************************************************************************** 
  Interface du module image
******************************************************************************/

#ifndef _CONTOUR_H_
#define _CONTOUR_H_

typedef enum {Nord,Sud,Ouest,Est} Orientation;

Point trouver_pixel_depart(Image I);

Point avancer(Point pos, Orientation ori);
Orientation nouvelle_orientation(Point pos, Orientation ori, Image I);
Contour recherche_contour(Point depart, Image I);

#endif /* _CONTOUR_H_ */

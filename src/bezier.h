/****************************************************************************** 
  implementation module geometrie 2D
******************************************************************************/

#ifndef _BEZIER_H_
#define _BEZIER_H_

#include "sequence_point.h"

//////////////////////////////////////////////////
//                  Beziers                    //
//////////////////////////////////////////////////

typedef struct {
	Point C0;
	Point C1;
	Point C2;
} Bezier2;

typedef struct {
	Point C0;
	Point C1;
	Point C2;
	Point C3;
} Bezier3;

// Permet de rapidement créer une structure Bezier avec les points.
Bezier2 init_bezier2(Point C0, Point C1, Point C2);
Bezier3 init_bezier3(Point C0, Point C1, Point C2, Point C3);

// Permet de transformer un segment en courbe de bezier 2, puisque nous utilisons des liste chainées, on donne la cellule qui correspond au premier point du segment et au dernier, ainsi que le nombre de points pour l'optimisation.
Bezier2 approx_bezier2(Cellule_Point* depart, Cellule_Point* fin, int nombre_cellule);

// Calcul de la distance entre le point et la courbe (ti represente le numéro du point / nombre total de points du contour simplifiée)
double distance_point_courbe_bezier2(Point C, Bezier2 bez, double ti);

// Prend un bezier2 et renvoie un bezier3 grace a la transformation de l'elevation de degrée.
Bezier3 elevation_de_deg_bezier(Bezier2 bez);

// Applique la fonction, avec x un point entre 0 et 1.
Point applique_bezier2_point(Bezier2 bez, double x);

// Applique la fonction, avec x un point entre 0 et 1.
Point applique_bezier3_point(Bezier3 bez, double x);


#endif

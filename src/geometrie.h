/****************************************************************************** 
  implementation module geometrie 2D
******************************************************************************/

#ifndef _GEOMETRIE_H_
#define _GEOMETRIE_H_

#include "contour.h"


typedef struct {
    double x;
    double y;
} Vecteur;

typedef struct {
    double x;
    double y;
} Point;

//////////////////////////////////////////////////
//                Initialisation                //
//////////////////////////////////////////////////
// crée un nouveau vecteur de coordonée (x,y):  V(x,y)
Vecteur nouveau_vecteur(double x, double y);
// crée un nouveau point de coordonée (x,y):  P(x,y)
Point nouveau_point(double x, double y);
//////////////////////////////////////////////////
//                  Conversion                  //
//////////////////////////////////////////////////

//convertie le point P(x,y) en le vecteur V(x,y)
Vecteur point_to_vecteur(Point p);

//convertie le vecteur V(x,y) en le point P(x,y)
Point vecteur_to_point(Vecteur v);

//crée le vecteur allant du point p1 au point p2
Vecteur couple_point_to_vecteur(Point p1, Point p2);

//////////////////////////////////////////////////
//                  Operations                  //
//////////////////////////////////////////////////
//vecteurs
//renvoie v1+v2
Vecteur addition_vecteur(Vecteur v1, Vecteur v2);

//renvoie λ*v
Vecteur produit_vecteur(double λ, Vecteur v);

//renvoie le produit scalaire de v1 et v2
double produit_scalaire(Vecteur v1, Vecteur v2);

//renvoie la norme de v aussi notée |v|
double norme(Vecteur v);
// point
// renvoie p1+p2
Point addition_point(Point p1, Point p2);
// renvoie λ*p
Point produit_point(double λ, Point p);
//renvoie la distance en =tre le point p1 et p2
double distance_point(Point p1, Point p2);
//renvoie la distance point segment entre P, A et B
double distance_point_segment(Point P, Point A, Point B);

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
Bezier2 contour_vers_bezier2(Cellule_Point depart, Cellule_Point fin, int nombre_cellule);

// Calcul de la distance entre le point et la courbe (ti represente le numéro du point / nombre total de points du contour simplifiée)
double distance_point_courbe_bezier2(Point C, Bezier2 bez, double ti);

// Prend un bezier2 et renvoie un bezier3 grace a la transformation de l'elevation de degrée.
Bezier3 elevation_de_deg_bezier(Bezier2 bez);

// Applique la fonction, avec x un point entre 0 et 1.
Point applique_bezier2_point(Bezier2 bez, double x);


Point applique_bezier3_point(Bezier3 bez, double x);












#endif








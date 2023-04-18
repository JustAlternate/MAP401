/****************************************************************************** 
  implementation module geometrie 2D
******************************************************************************/

#ifndef _GEOMETRIE_H_
#define _GEOMETRIE_H_


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




#endif








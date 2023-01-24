/****************************************************************************** 
  implementation module geometrie 2D
******************************************************************************/

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
#include<math.h>
#include"types_macros.h"
#include"geometrie.h"


//////////////////////////////////////////////////
//                Initialisation                //
//////////////////////////////////////////////////

//crée un nouveau vecteur de coordonée (x,y):  V(x,y)
Vecteur nouveau_vecteur(double x,double y){
    Vecteur v;
    v.x = x;
    v.y = y;
    return v;
}
//crée un nouveau point de coordonée (x,y):  P(x,y)
Point nouveau_point(double x,double y){
    Point p;
    p.x = x;
    p.y = y;
    return p;
}
//////////////////////////////////////////////////
//                  Conversion                  //
//////////////////////////////////////////////////

//convertie le point P(x,y) en le vecteur V(x,y)
Vecteur point_to_vecteur(Point p){
    return nouveau_vecteur(p.x, p.y);
}

//convertie le vecteur V(x,y) en le point P(x,y)
Point vecteur_to_point(Vecteur v){
    return nouveau_point(v.x, v.y);
}

//crée le vecteur allant du point p1 au point p2
Vecteur couple_point_to_vecteur(Point p1, Point p2){
    return nouveau_vecteur(p2.x - p1.x, p2.y - p1.y);
}

//////////////////////////////////////////////////
//                  Operations                  //
//////////////////////////////////////////////////
//vecteurs
//renvoie v1+v2
Vecteur addition_vecteur(Vecteur v1, Vecteur v2){
    return nouveau_vecteur(v1.x + v2.x, v1.y + v2.y);
}

//renvoie λ*v
Vecteur produit_vecteur(double λ, Vecteur v){
    return nouveau_vecteur(λ * v.x, λ * v.y);
}

//renvoie le produit scalaire de v1 et v2
double produit_scalaire(Vecteur v1, Vecteur v2){
    return v1.x * v2.x + v1.y * v2.y;
}

//renvoie la norme de v aussi notée |v|
double norme(Vecteur v){
    sqrt(produit_scalaire(v, v));
}
//point
//renvoie p1+p2
Point addition_Point(Point p1, Point p2){
    return nouveau_point(p1.x + p2.x, p1.y + p2.y);
}
//renvoie λ*p
Point produit_point(double λ, Point p){
    return nouveau_point(λ * p.x, λ * p.y);
}
double distance_points(Point p1, Point p2){
    
}
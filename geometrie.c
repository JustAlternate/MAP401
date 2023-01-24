/****************************************************************************** 
  implementation module geometrie 2D
******************************************************************************/

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
#include"types_macros.h"
#include"geometrie.h"


//////////////////////////////////////////////////
//                Initialisation                //
//////////////////////////////////////////////////

Vecteur nouveau_vecteur(double x,double y){
    Vecteur v;
    v.x = x;
    v.y = y;
    return v;
}
Point nouveau_point(double x,double y){
    Point p;
    p.x = x;
    p.y = y;
    return p;
}
//////////////////////////////////////////////////
//                  Conversion                  //
//////////////////////////////////////////////////

Vecteur point_to_vecteur(Point p){
    return nouveau_vecteur(p.x, p.y);
}

Point vecteur_to_point(Vecteur v){
    return nouveau_point(v.x, v.y);
}

Vecteur couple_point_to_vecteur(Point p1, Point p2){
    return nouveau_vecteur(p2.x - p1.x, p2.y - p1.y);
}

//////////////////////////////////////////////////
//                  Operations                  //
//////////////////////////////////////////////////
//vecteurs

Vecteur addition_vecteur(Vecteur v1, Vecteur v2){
    return nouveau_vecteur(v1.x + v2.x, v1.y + v2.y);
}

Vecteur produit_vecteur(double a, Vecteur v){
    return nouveau_vecteur(v.x * a, v.y * a);
}

//point
Point addition_Point(Point p1, Point p2){
    return nouveau_point(p1.x + p2.x, p1.y + p2.y);
}

Point produit_point(double a, Point p){
    return nouveau_point(a * p.x, a * p.y);
}
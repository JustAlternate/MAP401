/****************************************************************************** 
  implementation module geometrie 2D
******************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
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
    return sqrt(produit_scalaire(v, v));
}
//point
//renvoie p1+p2
Point addition_point(Point p1, Point p2){
    return nouveau_point(p1.x + p2.x, p1.y + p2.y);
}
//renvoie λ*p
Point produit_point(double λ, Point p){
    return nouveau_point(λ * p.x, λ * p.y);
}

Point negation_point(Point p){
    return nouveau_point(-1 * p.x, -1 * p.y);
}

//renvoie la distance entre le point p1 et p2
double distance_point(Point p1, Point p2){
    return norme(couple_point_to_vecteur(p1, p2));
}

// CETTE FONCTION EST TESTER DANS LE FICHIER test_simplification_contour.c
double distance_point_segment(Point P, Point A, Point B){
	if (A.x == B.x && A.y == B.y){
		return distance_point(A,P);
	}
	// On est dans le cas A =/= B :
	
	// On commence par calculer lambda
	double lambda = produit_scalaire(couple_point_to_vecteur(A,P),couple_point_to_vecteur(A,B))/produit_scalaire(couple_point_to_vecteur(A,B),couple_point_to_vecteur(A,B));

	// Cas lambda < 0 :
	if (lambda < 0){
		return distance_point(A,P);
	}

	// Cas lambda > 1 :
	if (lambda > 1){
		return distance_point(B,P);
	}

	// Dernier cas 0 <= lambda <= 1 :
	// On calcule le point Q :
    Point Q = addition_point(A, produit_point(lambda, addition_point(B, negation_point(A))));
    //Point Q = nouveau_point(A.x + lambda * (B.x - A.x), A.y * lambda * (B.y - A.y));
    return distance_point(Q,P);
}

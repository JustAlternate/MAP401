#include<stdio.h>
#include<stdlib.h>

#include "geometrie.h"
#include "sequence_point.h"
#include "bezier.h"

//////////////////////////////////////////////////
//                  Beziers                    //
//////////////////////////////////////////////////

Bezier2 init_bezier2(Point C0, Point C1, Point C2){
    Bezier2 bez;
    bez.C0 = C0;
    bez.C1 = C1;
    bez.C2 = C2;
    return bez;
}

Bezier3 init_bezier3(Point C0, Point C1, Point C2, Point C3){
    Bezier3 bez;
    bez.C0 = C0;
    bez.C1 = C1;
    bez.C2 = C2;
    bez.C3 = C3;
    return bez;
}

Point applique_bezier2_point(Bezier2 bez, double x){
    // On recopie simplement la formule de la forme d'une courbe de bezier.
    Point a = produit_point((1-x)*(1 - x), bez.C0);
    Point b = produit_point(2*(1-x)*(x), bez.C1);
    Point c = produit_point((x)*(x), bez.C2);
    return addition_point(addition_point(a,b),c);
}

Point applique_bezier3_point(Bezier3 bez, double x){
    // On recopie simplement la formule de la forme d'une courbe de bezier.
    Point a = produit_point((1-x)*(1-x)*(1-x), bez.C0);
    Point b = produit_point(3*(1-x)*(1-x)*(x), bez.C1);
    Point c = produit_point(3*(1-x)*(x)*(x), bez.C2);
    Point d = produit_point((x)*(x)*(x), bez.C3);
    return addition_point(addition_point(a,b),addition_point(c,d));
}

Bezier3 elevation_de_deg_bezier(Bezier2 bez){
    double a = 1;
    double b = 3;
    double c = a/b;
    return init_bezier3(bez.C0,produit_point(c, addition_point(bez.C0, produit_point(2,bez.C1))),
	    produit_point(c, addition_point(produit_point(2,bez.C1), bez.C2)),bez.C2);
}

double distance_point_courbe_bezier2(Point P, Bezier2 bez, double ti){
    // P le point , bez la courbe de bezier 2
    return distance_point(P,applique_bezier2_point(bez, ti));
}



void print_Bezier2(Bezier2 b){
    printf("B2((%f,%f); (%f,%f); (%f,%f))", b.C0.x, b.C0.y, b.C1.x, b.C1.y, b.C2.x, b.C2.y);
}

#include <stdio.h>

#include "geometrie.h"
#include "types_macros.h"
#include "sequence_point.h"
#include "contour.h"
#include "bezier.h"

Bezier2 approx_bezier2(Cellule_Point *depart, Cellule_Point* fin, int n){
    Bezier2 bez;
    if (n == 1){
        bez = init_bezier2(depart->val, produit_point(0.5, addition_point(depart->val, fin->val)), fin->val);
    }
    else{ // n >= 2
        double n_double = (double)n;
        double a = (n_double*3)/(n_double* n_double -1); // alpha α
        double b = (1-(2*n_double))/(2*(n_double + 1)); // beta β
        
        Cellule_Point* cur = depart->suiv;
        Point C1 = nouveau_point(0, 0);
        while (cur != fin){ //somme P_i+j1
            C1 = addition_point(cur->val, C1);
            cur = cur->suiv;
        }
        C1 = produit_point(a, C1);
        C1 = addition_point(C1, produit_point(b, addition_point(depart->val, fin->val)));

        bez = init_bezier2(depart->val, C1, fin->val);
    }
    return bez;
}


#include <stdio.h>

#include "geometrie.h"
#include "types_macros.h"
#include "sequence_bezier2.h"
#include "sequence_point.h"
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


Motif_Bezier2 simplification_douglas_peucker_Bezier2(Cellule_Point* Pj1, Cellule_Point* Pj2, double d, int nb_elem){
	/*
	nb_elem: nombre d'element-1 (n utilisé dans approx_bezier)
	*/

	Cellule_Point* Pk = Pj1;
	Cellule_Point* Pj = Pj1->suiv;
	int n = 1;

	int nmax = 1;
	double dmax = 0;
	double dj;
	Bezier2 bez = approx_bezier2(Pj1, Pj2, nb_elem);

	while (Pj != Pj2){

		dj = distance_point_courbe_bezier2(Pj->val,bez,((double) n)/nb_elem);

		if (dmax < dj){
			dmax = dj; 
			Pk = Pj;
			nmax = n;
		}
		n++;
		Pj = Pj->suiv;
	}

	Motif_Bezier2 *L = creer_Motif_Bezier2();
	if (dmax <= d){
		ajouter_element_Motif_Bezier2(L, bez);
	}
	else{
		Motif_Bezier2 L1 = simplification_douglas_peucker_Bezier2(Pj1, Pk, d, nmax);
		Motif_Bezier2 L2 = simplification_douglas_peucker_Bezier2(Pk, Pj2, d, (nb_elem-nmax));

		*L = concatener_Motif_Bezier2(L1,L2);
	}
	return *L;
}



Dessin_Bezier2 *simplification_Bezier2(Liste_Contour* LCont, float d){
	Cellule_Contour* cur = LCont->first;
	Dessin_Bezier2* LContS = creer_Dessin_Bezier2();
	while (cur != NULL){
		ajouter_element_Dessin_Bezier2(LContS, simplification_douglas_peucker_Bezier2(cur->val.first, cur->val.last, d, nombre_points(cur->val)-1));//je ne suis pas sur du '-1'
		cur = cur->suiv;
	}
	return LContS;
}
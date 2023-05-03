#include <stdio.h>

#include "geometrie.h"
#include "types_macros.h"
#include "sequence_point.h"
#include "contour.h"

Contour simplification_douglas_peucker(Cellule_Point* Pj1, Cellule_Point* Pj2, double d){

	Cellule_Point* Pk = Pj1;
	Cellule_Point* Pj = Pj1->suiv;

	double dmax = 0;
	double dj;
	while (Pj != Pj2){

		dj = distance_point_segment(Pj->val,Pj1->val,Pj2->val);

		if (dmax < dj){
			dmax = dj; 
			Pk = Pj;
		}

		Pj = Pj->suiv;
	}

	Contour L = creer_liste_Point();
	if (dmax <= d){
		ajouter_element_liste_Point(&L,Pj2->val);
	}
	else{
		Contour L1 = simplification_douglas_peucker(Pj1, Pk, d);
		Contour L2 = simplification_douglas_peucker(Pk, Pj2, d);

		L = concatener_liste_Point(L1,L2);
	}
	return L;
}

Contour enrobage_douglas(Contour Cont, double d){
	Contour L = simplification_douglas_peucker(Cont.first, Cont.last, d);
	Contour petit_L = creer_liste_Point();
	ajouter_element_liste_Point(&L, Cont.first->val);
	L = concatener_liste_Point(petit_L, L);
	return L;
}


Liste_Contour *simplification_segment(Liste_Contour* LCont, double d){
	Cellule_Contour* cur = LCont->first;
	Liste_Contour* LContS = creer_liste_Contour();
	while (cur != NULL){
		ajouter_element_liste_Contour(LContS, enrobage_douglas(cur->val, d));
		cur = cur->suiv;
	}
	return LContS;
}
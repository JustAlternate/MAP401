#ifndef _SEQUENCE_POINT_H_
#define _SEQUENCE_POINT_H_

#include "geometrie.h"


typedef struct Cellule_Point_{
	Point val;    /* donn�e de l'�l�ment de liste */
	struct Cellule_Liste_Point_* suiv; /* pointeur sur l'�l�ment suivant */
} Cellule_Point;

typedef struct Liste_Point_{
	unsigned int taille;        /* nombre d'�l�ments dans la liste */
	Cellule_Point *first; /* pointeur sur le premier �l�ment de la liste */
	Cellule_Point *last;  /* pointeur sur le dernier �l�ment de la liste */
} Liste_Point;

typedef Liste_Point Contour; /* type Contour = type Liste_Point */

Liste_Point creer_liste_Point();
Cellule_Point *creer_element_liste_Point(Point v);
Liste_Point ajouter_element_liste_Point(Liste_Point L, Point e);
Liste_Point supprimer_liste_Point(Liste_Point L);
Liste_Point concatener_liste_Point(Liste_Point L1, Liste_Point L2);
void print_liste_Point(Liste_Point l);
int nombre_segments(Liste_Point L);

#endif

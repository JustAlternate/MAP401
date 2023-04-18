#ifndef _SEQUENCE_POINT_H_
#define _SEQUENCE_POINT_H_

#include "geometrie.h"
#include "bezier.h"


typedef struct Cellule_Point_{
	Point val;    /* donn�e de l'�l�ment de liste */
	struct Cellule_Point_* suiv; /* pointeur sur l'�l�ment suivant */
} Cellule_Point;

typedef struct Liste_Point_{
	unsigned int taille;        /* nombre d'�l�ments dans la liste */
	Cellule_Point *first; /* pointeur sur le premier �l�ment de la liste */
	Cellule_Point *last;  /* pointeur sur le dernier �l�ment de la liste */
} Liste_Point;
typedef Liste_Point Contour; /* type Contour = type Liste_Point */

typedef struct Cellule_Contour_{
	Contour val;    /* donn�e de l'�l�ment de liste */
	struct Cellule_Contour_* suiv; /* pointeur sur l'�l�ment suivant */
} Cellule_Contour;

typedef struct{
	unsigned int taille;        /* nombre d'�l�ments dans la liste */
	Cellule_Contour *first; /* pointeur sur le premier �l�ment de la liste */
	Cellule_Contour *last;  /* pointeur sur le dernier �l�ment de la liste */
} Liste_Contour;

typedef struct Cellule_Bezier2_{
	Bezier2 val;    /* donn�e de l'�l�ment de liste */
	struct Cellule_Bezier2_* suiv; /* pointeur sur l'�l�ment suivant */
} Cellule_Bezier2;

typedef struct Liste_Bezier2_{
	unsigned int taille;        /* nombre d'�l�ments dans la liste */
	Cellule_Bezier2 *first; /* pointeur sur le premier �l�ment de la liste */
	Cellule_Bezier2 *last;  /* pointeur sur le dernier �l�ment de la liste */
} Liste_Bezier2;

// Tout ce qui relate des points
Liste_Point creer_liste_Point();
Cellule_Point *creer_element_liste_Point(Point v);
void ajouter_element_liste_Point(Liste_Point* L, Point e);
Liste_Point supprimer_liste_Point(Liste_Point L);
Liste_Point concatener_liste_Point(Liste_Point L1, Liste_Point L2);
void print_liste_Point(Liste_Point l);
int nombre_segments(Liste_Point L);
int nombre_points(Liste_Point L);

// Tout ce qui relate des Contours
Liste_Contour* creer_liste_Contour();
Cellule_Contour *creer_element_liste_Contour(Contour v);
void ajouter_element_liste_Contour(Liste_Contour* L, Contour e);
Liste_Contour supprimer_liste_Contour(Liste_Contour L);
Liste_Contour concatener_liste_Contour(Liste_Contour L1, Liste_Contour L2);
void print_liste_Contour(Liste_Contour *l);
int nombre_Contour(Liste_Contour L);
int nombre_points_Liste_Contour(Liste_Contour L);
int nombre_segments_Liste_Contour(Liste_Contour L);

//tout ce que relate des litdes de bezier2
Liste_Bezier2* creer_liste_Bezier2();
Cellule_Bezier2 *creer_element_liste_Bezier2(Bezier2 v);
void ajouter_element_liste_Bezier2(Liste_Bezier2* L, Bezier2 e);
Liste_Bezier2 supprimer_liste_Bezier2(Liste_Bezier2 L);
Liste_Bezier2 concatener_liste_Bezier2(Liste_Bezier2 L1, Liste_Bezier2 L2);
void print_liste_Bezier2(Liste_Bezier2 *l);
int nombre_Bezier2(Liste_Bezier2 L);
#endif

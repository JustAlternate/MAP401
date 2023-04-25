#ifndef _SEQUENCE_BEZIER2_H_
#define _SEQUENCE_BEZIER2_H_

#include "geometrie.h"
#include "bezier.h"

typedef struct Cellule_Motif_Bezier2_{
	Bezier2 val;    /* donn�e de l'�l�ment de liste */
	struct Cellule_Motif_Bezier2_* suiv; /* pointeur sur l'�l�ment suivant */
} Cellule_Motif_Bezier2;

typedef struct Motif_Bezier2_{
	unsigned int taille;        /* nombre d'�l�ments dans la liste */
	Cellule_Motif_Bezier2 *first; /* pointeur sur le premier �l�ment de la liste */
	Cellule_Motif_Bezier2 *last;  /* pointeur sur le dernier �l�ment de la liste */
} Motif_Bezier2;

typedef struct Cellule_Dessin_Bezier2_{
	Motif_Bezier2 val;    /* donn�e de l'�l�ment de liste */
	struct Cellule_Dessin_Bezier2_* suiv; /* pointeur sur l'�l�ment suivant */
} Cellule_Dessin_Bezier2;

typedef struct Dessin_Bezier2_{
	unsigned int taille;        /* nombre d'�l�ments dans la liste */
	Cellule_Dessin_Bezier2 *first; /* pointeur sur le premier �l�ment de la liste */
	Cellule_Dessin_Bezier2 *last;  /* pointeur sur le dernier �l�ment de la liste */
} Dessin_Bezier2;



//tout ce que relate des Motif de bezier2 (liste de bezier2)
Motif_Bezier2* creer_Motif_Bezier2();
Cellule_Motif_Bezier2 *creer_element_Motif_Bezier2(Bezier2 v);
void ajouter_element_Motif_Bezier2(Motif_Bezier2* L, Bezier2 e);
void supprimer_Motif_Bezier2(Motif_Bezier2 L);
Motif_Bezier2 concatener_Motif_Bezier2(Motif_Bezier2 L1, Motif_Bezier2 L2);
void print_Motif_Bezier2(Motif_Bezier2 *l);
int nombre_Bezier2(Motif_Bezier2 L);

// Tout ce qui relate des Dessin Bezier2
Dessin_Bezier2* creer_Dessin_Bezier2();
Cellule_Dessin_Bezier2 *creer_element_Dessin_Bezier2(Motif_Bezier2 v);
void ajouter_element_Dessin_Bezier2(Dessin_Bezier2 *L, Motif_Bezier2 e);
void supprimer_Dessin_Bezier2(Dessin_Bezier2 L);
Dessin_Bezier2 concatener_Dessin_Bezier2(Dessin_Bezier2 L1, Dessin_Bezier2 L2);
void print_Dessin_Bezier2(Dessin_Bezier2 *L);
int nombre_Motif_dans_Dessin_Bezier2(Dessin_Bezier2 L);


#endif

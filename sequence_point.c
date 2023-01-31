/****************************************************************************** 
  Implementation du module sequence_point.c
******************************************************************************/

#include <stdio.h>
#include "sequence_point.h"
#include "geometrie.h"

Liste_Point creer_liste_Point()
{
	Liste_Point L = {0, NULL, NULL};
	return L;
}
Cellule_Point *creer_element_liste_Point(Point v)
{
	Cellule_Point *el;
	el = (Cellule_Point *)malloc(sizeof(Cellule_Point));
	if (el==NULL)
	{
		fprintf(stderr, "creer_element_liste_Point : allocation impossible\n");
		exit(-1);
	}
	el->val = v;
	el->suiv = NULL;
	return el;
}

Liste_Point ajouter_element_liste_Point(Liste_Point L, Point e)
{
	Cellule_Point *el;
	
	el = creer_element_liste_Point(e);
	if (L.taille == 0)
	{
		/* premier �l�ment de la liste */
		L.first = L.last = el;
	}
	else
	{
		L.last->suiv = el;
		L.last = el;
	}
	L.taille++;
	return L;
}
Liste_Point supprimer_liste_Point(Liste_Point L)
{
	Cellule_Point *el=L.first;
	
	while (el) 
	{		
		Cellule_Point *suiv=el->suiv;
		free(el);
		el = suiv;
	}
	L.first = L.last = NULL; L.taille = 0;
	return L;
}

/* concat�ne L2 � la suite de L1, renvoie la liste L1 modifi�e */
Liste_Point concatener_liste_Point(Liste_Point L1, Liste_Point L2)
{
	/* cas o� l'une des deux listes est vide */
	if (L1.taille == 0) return L2; 
	if (L2.taille == 0) return L1;
	
	/* les deux listes sont non vides */
	L1.last->suiv = L2.first; /* lien entre L1.last et L2.first */
	L1.last = L2.last;        /* le dernier �l�ment de L1 est celui de L2 */
	L1.taille += L2.taille;   /* nouvelle taille pour L1 */
	return L1;
}

void print_liste_Point(Liste_Point L){
	printf("{");
	Cellule_Point* cur = L.first;
	while(cur!=NULL){
		printf("(%f,%f), ", cur->val.x, cur->val.y);
		cur = cur->suiv;
	}
	printf("}\n");
}

int nombre_segments(Liste_Point L){
	int nb = 0;
	Cellule_Point* cur = L.first;
	while(cur!=NULL){
		nb++;
		cur=cur->suiv;
	}
	return nb-1;
}

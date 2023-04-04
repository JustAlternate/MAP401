/****************************************************************************** 
  Implementation du module sequence_point.c
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
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

void ajouter_element_liste_Point(Liste_Point* L, Point e)
{
	Cellule_Point *el;
	
	el = creer_element_liste_Point(e);
	if (L->taille == 0)
	{
		/* premier �l�ment de la liste */
		L->first = L->last = el;
	}
	else
	{
		L->last->suiv = el;
		L->last = el;
	}
	L->taille++;
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

int nombre_points(Liste_Point L){
	//nombre de point dans le contour L
	int nb = 0;
	Cellule_Point* cur = L.first;
	while(cur!=NULL){
		nb++;
		cur=cur->suiv;
	}
	return nb;
}
int nombre_segments(Liste_Point L){
	//nombre de segments dans le contour L
	int nb = 0;
	Cellule_Point* cur = L.first;
	while(cur!=NULL){
		nb++;
		cur=cur->suiv;
	}
	return nb;
}


Liste_Contour* creer_liste_Contour(){
	Liste_Contour *L = malloc(sizeof(Liste_Contour));
	L->taille = 0;
	L->first = NULL;
	L->last = NULL; 
	return L;
}
Cellule_Contour *creer_element_liste_Contour(Contour v)
{
	Cellule_Contour *el;
	el = (Cellule_Contour *)malloc(sizeof(Cellule_Contour));
	if (el==NULL)
	{
		fprintf(stderr, "creer_element_liste_Contour: allocation impossible\n");
		exit(-1);
	}
	el->val = v;
	el->suiv = NULL;
	return el;
}

void ajouter_element_liste_Contour(Liste_Contour *L, Contour e)
{
	Cellule_Contour *el;

	el = creer_element_liste_Contour(e);
	if (L->taille == 0)
	{
		/* premier �l�ment de la liste */
		L->first = el;
		L->last = el;
	}
	else
	{
		L->last->suiv = el;
		L->last = el;
	}
	L->taille++;
}
Liste_Contour supprimer_liste_Contour(Liste_Contour L)
{
	Cellule_Contour *el=L.first;
	
	while (el) 
	{		
		Cellule_Contour *suiv=el->suiv;
		supprimer_liste_Point(el->val);
		free(el);
		el = suiv;
	}
	L.first = L.last = NULL; L.taille = 0;
	return L;
}

/* concat�ne L2 � la suite de L1, renvoie la liste L1 modifi�e */
Liste_Contour concatener_liste_Contour(Liste_Contour L1, Liste_Contour L2)
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

void print_liste_Contour(Liste_Contour *L){
	printf("{");
	Cellule_Contour* cur = L->first;
	while(cur!=NULL){
		print_liste_Point(cur->val);
		cur = cur->suiv;
		printf("; ");
	}
	printf("}\n");
}

int nombre_Contour(Liste_Contour L){
	//la somme du nombre de Contours dans la liste chainée de contour L (on ne s'intéresse pas à ce que contiennent les contours)
	int nb = 0;
	Cellule_Contour* cur = L.first;
	while(cur!=NULL){
		nb++;
		cur=cur->suiv;
	}
	return nb;
}
int nombre_points_Liste_Contour(Liste_Contour L){
	//la somme du nombre de points total de la liste de contours L
	int nb = 0;
	Cellule_Contour* cur = L.first;
	while(cur!=NULL){
		nb+= nombre_points(cur->val);
		cur=cur->suiv;
	}
	return nb;
}
int nombre_segments_Liste_Contour(Liste_Contour L){
	//la somme du nombre de segments total de la liste de contours L
	int nb = 0;
	Cellule_Contour* cur = L.first;
	while(cur!=NULL){
		nb+= nombre_segments(cur->val);
		cur=cur->suiv;
	}
	return nb;
}





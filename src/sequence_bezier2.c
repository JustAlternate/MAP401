/****************************************************************************** 
  Implementation du module sequence_bezier2.c
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "sequence_bezier2.h"
#include "geometrie.h"
#include "bezier.h"

//######################//
//		Bezier2			//
//######################//

Motif_Bezier2* creer_Motif_Bezier2(){
	Motif_Bezier2 *L = malloc(sizeof(Motif_Bezier2));
	L->taille = 0;
	L->first = NULL;
	L->last = NULL; 
	return L;
}
Cellule_Motif_Bezier2 *creer_element_Motif_Bezier2(Bezier2 v)
{
	Cellule_Motif_Bezier2 *el;
	el = (Cellule_Motif_Bezier2 *)malloc(sizeof(Cellule_Motif_Bezier2));
	if (el==NULL)
	{
		fprintf(stderr, "creer_element_Motif_Bezier2: allocation impossible\n");
		exit(-1);
	}
	el->val = v;
	el->suiv = NULL;
	return el;
}

void ajouter_element_Motif_Bezier2(Motif_Bezier2 *L, Bezier2 e)
{
	Cellule_Motif_Bezier2 *el;

	el = creer_element_Motif_Bezier2(e);
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
void supprimer_Motif_Bezier2(Motif_Bezier2 L)
{
	Cellule_Motif_Bezier2 *el=L.first;
	
	while (el != NULL) 
	{		
		Cellule_Motif_Bezier2 *suiv=el->suiv;
		free(el);
		el = suiv;
	}
}

/* concat�ne L2 � la suite de L1, renvoie la liste L1 modifi�e */
Motif_Bezier2 concatener_Motif_Bezier2(Motif_Bezier2 L1, Motif_Bezier2 L2)
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

void print_Motif_Bezier2(Motif_Bezier2 *L){
	printf("{");
	Cellule_Motif_Bezier2* cur = L->first;
	while(cur!=NULL){
		print_Bezier2(cur->val);
		cur = cur->suiv;
		printf("; ");
	}
	printf("}\n");
}

int nombre_Bezier2(Motif_Bezier2 L){
	//la somme du nombre de Bezier2s dans la liste chainée de Bezier2 L (on ne s'intéresse pas à ce que contiennent les Bezier2s)
	int nb = 0;
	Cellule_Motif_Bezier2* cur = L.first;
	while(cur!=NULL){
		nb++;
		cur=cur->suiv;
	}
	return nb;
}

int nombre_Bezier2_dans_Dessin(Dessin_Bezier2 D){
	int nb = 0;
	Cellule_Dessin_Bezier2* cur = D.first;
	while(cur!=NULL){
		nb += nombre_Bezier2(cur->val);
		cur = cur->suiv;
	}
	return nb;
}

//#################
// Dessin_Bezier2//
//#################

Dessin_Bezier2* creer_Dessin_Bezier2(){
	Dessin_Bezier2 *L = malloc(sizeof(Dessin_Bezier2));
	L->taille = 0;
	L->first = NULL;
	L->last = NULL; 
	return L;
}
Cellule_Dessin_Bezier2 *creer_element_Dessin_Bezier2(Motif_Bezier2 v)
{
	Cellule_Dessin_Bezier2 *el;
	el = (Cellule_Dessin_Bezier2 *)malloc(sizeof(Cellule_Dessin_Bezier2));
	if (el==NULL)
	{
		fprintf(stderr, "creer_element_Dessin_Bezier2: allocation impossible\n");
		exit(-1);
	}
	el->val = v;
	el->suiv = NULL;
	return el;
}

void ajouter_element_Dessin_Bezier2(Dessin_Bezier2 *L, Motif_Bezier2 e)
{
	Cellule_Dessin_Bezier2 *el;

	el = creer_element_Dessin_Bezier2(e);
	if (L->taille == 0){
		/* premier �l�ment de la liste */
		L->first = el;
		L->last = el;
	}
	else{
		L->last->suiv = el;
		L->last = el;
	}
	L->taille++;
}
void supprimer_Dessin_Bezier2(Dessin_Bezier2 L)
{
	Cellule_Dessin_Bezier2 *el=L.first;
	
	while (el != NULL) {
		Cellule_Dessin_Bezier2 *suiv=el->suiv;
		supprimer_Motif_Bezier2(el->val);
		free(el);
		el = suiv;
	}
}

/* concat�ne L2 � la suite de L1, renvoie la liste L1 modifi�e */
Dessin_Bezier2 concatener_Dessin_Bezier2(Dessin_Bezier2 L1, Dessin_Bezier2 L2)
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

void print_Dessin_Bezier2(Dessin_Bezier2 *L){
	printf("{");
	Cellule_Dessin_Bezier2* cur = L->first;
	while(cur!=NULL){
		print_Motif_Bezier2(&(cur->val));
		cur = cur->suiv;
		printf("; ");
	}
	printf("}\n");
}

int nombre_Motif_dans_Dessin_Bezier2(Dessin_Bezier2 L){
	//la somme du nombre de Contours dans la liste chainée de Motif_Bezier2 L (on ne s'intéresse pas à ce que contiennent les contours)
	int nb = 0;
	Cellule_Dessin_Bezier2* cur = L.first;
	while(cur!=NULL){
		nb++;
		cur=cur->suiv;
	}
	return nb;
}

/****************************************************************************** 
  Implementation du module contour.c
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "geometrie.h"
#include "image.h"
#include "sequence_point.h"
#include "contour.h"

Point trouver_pixel_depart(Image I){
	UINT h_img = hauteur_image(I)+1;
	UINT l_img = largeur_image(I)+1;
	for (double i = 1; i<h_img;i++){
		for(double j = 1; j<l_img;j++){
			if (get_pixel_image(I,i,j)){
				if (!get_pixel_image(I,i,j-1)){
					Point p = nouveau_point(i,j);
					return p;
				}
			}
		}
	}
	Point p = nouveau_point(0,0);
	return p;
}

Point avancer(Point pos, Orientation ori){
	switch (ori){
		case Est:
			pos.x++;
			break;
		case Ouest:
			pos.x--;
			break;
		case Nord:
			pos.y--;
			break;
		case Sud:
			pos.y++;
			break;
	}
	return pos;
}

Orientation nouvelle_orientation(Point pos, Orientation ori, Image I){
	switch (ori){
		case Nord:
			if(get_pixel_image(I,(int)pos.x,(int)pos.y)){
				return Ouest;
			}else{
				if(get_pixel_image(I,(int)pos.x + 1,(int)pos.y)){
					return Nord;
				}
				return Est;
			}

		case Est:
			if(get_pixel_image(I,(int)pos.x + 1,(int)pos.y)){
				return Nord;
			}else{
				if(get_pixel_image(I,(int)pos.x + 1,(int)pos.y +1)){
					return Est;
				}
				return Sud;
			}
		case Sud:
			if(get_pixel_image(I,(int)pos.x +1,(int)pos.y +1)){
				return Est;
			}else{
				if(get_pixel_image(I,(int)pos.x,(int)pos.y +1)){
					return Sud;
				}
				return Ouest;
			}
		case Ouest:
			if(get_pixel_image(I,(int)pos.x,(int)pos.y +1)){
				return Sud;
			}else{
				if(get_pixel_image(I,(int)pos.x,(int)pos.y)){
					return Ouest;
				}
				return Nord;
			}
	}
}

Contour recherche_contour(Point depart, Image I){
	Contour LC = creer_liste_Point();
	Point vrai_Depart = depart;
	vrai_Depart.x --;
	vrai_Depart.y --;
	Orientation ori = Est;
	Point pos = nouveau_point(vrai_Depart.x,vrai_Depart.y);
	do{
		ajouter_element_liste_Point(&LC,pos);
		pos = avancer(pos,ori);
		ori = nouvelle_orientation(pos, ori, I);
	}
	while(!(pos.x == vrai_Depart.x && pos.y == vrai_Depart.y && ori == Est));
	return LC;
}

Contour recherche_contour_et_image_mask(Point depart, Image I, Image mask){
	Contour LC = creer_liste_Point();
	Point vrai_Depart = depart;
	vrai_Depart.x --;
	vrai_Depart.y --;
	Orientation ori = Est;
	Point pos = nouveau_point(vrai_Depart.x,vrai_Depart.y);
	do{
		ajouter_element_liste_Point(&LC,pos);
		pos = avancer(pos,ori);
		ori = nouvelle_orientation(pos, ori, I);
		if (ori == Est){
			set_pixel_image(mask,pos.x+1,pos.y+1,0);
		}
	}
	while(!(pos.x == vrai_Depart.x && pos.y == vrai_Depart.y && ori == Est));
	return LC;
}

void qui_save_dans_un_fichier(char *name, Liste_Point LC){
	//    /!\ sauvegarde un contour et non une liste de contours.
	FILE *f = fopen(name, "w");
	if (f == NULL){
		printf("erreur: overture du fichier impossible");
		return;
	}
	fprintf(f, "1\n\n");
	fprintf(f,"%d",nombre_segments(LC));
	Cellule_Point *cur = LC.first;
	while (cur!=NULL){
		fprintf(f, "%f %f", cur->val.x, cur->val.y);
	}
	fclose(f);
}

void sauveguarde_LC_contour(char *name, Liste_Contour LC){ 
	// sauvegarde dans un fichier la liste chainée de contour 
	// la fonction qui_save_dans_un_fichier ne sauvegarde que un coutour et non une liste de contour
	FILE *f = fopen(name, "w");
	if (f == NULL){
		printf("erreur: overture du fichier impossible");
		return;
	}
	fprintf(f, "%d\n\n", nombre_Contour(LC));
	Cellule_Contour *cell_cont = LC.first;
	while (cell_cont != NULL)
	{
		fprintf(f, "%d", nombre_segments(cell_cont->val));
		Cellule_Point *cell = cell_cont->val.first;
		while (cell!=NULL)
		{
			fprintf(f, "%f %f", cell->val.x, cell->val.y);
		}	
	}
	fclose(f);
}

Liste_Contour* recherche_tous_les_contours(Image img){
	Image masque = creer_masque(img);
	Liste_Contour *LC = creer_liste_Contour();
	int hauteur = hauteur_image(img);
	int largeur = largeur_image(img);
	for (int x = 1; x <= largeur; x++){
		for (int y = 1; y <= hauteur; y++){
			if (get_pixel_image(masque, x, y) == 1){ //il faut réaliser un contour ici
					ajouter_element_liste_Contour(LC, recherche_contour_et_image_mask(nouveau_point(x, y), img, masque));
			}
		}
	}
	return LC;
}

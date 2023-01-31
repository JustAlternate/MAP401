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
	for (double i = 1; i<hauteur_image(I);i++){
		for(double j = 1; j<largeur_image(I);j++){
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
		LC = ajouter_element_liste_Point(LC,pos);
		pos = avancer(pos,ori);
		ori = nouvelle_orientation(pos, ori, I);
	}
	while(!(pos.x == vrai_Depart.x && pos.y == vrai_Depart.y && ori == Est));
	return LC;
}


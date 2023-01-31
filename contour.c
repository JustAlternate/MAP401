/****************************************************************************** 
  Implementation du module contour.c
******************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include "geometrie.h"
#include "image.h"

Point trouver_pixel_depart(Image I){
	for (double i = 1; i<hauteur_image(I);i++){
		for(double j = 1; j<largeur_image(I);j++){
			if (get_pixel_image(I,i,j)){
				if (get_pixel_image(I,i,j-1)){
					Point p = nouveau_point(i,j);
					return p;
				}
			}
		}
	}
	Point p = nouveau_point(0,0);
	return p;
}

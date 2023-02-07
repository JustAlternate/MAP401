#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "image.h"
#include "geometrie.h"
#include "contour.h"


char* name_to_name_eps(char* nom_fichier){
	char* name = malloc(sizeof(char)*strlen(nom_fichier) + 4);
	strcpy(name,nom_fichier);
	strcat(name,".eps");
	return name;
}

// Faire une fonction qui initialise un fichier EPS.
FILE* init_fichier_eps(char* nom_fichier,int xmin, int ymin, int xmax, int ymax){

	char *name = name_to_name_eps(nom_fichier);
	FILE* f = fopen(name,"w");
	fprintf(f,"%!PS-Adobe-3.0 EPSF-3.0\n");
	fprintf(f,"%%BoundingBox: %d %d %d %d\n",xmin,ymin,xmax,ymax);
	return f;
}

// Faire une fonction qui dessine une ligne d'un point départ a un point arrivés.
void dessiner_ligne(FILE* f, int x_dep,int y_dep,int x_fin, int y_fin, bool style, bool r, bool g, bool b, float width){
	/*
	Permet de tracer une ligne dans un fichier .eps (apres initialisation de celui-çi.
	nom_fichier: le nom du fichier (avec le .eps a la fin)
	x_dep,y_dep: les coordonnées en int du point de départ.
	x_fin,y_fin: les coordonnées en int du point de fin.
	syle: si 0 = stroke, si 1 = fill
	r,g,b: des booléen pour la couleur, exemple si r=1,b=0,g=0 --> couleur rouge.
	width: la largeur du trait dessiné en float.
	*/

}



// Faire une fonction qui prend un contour et qui dessine le contour dans un fichier EPS
void dessiner_contour(Contour CT, FILE* f,bool style, bool r, bool g, bool b, float width){
	/*
	Initialise un fichier .eps puis utillise la liste chainée contour pour dessiner tout les segments.
	nom_fichier: le nom du fichier (avec le .eps a la fin)
	x_dep,y_dep: les coordonnées en int du point de départ.
	x_fin,y_fin: les coordonnées en int du point de fin.
	syle: si 0 = stroke, si 1 = fill
	r,g,b: des booléen pour la couleur, exemple si r=1,b=0,g=0 --> couleur rouge.
	width: la largeur du trait dessiné en float.
	*/
}

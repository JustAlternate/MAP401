#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "image.h"
#include "geometrie.h"
#include "contour.h"
#include "bezier.h"
#include "sequence_bezier2.h"


char* name_to_name_eps(char* nom_fichier){
	char* name = malloc(sizeof(char)*strlen(nom_fichier) + 5);
	strcpy(name,nom_fichier);
	strcat(name,".eps");
	return name;
}

// Faire une fonction qui initialise un fichier EPS.
FILE* init_fichier_eps(char* nom_fichier,int xmin, int ymin, int xmax, int ymax){
	char *name = name_to_name_eps(nom_fichier);
	FILE* f = fopen(name,"w");
	fprintf(f,"\%!PS-Adobe-3.0 EPSF-3.0\n");
	fprintf(f,"%%%%BoundingBox: %d %d %d %d\n",xmin,ymin,xmax,ymax);
	free(name);
	return f;
}

// Faire une fonction qui dessine une ligne d'un point départ a un point arrivés.
void dessiner_ligne(FILE* f, int x_dep,int y_dep,int x_fin, int y_fin, bool style, bool r, bool g, bool b, float width){
	/*
	Permet de tracer une ligne dans un fichier .eps (apres initialisation de celui-çi.
	nom_fichier: le nom du fichier (avec le .eps a la fin)
	x_dep,y_dep: les coordonnées en int du point de départ.
	x_fin,y_fin: les coordonnées en int du point de fin.
	syle: si 1 = stroke, si 0 = fill
	r,g,b: des booléen pour la couleur, exemple si r=1,b=0,g=0 --> couleur rouge.
	width: la largeur du trait dessiné en float.
	*/
	fprintf(f,"%d %d moveto %d %d lineto\n",x_dep,y_dep,x_fin,y_fin);
	fprintf(f,"%d %d %d setrgbcolor %.1f setlinewidth\n",r,g,b,width);
}

// Faire une fonction qui prend un contour et qui dessine le contour dans un fichier EPS
void dessiner_contour(Contour CT, FILE* f, bool r, bool g, bool b, float width, int ymax){
	/*
	Initialise un fichier .eps puis utillise la liste chainée contour pour dessiner tout les segments.
	nom_fichier: le nom du fichier (avec le .eps a la fin)
	x_dep,y_dep: les coordonnées en int du point de départ.
	x_fin,y_fin: les coordonnées en int du point de fin.
	syle: si 0 = stroke, si 1 = fill
	r,g,b: des booléen pour la couleur, exemple si r=1,b=0,g=0 --> couleur rouge.
	width: la largeur du trait dessiné en float.
	ymax: hauteur de l'image
	*/
	Cellule_Point* p1 = CT.first;
	fprintf(f,"%d %d moveto ",(int)p1->val.x,ymax-(int)p1->val.y);
	p1 = p1->suiv;
	while(p1!=NULL){
		fprintf(f,"%d %d lineto ",(int)p1->val.x,ymax-(int)p1->val.y);
		p1 = p1->suiv;
	}
	fprintf(f,"\n%d %d %d setrgbcolor %.1f setlinewidth\n",r,g,b,width);
}

void enregistrer_liste_contour_vers_EPS(Liste_Contour* LC, char* nom_fichier, int style, int largeur_img, int hauteur_img){
	/*
	style = 0: stroke
	style = 1: fill
	*/
    FILE* f = init_fichier_eps(nom_fichier,0,0,largeur_img,hauteur_img);
    Cellule_Contour *cell_cont = LC->first;
    while (cell_cont != NULL){
        dessiner_contour(cell_cont->val,f,0,0,0,1.,hauteur_img);
        cell_cont = cell_cont->suiv;
    }
	if (style){
		fprintf(f,"fill\n");
	}else{
		fprintf(f,"stroke\n");
	}
    fprintf(f,"showpage");
    fclose(f);
}

// Fonction qui prend un motif (voir explication motif et dessin dans sequence_bezier2) et qui va transformer la courbe de bézier2 en bézier3 et qui ensuite va écrire dans le fichier EPS.
void dessiner_motif_Bezier2(FILE* f, Motif_Bezier2 *Mot_bez2, int hauteur_img){

	Cellule_Motif_Bezier2 *cell_mot_bez2 = Mot_bez2->first;

	// Avant de boucler, on va faire un premier moveto.
	
	fprintf(f,"%f %f moveto\n",cell_mot_bez2->val.C0.x, hauteur_img - cell_mot_bez2->val.C0.y);

	while (cell_mot_bez2 != NULL){
		Bezier3 bez3 = elevation_de_deg_bezier(cell_mot_bez2->val);
		// time to draw la bezier 3
		fprintf(f, "%f %f %f %f %f %f curveto ", bez3.C1.x, hauteur_img - bez3.C1.y, bez3.C2.x, hauteur_img - bez3.C2.y, bez3.C3.x, hauteur_img - bez3.C3.y);
		cell_mot_bez2 = cell_mot_bez2->suiv;
	}
	fprintf(f, "\n");
}

void enregister_dessin_Bezier2_vers_EPS(Dessin_Bezier2 *des_bez2, char* nom_fichier, int largeur_img, int hauteur_img){

	FILE* f = init_fichier_eps(nom_fichier,0,0,largeur_img,hauteur_img);
	Cellule_Dessin_Bezier2 *cell_des_bez2 = des_bez2->first;
	while (cell_des_bez2 != NULL){
		dessiner_motif_Bezier2(f, &cell_des_bez2->val, hauteur_img);
		cell_des_bez2 = cell_des_bez2->suiv;
	}
	fprintf(f,"fill\n");
	fprintf(f,"showpage");
	fclose(f);
}


/****************************************************************************** 
  Interface du module EPS
******************************************************************************/

#ifndef _EPS_H_
#define _EPS_H_

#include "image.h"
#include "geometrie.h"
#include "sequence_point.h"
#include "contour.h"
#include "bezier.h"
#include "sequence_bezier2.h"

char* name_to_name_eps(char* nom_fichier);
FILE* init_fichier_eps(char* nom_fichier,int xmin, int ymin, int xmax, int ymax);
void dessiner_ligne(FILE* f, int x_dep,int y_dep,int x_fin, int y_fin, bool style, bool r, bool g, bool b, float width);
void enregistrer_liste_contour_vers_EPS(Liste_Contour *LC, char *nom_fichier, int style, int largeur_img, int hauteur_img);
void dessiner_contour(Contour CT, FILE *f, bool r, bool g, bool b, float width, int ymax);
void dessiner_motif_Bezier2(FILE* f, Motif_Bezier2 *Mot_bez2, int hauteur_img);
void enregister_dessin_Bezier2_vers_EPS(Dessin_Bezier2 *des_bez2, char* nom_fichier, int largeur_img, int hauteur_img);


#endif /* _EPS_H_ */

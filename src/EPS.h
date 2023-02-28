/****************************************************************************** 
  Interface du module EPS
******************************************************************************/

#ifndef _EPS_H_
#define _EPS_H_

#include "image.h"
#include "geometrie.h"
#include "sequence_point.h"
#include "contour.h"

char* name_to_name_eps(char* nom_fichier);
FILE* init_fichier_eps(char* nom_fichier,int xmin, int ymin, int xmax, int ymax);
void dessiner_ligne(FILE* f, int x_dep,int y_dep,int x_fin, int y_fin, bool style, bool r, bool g, bool b, float width);
void dessiner_contour(Contour CT, FILE* f, bool r, bool g, bool b, float width, int ymax);


#endif /* _EPS_H_ */

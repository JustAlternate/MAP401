#include "image.h"
#include "sequence_point.h"
#include "contour.h"
#include "simplification_contour.h"
#include "EPS.h"



int main(int argc, char** argv){

    if(argc != 4){
        printf("usgae: %s <nom_fichier_image> <distance_seuil> <nom_fichier_sortie>\n", argv[0]);
        return 1;
    }

    int d;
    sscanf(argv[2], "%d", &d);

    Image img = lire_fichier_image(argv[1]);
    Liste_Contour* LC = recherche_tous_les_contours(img);
    Liste_Contour *LCs = simplification_segment(LC, d);
    enregistrer_liste_contour_vers_EPS(LCs, argv[3], 1, largeur_image(img), hauteur_image(img));

}
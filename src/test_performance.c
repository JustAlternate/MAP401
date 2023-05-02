#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "geometrie.h"
#include "types_macros.h"
#include "image.h"
#include "contour.h"
#include "sequence_point.h"
#include "sequence_bezier2.h"
#include "simplification_bezier2.h"
#include "simplification_contour.h"
#include "EPS.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define RESET_COLOR        "\x1B[0m"

//fonctions pratiques:
void afficher_resultat_test(int b){
    if (b){
        printf("%sSUCCESS%s\n", ANSI_COLOR_GREEN, RESET_COLOR);
    }
    else{
        printf("%sFAILED%s\n", ANSI_COLOR_RED, RESET_COLOR);
    }
}

void tester_image_segment(char* nom_entree, char* nom_sortie, int d){
    printf("simplification segment: %s -> %s\n", nom_entree, nom_sortie);

    Image img = lire_fichier_image(nom_entree);

    Liste_Contour * LC_cont = recherche_tous_les_contours(img);
    Liste_Contour *LC_simplifier = simplification_segment(LC_cont, d);
    
    int nombre_contours_image = nombre_Contour(*LC_cont);
    int nombre_segments_image = nombre_segments_Liste_Contour(*LC_cont);
    int nombre_segment_simplifier = nombre_segments_Liste_Contour(*LC_simplifier);
    printf("Informations:\n");
    printf("Image d'origine : \n  -nombre de contours:%d\n  -nombre de segments:%d \n",nombre_contours_image, nombre_segments_image);
    printf("Image simplifiée : \n  -nombre de segments:%d\n",nombre_segment_simplifier);

    enregistrer_liste_contour_vers_EPS(LC_simplifier, nom_sortie, 1, img.la_largeur_de_l_image, img.la_hauteur_de_l_image);

    supprimer_liste_Contour(*LC_simplifier);
    supprimer_liste_Contour(*LC_cont);
    supprimer_image(&img);
}

int main(int argc, char** argv){

    if (argc != 4){
        printf("usage: %s <nom_image> <distance_seuil> <format=s(segment) b(bezier2)> \n", argv[0]);
        return 1;
    }
	char* name_img = malloc(sizeof(char)*strlen(argv[1]) + 30);
	char* name_simplifier = malloc(sizeof(char)*strlen(argv[1]) + 30);
    strcpy(name_img,"../IMAGES_PERFORMANCE/");
    strcat(name_img,argv[1]);
    strcat(name_img,".pbm");
    strcpy(name_simplifier,"../RESULTATS/");
    strcat(name_simplifier,argv[1]);

    int d;
    sscanf(argv[2], "%d", &d);

    if (strcmp("s",argv[3])==0) {
        //mode segment

        strcat(name_simplifier,"_segment_d=");
        strcat(name_simplifier,argv[2]);
        strcat(name_simplifier,".eps");
        tester_image_segment(name_img, name_simplifier, d);
    }else{
        printf("pas encore inplementé");
    }

    return 0;
}

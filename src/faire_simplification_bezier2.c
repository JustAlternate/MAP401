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

void tester_image(char* nom_entree, char* nom_sortie, int d){
    printf("simplification Bezier2: %s -> %s\n", nom_entree, nom_sortie);

    Image img = lire_fichier_image(nom_entree);

    Liste_Contour * LC_cont = recherche_tous_les_contours(img);
    Dessin_Bezier2 *Dessin_d1 = simplification_Bezier2(LC_cont, d);
    
    int nombre_bezier2 = nombre_Bezier2_dans_Dessin(*Dessin_d1);
    printf("Nombre de Bézier : %d \n",nombre_bezier2);

    enregister_dessin_Bezier2_vers_EPS(Dessin_d1, nom_sortie, img.la_largeur_de_l_image, img.la_hauteur_de_l_image);

    supprimer_Dessin_Bezier2(*Dessin_d1);
    supprimer_liste_Contour(*LC_cont);
    supprimer_image(&img);
}

int main(int argc, char** argv){

    if (argc != 4){
        printf("usage: nom_image.pbm nom_image_resultat distance_seuil\n");
        return 1;
    }
    char str1[100] = "../IMAGES_TEST/";
    strcat(str1,argv[1]);
    char str2[100] = "../RESULTATS/";
    strcat(str2,argv[2]);

    int d;
    sscanf(argv[3], "%d", &d);

    tester_image(str1, str2, d);

    return 0;
}

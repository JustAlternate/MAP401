#include <stdio.h>

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

    enregister_dessin_Bezier2_vers_EPS(Dessin_d1, nom_sortie, img.la_largeur_de_l_image, img.la_hauteur_de_l_image);

    supprimer_Dessin_Bezier2(*Dessin_d1);
    supprimer_liste_Contour(*LC_cont);
    supprimer_image(&img);
}

int main(int argc, char** argv){
    tester_image("../IMAGES_TEST/caractere2.pbm", "../RESULTATS/caractere2_douglas_peucker", 1);
    tester_image("../IMAGES_TEST/arbre.pbm", "../RESULTATS/arbre_douglas_peucker", 1);
    tester_image("../IMAGES_TEST/animaux.pbm", "../RESULTATS/animaux_douglas_peucker", 1);
    tester_image("../IMAGES_TEST/Charlot.pbm", "../RESULTATS/Charlot_douglas_peucker", 1);
    tester_image("../IMAGES_TEST/drowning-girl.pbm", "../RESULTATS/drowning-girl_douglas_peucker", 1);
    tester_image("../IMAGES_TEST/lettre-L-cursive.pbm", "../RESULTATS/lettre-L-cursive_douglas_peucker", 1);
    /*
    jeu_de_test();
    generation_resultats_tache6();
/
    if (argc != 7){
        printf("Usage: ./test_simplification_contour P.x P.y A.x A.y B.x B.y\n");
        return 1;
    }
    Point P = nouveau_point(atof(argv[1]),atof(argv[2]));
    Point A = nouveau_point(atof(argv[3]),atof(argv[4]));
    Point B = nouveau_point(atof(argv[5]),atof(argv[6]));


    double resultat = distance_point_segment(P, A, B);
    printf("distance_point_segment = %f \n",resultat);
*/
    return 0;
}

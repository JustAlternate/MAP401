#include <stdio.h>

#include "geometrie.h"
#include "types_macros.h"
#include "image.h"
#include "contour.h"
#include "sequence_point.h"
#include "sequence_bezier2.h"
#include "simplification_bezier2.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define RESET_COLOR        "\x1B[0m"

//foncyions pratiques:
void afficher_resultat_test(int b){
    if (b){
        printf("%sSUCCESS%s\n", ANSI_COLOR_GREEN, RESET_COLOR);
    }
    else{
        printf("%sFAILED%s\n", ANSI_COLOR_RED, RESET_COLOR);
    }
}

void tester_image(char* nom){
	Image img = lire_fichier_image(nom);
	Liste_Contour * LC_cont = recherche_tous_les_contours(img);
    Dessin_Bezier2 *Dessin_d1 = simplification_Bezier2(LC_cont, 1);
    Dessin_Bezier2 *Dessin_d2 = simplification_Bezier2(LC_cont, 2);
    print_Dessin_Bezier2(Dessin_d1);
    print_Dessin_Bezier2(Dessin_d2);
}

int main(int argc, char** argv){
    tester_image("../IMAGES_TEST/caractere2.pbm");
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

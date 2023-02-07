#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include "geometrie.h"
#include "sequence_point.h"
#include "contour.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define RESET_COLOR        "\x1B[0m"

//foncyions pratiques:
void afficher_resultat_test(int b){
    if (b){
        printf(" %s SUCCESS%s\n", ANSI_COLOR_GREEN, RESET_COLOR);
    }
    else{
        printf(" %s FAILED%s\n", ANSI_COLOR_RED, RESET_COLOR);
    }
}

void test_trouver_pixel_depart(){
	printf("Test fonction trouver_pixel_depart : \n");
	printf("Test 1/2\n");
	// On va vérifier que le point trouver sur l'image contour_simple.pbm est bien en x=3, y=2
	Image contour_simple = lire_fichier_image("contour_simple.pbm");
	Point p = trouver_pixel_depart(contour_simple);
	afficher_resultat_test(p.x == 3.0 && p.y == 2.0);

	printf("Test 2/2\n");
	// On va vérifier qu'une image sans aucun point noir retourne un point 0,0
	Image test = creer_image(10,10);
	Point p2 = trouver_pixel_depart(test);
	afficher_resultat_test(p2.x == 0 && p2.y == 0);

	printf("Test 3/3\n");
	// On va vérifier qu'une image entierement noir retourne bien le premier point (1,1)
	Image negatif_test = negatif_image(test);
	Point p3 = trouver_pixel_depart(negatif_test);
	afficher_resultat_test(p3.x == 1 && p3.y == 1);
}
void test_recherche_contour(){
	printf("Test fonction recherche_contour : \n");
	printf("Test 1/3\n");
	// On va verifier que la liste des points pour l'image contour_simple.pbm est la bonne
	printf("Sur l'image : contour_simple.pbm\n");
	Image contour_simple = lire_fichier_image("contour_simple.pbm");
	Point p = trouver_pixel_depart(contour_simple);
	Contour Cont = recherche_contour(p,contour_simple);
	print_liste_Point(Cont);

	printf("Test 2/3\n");
	// On va verifier que la liste des points pour l'image contour_tres_simple.pbm est la bonne
	printf("Sur l'image : contour_tres_simple.pbm\n");
	Image contour_tres_simple = lire_fichier_image("contour_tres_simple.pbm");
	Point p2 = trouver_pixel_depart(contour_tres_simple);
	Contour Cont2 = recherche_contour(p2,contour_tres_simple);
	print_liste_Point(Cont2);

	printf("Test 3/3\n");
	// On va verifier que la liste des points pour l'image .pbm est la bonne
	printf("Sur l'image : contour_tres_tres_simple.pbm\n");
	Image contour_tres_tres_simple = lire_fichier_image("contour_tres_tres_simple.pbm");
	Point p3 = trouver_pixel_depart(contour_tres_tres_simple);
	Contour Cont3 = recherche_contour(p3,contour_tres_tres_simple);
	print_liste_Point(Cont3);
}

int main(int argc, char** argv){
	test_trouver_pixel_depart();
	test_recherche_contour();
}
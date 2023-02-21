#include <stdio.h>
#include <string.h>

#include "EPS.h"
#include "contour.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_ORANGE  "\033[93m"
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

void test_init_fichier_eps(void){
    char nom[100] = "test_EPS1";
    char read[100];
    printf("Test fonction init_fichier_eps\n");

    printf("Test 1/2\n");
    FILE *f = init_fichier_eps(nom, 0, 0, 10, 10);
    fclose(f);
    FILE *f2 = fopen("test_EPS1.eps", "r");
    if (f2 == NULL){
        afficher_resultat_test( /*false*/ 0);
    }
    fgets(read, 100, f2);
    afficher_resultat_test(0 == strcmp(read, "%!PS-Adobe-3.0 EPSF-3.0\n"));

    printf("Test 2/2\n");
    fgets(read, 100, f2);
    afficher_resultat_test(0 == strcmp(read, "%BoundingBox: 0 0 10 10\n"));
}

void test_dessiner_ligne(){
    char nom[100] = "test_EPS2";
    char read[100];
    char read2[100];
    printf("Test fonction dessiner_ligne\n");
    FILE *f = init_fichier_eps(nom, 0, 0, 10, 10);
    dessiner_ligne(f, 0, 0, 10, 10, 1, 0, 0, 0, 1.5);
    dessiner_ligne(f, 0, 0, 0, 0, 0, 0, 0, 0, 0.);
    fclose(f);
    FILE *f3 = init_fichier_eps("test_EPS3", 0, 0, 100, 100);
    dessiner_ligne(f, 100, 0, 0, 100, 1, 0, 1, 1, 1.5);
    fclose(f3);

    FILE *f2 = fopen("test_EPS2.eps", "r");
    if (f2 == NULL){
        afficher_resultat_test( /*false*/ 0);
    }
    fgets(read, 100, f2);// les deux 
    fgets(read, 100, f2);// premières lignes

    printf("Test 1/3\n");
    fgets(read, 100, f2);
    fgets(read2, 100, f2);
    afficher_resultat_test((0 == strcmp(read, "0 0 moveto 10 10 lineto\n") )&&( 0 == strcmp(read2,"0 0 0 setrgbcolor 1.5 setlinewidth\n")));

    printf("Test 2/3\n");
    fgets(read, 100, f2);
    fgets(read2, 100, f2);
    afficher_resultat_test((0 == strcmp(read, "0 0 moveto 0 0 lineto\n") )&&( 0 == strcmp(read2,"0 0 0 setrgbcolor 0.0 setlinewidth\n")));

    FILE *f4 = fopen("test_EPS3.eps", "r");
    if (f4 == NULL){
        afficher_resultat_test( /*false*/ 0);
    }
    fgets(read, 100, f4);// les deux 
    fgets(read2, 100, f4);// premières lignes
    printf("Test 3/3\n");
    fgets(read, 100, f4);
    fgets(read2, 100, f4);
    afficher_resultat_test((0 == strcmp(read, "100 0 moveto 0 100 lineto\n")) && (0 == strcmp(read2, "0 1 1 setrgbcolor 1.5 setlinewidth\n")));
}

void tout_faire(char *nom, int sf){
	char* nom_pbm = malloc(sizeof(char)*strlen(nom) + 100);
	char* nom2 = malloc(sizeof(char)*strlen(nom) + 100);
	strcpy(nom_pbm,"IMAGES_TACHE3/");
	strcat(nom_pbm,nom);
    strcpy(nom2, nom);
    strcat(nom_pbm, ".pbm");
    Image contour_simple = lire_fichier_image(nom_pbm);
    Point p = trouver_pixel_depart(contour_simple);
    Contour Cont = recherche_contour(p,contour_simple);
    FILE* f = init_fichier_eps(nom2,0,0,largeur_image(contour_simple),hauteur_image(contour_simple));
    dessiner_contour(Cont,f,sf,0,0,0,1.);
    fclose(f);
}

void test_dessiner_contour(){
    printf("Test fonction dessiner_contour\n");
    printf("Test 1/2\n");
    printf("%sA VERIFIER SOI-MEME%s\n", ANSI_COLOR_ORANGE, RESET_COLOR);
    Image contour_simple = lire_fichier_image("contour_simple.pbm");
    Point p = trouver_pixel_depart(contour_simple);
    Contour Cont = recherche_contour(p,contour_simple);
    FILE* f = init_fichier_eps("test_EPS4",0,0,largeur_image(contour_simple),hauteur_image(contour_simple));
    dessiner_contour(Cont,f,0,1,0,0,1.);
    fclose(f);

    printf("Test 2/2\n");
    printf("%sA VERIFIER SOI-MEME%s\n", ANSI_COLOR_ORANGE, RESET_COLOR);
    f = init_fichier_eps("test_EPS5",0,0,largeur_image(contour_simple),hauteur_image(contour_simple));
    dessiner_contour(Cont,f,1,1,0,0,1.);
    fclose(f);

    printf("exportation des images du CR\n");
    tout_faire("chat", 0);
    tout_faire("image_ex_poly", 0);
    tout_faire("coq", 1);
    tout_faire("elephant", 1);
    tout_faire("gymnaste", 1);
    tout_faire("labyrinthe", 1);
    tout_faire("lettreZ", 1);
    tout_faire("map401", 1);
    tout_faire("tete", 1);
}

int main(int argc, char** argv){
    test_init_fichier_eps();
    test_dessiner_ligne();
    test_dessiner_contour();
}

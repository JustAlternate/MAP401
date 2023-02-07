#include <stdio.h>

#include "EPS.h"
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


void test_init_fichier_eps(void){
    char nom[100] = "test_EPS1";
    char read[100];
    printf("tests de init_fichier_eps\n");

    printf("test première ligne\n");
    FILE *f = init_fichier_eps(nom, 0, 0, 100, 100);
    fclose(f);
    FILE *f2 = fopen("test_EPS1.eps", "r");
    if (f2 == NULL){
        afficher_resultat_test( /*false*/ 0);
    }
    fgets(read, 100, f2);
    afficher_resultat_test(0 == strcmp(read, "%!PS-Adobe-3.0 EPSF-3.0\n"));

    printf("test deuxième ligne\n");
    fgets(read, 100, f2);
    afficher_resultat_test(0 == strcmp(read, "%BoundingBox: 0 0 100 100\n"));
}

void test_dessiner_ligne(){
    char nom[100] = "test_EPS2";
    char read[100];
    char read2[100];
    printf("tests de dessiner_ligne\n");
    FILE *f = init_fichier_eps(nom, 0, 0, 100, 100);
    dessiner_ligne(f, 5, 5, 10, 10, 1, 0, 0, 0, 1.5);
    dessiner_ligne(f, 0, 0, 0, 0, 0, 0, 0, 0, 0.);
    dessiner_ligne(f, 5, 5, 10, 10, 1, 0, 0, 0, 1.5);
    fclose(f);

    FILE *f2 = fopen("test_EPS2.eps", "r");
    if (f2 == NULL){
        afficher_resultat_test( /*false*/ 0);
    }
    fgets(read, 100, f2);// les deux 
    fgets(read, 100, f2);// premières lignes

    printf("test ligne ((5,5),(10,10)) noir strock 1.5 d'epaisseure dans une boite de 0,0,100,100\n");
    fgets(read, 100, f2);
    fgets(read2, 100, f2);
    afficher_resultat_test((0 == strcmp(read, "5 5 moveto 10 10 lineto\n") )&&( 0 == strcmp(read2,"0 0 0 setrgbcolor 1.500000 setlinewidth stroke\n")));
}

int main(int argc, char** argv){
    test_init_fichier_eps();
    test_dessiner_ligne();
    //test_dessiner_contour();
}
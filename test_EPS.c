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
    FILE *f = init_fichier_eps(nom, 0, 0, 100, 100);
    fclose(f);
    FILE *f2 = fopen("test_EPS1.eps", "r");
    if (f2 == NULL){
        afficher_resultat_test( /*false*/ 0);
    }
    printf("%s",fgets(read, 100, f2));
}


int main(int argc, char** argv){
    test_init_fichier_eps();
}
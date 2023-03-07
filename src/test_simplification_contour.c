#include <stdio.h>

#include "geometrie.h"
#include "types_macros.h"

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

void jeu_de_test(){
    printf("Test simplification contour");
    printf("Test 1/10");
    afficher_resultat_test(distance_point_segment(nouveau_point(0,0), nouveau_point(0,0), nouveau_point(0,0)) == 0); //P = A = B = (0,0)
    
    printf("Test 2/10");
    afficher_resultat_test(distance_point_segment(nouveau_point(0.5,0), nouveau_point(0,0), nouveau_point(1,0)) == 0); // P = milieu(A,B)
    
    printf("Test 3/10");
    afficher_resultat_test(distance_point_segment(nouveau_point(3.5,3.5), nouveau_point(5,2), nouveau_point(2,5)) == 0); // P = milieu(A,B)
    
    printf("Test 4/10");
    afficher_resultat_test(distance_point_segment(nouveau_point(5,8), nouveau_point(5,8), nouveau_point(5,0)) == 0); // P = A
    
    printf("Test 5/10");
    afficher_resultat_test(distance_point_segment(nouveau_point(5,8), nouveau_point(5,0), nouveau_point(5,8)) == 0); // P = B
    
    printf("Test 6/10");
    afficher_resultat_test(distance_point_segment(nouveau_point(5,11), nouveau_point(5,0), nouveau_point(5,10)) == 1); // P ∈ droite(A,B)
    
    printf("Test 7/10");
    afficher_resultat_test(distance_point_segment(nouveau_point(5,-1), nouveau_point(5,0), nouveau_point(5,10)) == 1); // P ∈ droite(A,B)
    
    printf("Test 8/10");
    afficher_resultat_test(distance_point_segment(nouveau_point(7,8), nouveau_point(5,0), nouveau_point(5,10)) == 2); // 0 < λ < 1

    printf("Test 9/10");
    afficher_resultat_test(distance_point_segment(nouveau_point(8,14), nouveau_point(5,5), nouveau_point(5,10)) == 5); // 1 < λ

    printf("Test 10/10");
    afficher_resultat_test(distance_point_segment(nouveau_point(1,2), nouveau_point(5,5), nouveau_point(5,10)) == 5); // 1 < λ




}

int main(int argc, char** argv){

    jeu_de_test();

    if (argc != 7){
        printf("Usage: ./test_simplification_contour P.x P.y A.x A.y B.x B.y\n");
        return 1;
    }
    Point P = nouveau_point(atof(argv[1]),atof(argv[2]));
    Point A = nouveau_point(atof(argv[3]),atof(argv[4]));
    Point B = nouveau_point(atof(argv[5]),atof(argv[6]));

    double resultat = distance_point_segment(P, A, B);
    printf("distance_point_segment = %f \n",resultat);



    return 0;
}

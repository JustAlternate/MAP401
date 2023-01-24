#include <stdio.h>

#include "geometrie.h"
#include "types_macros.h"

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

int egale_vecteur(Vecteur v1, Vecteur v2){
    return v1.x == v2.x && v1.y == v2.y;
}

int egale_point(Point p1, Point p2){
    return p1.x == p2.x && p1.y == p2.y;
}

//fonctions de test
void test_nouveau_point(){
    printf("Test fonction nouveau_point\n");
    
    printf("Test 1/3");
    Point p = nouveau_point(0, 0);
    afficher_resultat_test((p.x == 0 && p.y == 0));

    printf("Test 2/3");
    Point p1 = nouveau_point(5, 27.5);
    Point p2 = nouveau_point(5, 27.5);
    afficher_resultat_test((p1.x == p2.x && p1.y == p2.y));

    printf("Test 3/3");
    p = nouveau_point(-315.648135, 74535.1);
    afficher_resultat_test((p.x == -315.648135 && p.y == 74535.1));
}
void test_nouveau_vecteur(){
    printf("Test fonction nouveau_vecteur\n");
    
    printf("Test 1/3");
    Vecteur v = nouveau_vecteur(0, 0);
    afficher_resultat_test((v.x == 0 && v.y == 0));

    printf("Test 2/3");
    Vecteur v1 = nouveau_vecteur(5, 27.5);
    Vecteur v2 = nouveau_vecteur(5, 27.5);
    afficher_resultat_test((v1.x == v2.x && v1.y == v2.y));

    printf("Test 3/3");
    v = nouveau_vecteur(-315.648135, 74535.1);
    afficher_resultat_test((v.x == -315.648135 && v.y == 74535.1));
}

void test_point_to_vecteur(){
    printf("Test fonction point_to_vecteur\n");
    
    printf("Test 1/3");
    Point p = nouveau_point(0, 0);
    Vecteur v = point_to_vecteur(p);
    afficher_resultat_test((v.x == 0 && v.y == 0));

    printf("Test 2/3");
    Point p1 = nouveau_point(5, 27.5);
    Point p2 = nouveau_point(5, 27.5);
    Vecteur v1 = point_to_vecteur(p1);
    Vecteur v2 = point_to_vecteur(p2);
    afficher_resultat_test((v1.x == v2.x && v1.y == v2.y));

    printf("Test 3/3");
    p = nouveau_point(-315.648135, 74535.1);
    v = point_to_vecteur(p);
    afficher_resultat_test((v.x == -315.648135 && v.y == 74535.1));
}

void test_vecteur_to_point(){
    printf("Test fonction vecteur_to_point\n");
    
    printf("Test 1/3");
    Vecteur v = nouveau_vecteur(0, 0);
    Point p = vecteur_to_point(v);
    afficher_resultat_test((p.x == 0 && p.y == 0));

    printf("Test 2/3");
    Vecteur v1 = nouveau_vecteur(5, 27.5);
    Vecteur v2 = nouveau_vecteur(5, 27.5);
    Point p1 = vecteur_to_point(v1);
    Point p2 = vecteur_to_point(v2);
    afficher_resultat_test((p1.x == p2.x && p1.y == p2.y));

    printf("Test 3/3");
    v = nouveau_vecteur(-315.648135, 74535.1);
    p = vecteur_to_point(v);
    afficher_resultat_test((p.x == -315.648135 && p.y == 74535.1));
}

void test_couple_point_to_vecteur(){
    printf("Test fonction couple_point_to_vecteur\n");
    
    printf("Test 1/3");
    afficher_resultat_test(egale_vecteur(couple_point_to_vecteur(nouveau_point(0,0),nouveau_point(5,5)), nouveau_vecteur(5,5)));

    
    printf("Test 2/3");
    afficher_resultat_test(egale_vecteur(couple_point_to_vecteur(nouveau_point(5,5),nouveau_point(0,0)), nouveau_vecteur(-5,-5)));


    printf("Test 3/3");
    afficher_resultat_test(egale_vecteur(couple_point_to_vecteur(nouveau_point(0,0),nouveau_point(0.25,2)), couple_point_to_vecteur(nouveau_point(-0.25,-2),nouveau_point(0,0))));
}

void test_addition_vecteur(){
    printf("Test fonction addition_vecteur\n");
    
    printf("Test 1/3");
    afficher_resultat_test(egale_vecteur(addition_vecteur(nouveau_vecteur(0,0),nouveau_vecteur(5,5)), nouveau_vecteur(5,5)));

    
    printf("Test 2/3");
    afficher_resultat_test(egale_vecteur(addition_vecteur(nouveau_vecteur(-5,5),nouveau_vecteur(2,-8)), nouveau_vecteur(-3,-3)));


    printf("Test 3/3");// v1+v2 == v2+v1
    afficher_resultat_test(egale_vecteur(addition_vecteur(nouveau_vecteur(5,2.5),nouveau_vecteur(0.25,2)), addition_vecteur(nouveau_vecteur(0.25,2),nouveau_vecteur(5,2.5))));
}



int main(int argc, char** argv){
    test_nouveau_point();
    test_nouveau_vecteur();
    test_point_to_vecteur();
    test_vecteur_to_point();
    test_couple_point_to_vecteur();
    test_addition_vecteur();
    return 1;
}
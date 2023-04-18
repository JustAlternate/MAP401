#include <stdio.h>

#include "bezier.h"
#include "simplification_bezier2.h"
#include "geometrie.h"
#include "sequence_point.h"
#include "types_macros.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define RESET_COLOR        "\x1B[0m"

//fonctions pratiques:
void afficher_resultat_test(int b){
    if (b){
        printf(" %s SUCCESS%s\n", ANSI_COLOR_GREEN, RESET_COLOR);
    }
    else{
        printf(" %s FAILED%s\n", ANSI_COLOR_RED, RESET_COLOR);
    }
}

void test_distance_point_bezier2(){
    // On va verifier que la fonction donne les meme valeurs que dans l'exemple page 51.
    printf("Fonction distance_point_bezier2()\n");
    printf("Test 1/2\n");

    Bezier2 bez = init_bezier2(nouveau_point(0,0),nouveau_point(1.547619,2.452381),nouveau_point(5,3));

    // Les points sur lequels on va tester la fonction distance_point_courbe_bezier2
    Point tab[] = {nouveau_point(0,0),nouveau_point(1,0),nouveau_point(1,1),nouveau_point(1,2),
                  nouveau_point(2,2),nouveau_point(3,2),nouveau_point(3,3),nouveau_point(4,3),
                  nouveau_point(5,3)};

    for (int i = 0; i < 9; i++){
        printf("Distance : %lf \n", distance_point_courbe_bezier2(tab[i], bez, i/8.0));
        Point Pegual = applique_bezier2_point(bez, i/8.0);
        printf("On applique la courbe au point : B2(%lf)=(%lf,%lf)\n",i/8.0,Pegual.x,Pegual.y);

    }
}

void test_approx_bezier2(){    
    // On va verifier que la fonction donne les meme valeurs que dans l'exemple page 50.
    printf("Fonction approx_bezier2()\n");
    printf("Test 2/2\n");

    Liste_Point LP = creer_liste_Point();
    ajouter_element_liste_Point(&LP, nouveau_point(0,0));
    ajouter_element_liste_Point(&LP, nouveau_point(1,0));
    ajouter_element_liste_Point(&LP, nouveau_point(1,1));
    ajouter_element_liste_Point(&LP, nouveau_point(1,2));
    ajouter_element_liste_Point(&LP, nouveau_point(2,2));
    ajouter_element_liste_Point(&LP, nouveau_point(3,2));
    ajouter_element_liste_Point(&LP, nouveau_point(3,3));
    ajouter_element_liste_Point(&LP, nouveau_point(4,3));
    ajouter_element_liste_Point(&LP, nouveau_point(5,3));

    Bezier2 bez = approx_bezier2(LP.first, LP.last, LP.taille-1);
    
    printf("C0 : (%lf.%lf)\n",bez.C0.x, bez.C0.y); 
    printf("C1 : (%lf.%lf)\n",bez.C1.x, bez.C1.y); 
    printf("C2 : (%lf.%lf)\n",bez.C2.x, bez.C2.y); 
    
    print_Bezier2(bez);
    printf("\n");
}

int main(int argc, char** argv){
    test_distance_point_bezier2();
    test_approx_bezier2();
    return 0;
}

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
        printf("%sSUCCESS%s\n", ANSI_COLOR_GREEN, RESET_COLOR);
    }
    else{
        printf("%sFAILED%s\n", ANSI_COLOR_RED, RESET_COLOR);
    }
}

int environ_egual(double val_calcule, double val_reele){

    return (val_calcule > val_reele - 0.0001 && val_calcule < val_reele + 0.0001);
}

void test_distance_point_bezier2(){
    // On va verifier que la fonction donne les meme valeurs que dans l'exemple page 51.
    printf("Fonction distance_point_bezier2()\n");

    printf("Test 1/2\n");

    printf("On test sur l'exemple page 51\n");
    Bezier2 bez = init_bezier2(nouveau_point(0,0),nouveau_point(1.547619,2.452381),nouveau_point(5,3));

    // Les points sur lequels on va tester la fonction distance_point_courbe_bezier2
    Point tab[] = {nouveau_point(0,0),nouveau_point(1,0),nouveau_point(1,1),nouveau_point(1,2),
                  nouveau_point(2,2),nouveau_point(3,2),nouveau_point(3,3),nouveau_point(4,3),
                  nouveau_point(5,3)};

    // Les distances que l'on doit obtenir selon l'exemple page 51.
    double tab_res[] = {0.0,0.824958,0.151523,0.606091,0.033672,0.454569,0.555584,0.235702,0.0};

    for (int i = 0; i < 9; i++){
        double distance = distance_point_courbe_bezier2(tab[i], bez, i/8.0);
        printf("Distance : %lf  ",distance);
        afficher_resultat_test(environ_egual(distance,tab_res[i]));
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
    
    print_Bezier2(bez);

    printf("\nC0 : (%lf.%lf)\n",bez.C0.x, bez.C0.y); 
    afficher_resultat_test(environ_egual(bez.C0.x,0.0) && (environ_egual(bez.C0.y, 0.0)));
    printf("C1 : (%lf.%lf)\n",bez.C1.x, bez.C1.y); 
    afficher_resultat_test(environ_egual(bez.C1.x,1.547619) && (environ_egual(bez.C1.y, 2.452381)));
    printf("C2 : (%lf.%lf)\n",bez.C2.x, bez.C2.y); 
    afficher_resultat_test(environ_egual(bez.C2.x,5.0) && (environ_egual(bez.C2.y, 3.0)));
    printf("\n");
}

int main(int argc, char** argv){
    test_distance_point_bezier2();
    test_approx_bezier2();
    return 0;
}

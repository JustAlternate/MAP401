#include <stdio.h>

#include "image.h"
#include "types_macros.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define RESET_COLOR        "\x1B[0m"

int test_creer_image(){
    printf("Test fonction creer_image\n");
    printf("Test 1/3");
    Image img_10_10 = creer_image(10,10);
    if (img_10_10.la_largeur_de_l_image == 10){
	printf(" %s SUCCESS%s\n",ANSI_COLOR_GREEN,RESET_COLOR);
    }else{
	printf(" %s FAILED%s\n",ANSI_COLOR_RED,RESET_COLOR);
	return 1;
    }
    printf("Test 2/3");
    if (img_10_10.la_hauteur_de_l_image == 10){
	printf(" %s SUCCESS%s\n",ANSI_COLOR_GREEN,RESET_COLOR);
    }else{
	printf(" %s FAILED%s\n",ANSI_COLOR_RED,RESET_COLOR);
	return 1;
    }
    
    printf("Test 3/3");
    if (img_10_10.pointeur_vers_le_tableau_de_pixels != NULL){
	printf(" %s SUCCESS%s\n",ANSI_COLOR_GREEN,RESET_COLOR);
    }else{
	printf(" %s FAILED%s\n",ANSI_COLOR_RED,RESET_COLOR);
	return 1;
    }
    return 0;

}

int test_supprimer_image(){
    printf("Test fonction supprimer_image\n");
    printf("Test 1/1");

    Image img_10_10 = creer_image(10,10);
    Image *p_I = &img_10_10;
    supprimer_image(p_I);

    if (p_I == NULL){
	printf(" %s SUCCESS%s\n",ANSI_COLOR_GREEN,RESET_COLOR);
    }else{
	printf(" %s FAILED%s\n",ANSI_COLOR_RED,RESET_COLOR);
	return 1;
    }
    return 0;
}



void test_module_img(char* fname){

    
    printf("Lancement des ");
    printf("%stests%s",ANSI_COLOR_GREEN,RESET_COLOR);
    printf(" du module image...\n");

    if (test_creer_image()){
	fprintf(stderr,"%sIl y a eu une erreur dans les tests de la fonction creer_image()%s\n",ANSI_COLOR_RED,RESET_COLOR);
    }else{
	printf("%sla fonction creer_image() est fonctionnelle.%s\n",ANSI_COLOR_GREEN,RESET_COLOR);
    }
    if (test_supprimer_image()){
	fprintf(stderr,"%sIl y a eu une erreur dans les tests de la fonction supprimer_image()%s\n",ANSI_COLOR_RED,RESET_COLOR);
    }else{
	printf("%sla fonction supprimer_image() est fonctionnelle.%s\n",ANSI_COLOR_GREEN,RESET_COLOR);
    }



}




int main(int argc, char** argv){


    test_module_img(argv[1]);

    /*
    if (argc != 2){
	fprintf(stderr, "Usage: donner un nom de fichier\n");
	return 1;
    }

    Image img = lire_fichier_image(argv[1]);

    ecrire_image(img);

    ecrire_image(negatif_image(img));

    */
    return 0;
}

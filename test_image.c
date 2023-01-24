#include <stdio.h>
#include <dirent.h>
#include <string.h>

#include "image.h"
#include "types_macros.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define RESET_COLOR        "\x1B[0m"

int test_creer_image(){
    printf("Test fonction creer_image :\n");

    printf("Test 1/3");
    // On verifie bien que creer_image creer bien une image avec la bonne largeur
    Image img_10_10 = creer_image(10,10);
    if (img_10_10.la_largeur_de_l_image == 10){
	printf(" %s SUCCESS%s\n",ANSI_COLOR_GREEN,RESET_COLOR);
    }else{
	printf(" %s FAILED%s\n",ANSI_COLOR_RED,RESET_COLOR);
	return 1;
    }
    printf("Test 2/3");
    // On verifie bien que creer_image creer bien une image avec la bonne hauteur
    if (img_10_10.la_hauteur_de_l_image == 10){
	printf(" %s SUCCESS%s\n",ANSI_COLOR_GREEN,RESET_COLOR);
    }else{
	printf(" %s FAILED%s\n",ANSI_COLOR_RED,RESET_COLOR);
	return 1;
    }
    
    printf("Test 3/3");
    // On verifie bien que creer_image creer bien un tableau non null
    if (img_10_10.pointeur_vers_le_tableau_de_pixels != NULL){
	printf(" %s SUCCESS%s\n",ANSI_COLOR_GREEN,RESET_COLOR);
    }else{
	printf(" %s FAILED%s\n",ANSI_COLOR_RED,RESET_COLOR);
	return 1;
    }
    return 0;

}

int test_get_pixel_image(){
    printf("Test fonction get_pixel_image :\n");

    printf("Test 1/3");
    // On essaye de prendre un pixel du tableau qui est blanc

    Image img_10_10 = creer_image(10,10);
    Image *p_I = &img_10_10;
    Pixel* tab = p_I->pointeur_vers_le_tableau_de_pixels;

    if (get_pixel_image(img_10_10,1,1) == BLANC){
	printf(" %s SUCCESS%s\n",ANSI_COLOR_GREEN,RESET_COLOR);
    }else{
	printf(" %s FAILED%s\n",ANSI_COLOR_RED,RESET_COLOR);
	return 1;
    }

    printf("Test 2/3");
    // On essaye de prendre un pixel du tableau qui est noir

    tab[0] = 1;

    if (get_pixel_image(img_10_10,1,1) == NOIR){
	printf(" %s SUCCESS%s\n",ANSI_COLOR_GREEN,RESET_COLOR);
    }else{
	printf(" %s FAILED%s\n",ANSI_COLOR_RED,RESET_COLOR);
	return 1;
    }

    printf("Test 3/3");
    // On essaye de prendre un pixel qui est en dehors du tableau (qui doit etre blanc)

    if (get_pixel_image(img_10_10,10,2123123123) == BLANC){
	printf(" %s SUCCESS%s\n",ANSI_COLOR_GREEN,RESET_COLOR);
    }else{
	printf(" %s FAILED%s\n",ANSI_COLOR_RED,RESET_COLOR);
	return 1;
    }

    return 0;
}


int test_set_pixel_image(){
    printf("Test fonction set_pixel_image : \n");

    Image img_1_1 = creer_image(1,1);

    printf("Test 1/3");
    // Test changer un pixel en noir
    set_pixel_image(img_1_1,1,1,NOIR);

    if (get_pixel_image(img_1_1,1,1) == NOIR){
	printf(" %s SUCCESS%s\n",ANSI_COLOR_GREEN,RESET_COLOR);
    }else{
	printf(" %s FAILED%s\n",ANSI_COLOR_RED,RESET_COLOR);
	return 1;
    }

    printf("Test 2/3");
    // Test changer un pixel en blanc
    set_pixel_image(img_1_1,1,1,BLANC);

    if (get_pixel_image(img_1_1,1,1) == BLANC){
	printf(" %s SUCCESS%s\n",ANSI_COLOR_GREEN,RESET_COLOR);
    }else{
	printf(" %s FAILED%s\n",ANSI_COLOR_RED,RESET_COLOR);
	return 1;
    }

    printf("Test 3/3");
    // Test changer un pixel en dehors de l'image (doit ne rien faire)
    set_pixel_image(img_1_1,9,9,NOIR);

    if (get_pixel_image(img_1_1,9,9) == BLANC && get_pixel_image(img_1_1,1,1) == BLANC){
	printf(" %s SUCCESS%s\n",ANSI_COLOR_GREEN,RESET_COLOR);
    }else{
	printf(" %s FAILED%s\n",ANSI_COLOR_RED,RESET_COLOR);
	return 1;
    }

    return 0;
}

int test_largeur_image(){
    printf("Test fonction largeur_image : \n");


    printf("Test 1/3");
    Image img_3_3 = creer_image(3,3);

    if (largeur_image(img_3_3) == 3) {
	printf(" %s SUCCESS%s\n",ANSI_COLOR_GREEN,RESET_COLOR);
    }else{
	printf(" %s FAILED%s\n",ANSI_COLOR_RED,RESET_COLOR);
	return 1;
    }
    printf("Test 2/3");
    Image img_0_0 = creer_image(0,0);

    if (largeur_image(img_0_0) == 0) {
	printf(" %s SUCCESS%s\n",ANSI_COLOR_GREEN,RESET_COLOR);
    }else{
	printf(" %s FAILED%s\n",ANSI_COLOR_RED,RESET_COLOR);
	return 1;
    }
    printf("Test 3/3");
    Image img_26_1 = creer_image(26,1);

    if (largeur_image(img_26_1) == 26) {
	printf(" %s SUCCESS%s\n",ANSI_COLOR_GREEN,RESET_COLOR);
    }else{
	printf(" %s FAILED%s\n",ANSI_COLOR_RED,RESET_COLOR);
	return 1;
    }
    return 0;
}

int test_hauteur_image(){
    printf("Test fonction hauteur_image : \n");

    printf("Test 1/3");
    Image img_3_3 = creer_image(3,3);

    if (hauteur_image(img_3_3) == 3) {
	printf(" %s SUCCESS%s\n",ANSI_COLOR_GREEN,RESET_COLOR);
    }else{
	printf(" %s FAILED%s\n",ANSI_COLOR_RED,RESET_COLOR);
	return 1;
    }
    printf("Test 2/3");
    Image img_0_0 = creer_image(0,0);

    if (hauteur_image(img_0_0) == 0) {
	printf(" %s SUCCESS%s\n",ANSI_COLOR_GREEN,RESET_COLOR);
    }else{
	printf(" %s FAILED%s\n",ANSI_COLOR_RED,RESET_COLOR);
	return 1;
    }
    printf("Test 3/3");
    Image img_26_1 = creer_image(26,1);

    if (hauteur_image(img_26_1) == 1) {
	printf(" %s SUCCESS%s\n",ANSI_COLOR_GREEN,RESET_COLOR);
    }else{
	printf(" %s FAILED%s\n",ANSI_COLOR_RED,RESET_COLOR);
	return 1;
    }
    return 0;
}


int test_lire_fichier_image(){


    printf("Test fonction lire_fichier_image : \n");

    struct dirent *de;  // Pointer for directory entry
  
    DIR *dr = opendir("IMAGES_TEST");
  
    if (dr == NULL)  // opendir returns NULL if couldn't open directory
    {
        printf("Could not open current directory" );
        return 1;
    }
  
    char name[50];
    while ((de = readdir(dr)) != NULL){ // J'ai aucune idée de ce qu'est cette magie noir de boucle while, jai copié sur internet je voulais juste une fonction qui me lister la liste des fichier dans un repertoire.
	if ((strcmp(de->d_name,".")!= 0) && (strcmp(de->d_name,"..") !=0)){
	    printf("Test sur l'image %s\n",de->d_name);
	    strcpy(name,"IMAGES_TEST/");
	    strcat(name,de->d_name);
	    Image img = lire_fichier_image(name); 
	    supprimer_image(&img);
	}
    }
  
    closedir(dr);  

    return 0;
}

void test_module_img(){

    
    printf("Lancement des ");
    printf("%stests%s",ANSI_COLOR_GREEN,RESET_COLOR);
    printf(" du module image...\n");

    if (test_creer_image()){
	fprintf(stderr,"%sIl y a eu une erreur dans les tests de la fonction creer_image()%s\n",ANSI_COLOR_RED,RESET_COLOR);
    }else{
	printf("%sla fonction creer_image() est fonctionnelle.%s\n",ANSI_COLOR_GREEN,RESET_COLOR);
    }
    if (test_get_pixel_image()){
	fprintf(stderr,"%sIl y a eu une erreur dans les tests de la fonction get_pixel_image()%s\n",ANSI_COLOR_RED,RESET_COLOR);
    }else{
	printf("%sla fonction get_pixel_image() est fonctionnelle.%s\n",ANSI_COLOR_GREEN,RESET_COLOR);
    }
    if (test_set_pixel_image()){
	fprintf(stderr,"%sIl y a eu une erreur dans les tests de la fonction set_pixel_image()%s\n",ANSI_COLOR_RED,RESET_COLOR);
    }else{
	printf("%sla fonction set_pixel_image() est fonctionnelle.%s\n",ANSI_COLOR_GREEN,RESET_COLOR);
    }
    if (test_largeur_image()){
	fprintf(stderr,"%sIl y a eu une erreur dans les tests de la fonction largeur_image()%s\n",ANSI_COLOR_RED,RESET_COLOR);
    }else{
	printf("%sla fonction largeur_image() est fonctionnelle.%s\n",ANSI_COLOR_GREEN,RESET_COLOR);
    }
    if (test_hauteur_image()){
	fprintf(stderr,"%sIl y a eu une erreur dans les tests de la fonction hauteur_image()%s\n",ANSI_COLOR_RED,RESET_COLOR);
    }else{
	printf("%sla fonction hauteur_image() est fonctionnelle.%s\n",ANSI_COLOR_GREEN,RESET_COLOR);
    }
    if (test_lire_fichier_image()){
	fprintf(stderr,"%sIl y a eu une erreur dans les tests de la fonction lire_fichier_image()%s\n",ANSI_COLOR_RED,RESET_COLOR);
    }else{
	printf("%sla fonction lire_fichier_image() est fonctionnelle.%s\n",ANSI_COLOR_GREEN,RESET_COLOR);
    }



}




int main(int argc, char** argv){

    test_module_img();

    return 0;
}

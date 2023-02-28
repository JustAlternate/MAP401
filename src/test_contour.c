#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include "image.h"
#include "geometrie.h"
#include "sequence_point.h"
#include "contour.h"
#include "types_macros.h"

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

void test_trouver_pixel_depart(){
	printf("Test fonction trouver_pixel_depart : \n");
	printf("Test 1/2\n");
	// On va vérifier que le point trouver sur l'image contour_simple.pbm est bien en x=3, y=2
	Image contour_simple = lire_fichier_image("../IMAGES_TEST/contour_simple.pbm");
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
	printf("Test 1/4\n");
	// On va verifier que la liste des points pour l'image contour_simple.pbm est la bonne
	printf("Sur l'image : contour_simple.pbm\n");
	Image contour_simple = lire_fichier_image("../IMAGES_TEST/contour_simple.pbm");
	Point p = trouver_pixel_depart(contour_simple);
	Contour Cont = recherche_contour(p,contour_simple);
	print_liste_Point(Cont);

	printf("Test 2/4\n");
	// On va verifier que la liste des points pour l'image contour_tres_simple.pbm est la bonne
	printf("Sur l'image : contour_tres_simple.pbm\n");
	Image contour_tres_simple = lire_fichier_image("../IMAGES_TEST/contour_tres_simple.pbm");
	Point p2 = trouver_pixel_depart(contour_tres_simple);
	Contour Cont2 = recherche_contour(p2,contour_tres_simple);
	print_liste_Point(Cont2);

	printf("Test 3/4\n");
	// On va verifier que la liste des points pour l'image .pbm est la bonne
	printf("Sur l'image : contour_tres_tres_simple.pbm\n");
	Image contour_tres_tres_simple = lire_fichier_image("../IMAGES_TEST/contour_tres_tres_simple.pbm");
	Point p3 = trouver_pixel_depart(contour_tres_tres_simple);
	Contour Cont3 = recherche_contour(p3,contour_tres_tres_simple);
	print_liste_Point(Cont3);

	printf("Test 4/4\n");
	// On va verifier que la liste des points pour l'image .pbm est la bonne
	printf("Sur l'image : contour_dur.pbm\n");
	Image contour_dur = lire_fichier_image("../IMAGES_TEST/contour_dur.pbm");
	Point p4 = trouver_pixel_depart(contour_dur);
	Contour Cont4 = recherche_contour(p4,contour_dur);
	print_liste_Point(Cont4);    
}

int generation_resultats_tache3(){
    printf("Generation du fichier resultat_tach3 dans RESULTATS/\n");
    struct dirent *de;  // Pointer for directory entry
  
    DIR *dr = opendir("../IMAGES_TACHE3");
  
    if (dr == NULL)  // opendir returns NULL if couldn't open directory
    {
        printf("Could not open current directory" );
        return 1;
    }
  
    char name[50];

    FILE* f = fopen("../RESULTATS/resultats-tache3-2.txt","w"); 

    int L,H;
    Contour CT;
    int nb_segments;
    while ((de = readdir(dr)) != NULL){ // J'ai aucune idée de ce qu'est cette magie noir de boucle while, jai copié sur internet je voulais juste une fonction qui me lister la liste des fichier dans un repertoire.
	if ((strcmp(de->d_name,".")!= 0) && (strcmp(de->d_name,"..") !=0)){
	    printf("Test sur l'image %s",de->d_name);
	    strcpy(name,"../IMAGES_TACHE3/");
	    strcat(name,de->d_name);
	    Image img = lire_fichier_image(name); 
	    L = largeur_image(img);
	    H = hauteur_image(img);
	    CT = recherche_contour(trouver_pixel_depart(img),img);
	    nb_segments = nombre_segments(CT);
	    fprintf(f,"%s: L=%d H=%d, nb_segment=%d\n",de->d_name,L,H,nb_segments);
	    printf(" %sA VERIF SOIT MEME%s\n",ANSI_COLOR_ORANGE,RESET_COLOR);
	}
    }
  
    closedir(dr);  
    fclose(f);
    return 1;

}

void test_recherche_tous_les_contours(){
    printf("on passe sur tous les contours\n");
    Image img = lire_fichier_image("../IMAGES_TEST/contour_simple.pbm");
    Liste_Contour LC = recherche_tous_les_contours(img);
    print_liste_Contour(LC);
}

int main(int argc, char** argv){
	test_trouver_pixel_depart();
	test_recherche_contour();
	generation_resultats_tache3();
	test_recherche_tous_les_contours();
}

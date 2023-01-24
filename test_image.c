#include <stdio.h>

#include "image.h"
#include "types_macros.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"

int main(int argc, char** argv){

	if (argc != 2){
		fprintf(stderr, "Usage: donner un nom de fichier\n");
		return 1;
	}

	Image img = lire_fichier_image(argv[1]);

	ecrire_image(img);

	ecrire_image(negatif_image(img));
	
	return 0;
}

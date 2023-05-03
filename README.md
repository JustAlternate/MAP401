# MAP401

Ceci est notre projet logiciel de map401 "Vectorisation et simplificatin d'image bitmap"
Dans ce projet vous retrouverer des simplifications par contour, par courbes de bezier de degrée 2 et de la generation d'images PostScript.

# Installation

`git clone https://github.com/JustAlternate/MAP401`


# Architecture du Projet

- divers : Les pdf de compte rendu des différentes taches et suivi de projet.  
- IMAGES_PERFORMANCE : L'ensemble des images de test pour la tache 8.  
- IMAGES_TACHE3 : L'ensemble des images de la tache 3.  
- IMAGES_TACHE5 : L'ensemble des images de la tache 5.  
- IMAGES_TEST : L'ensemble de toutes les images pbm.  
- RESULTATS : Dossier dans lequel on met automatiquement toutes les images générées et resultats textes 
- scripts : des fichiers bash qui execute des programmes c de notre projet.
- src : L'ensemble de nos fichiers .c .h et executable ainsi que notre Makefile.

# Comment utiliser le projet

Pour générer tout les executables :  

1) placer vous dans le dossier src  
2) faites `make clear`  
3) puis `make`  

Maintenant que tous les executables ont été créer, vous pouvez maintenant executer soit a la main un par un tous les fichiers de test (les fichiers executable qui commence par test_\*)
Ou bien vous pouvez le faire automatique en faisant `make tests`  

`make tests` execute les fichiers suivants :

- ~~test_image~~ : test le paquetage de la tache1 (faite le a la main `./test_image`)
- test_geometrie
- test_contour
- test_EPS
- test_bezier
- test_simplification_contour
- test_simplification_bezier2 


4) Aller dans le dossier RESULTATS pour regarder que tout a bien était générée correctement.

Cette branche est actuellement à jour avec la branche tache8.

Pour trouver une tache précisement changer de branche.

Exemple : git switch tache3
pour acceder a la tache 3.


# Travail dans chaque tache

## Tache 1

Completion du packetage image : écriture des fonctions ecrire_image et negatif_image.
Note : Pour la fonction negatif(Image) nous avons decidé d'utiliser une formule arithmetique plutot que d'utiliser un if pour savoir si le pixel est noir ou blanc et apres le changer.

Test du module image : nous testons toutes les fonctions du module image même celles que nous n'avons pas implémenté nous même. 
Le programme test_image.c lance 2 ou 3 tests sur TOUTES les fonctions du module image.
De plus ce programme test les 2 fonctions 'ecrire_image' et 'negatif_image' sur toutes les images du dossier IMAGES_TEST



## Tache 2

Paquetage geometrie 2D:

Pour le paquetage geometrie nous avons décidé d'enregistrer les types Point et Vecteur sous forme de struct et de ne pas utiliser de pointeurs dans les fonctions. Les pointeurs complexifiraient trop le code pour un bénéfice inexistant ou négligeable. Nous avons implémenté toutes les fonctions géométriques expliqués dans le cours.

Nous tenons à faire remarquer que nous ne nous sommes pas servis de l'implémentation des vecteurs lors du reste du projet. A moins que l'exercice d'implémentation vous semble intérressant (elle ne diffère que très peu de l'implementation des points), je propose que l'implémentation des vecteurs ne soit plus requise l'année prochaine.


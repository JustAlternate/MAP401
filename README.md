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

- ~~test_image~~ : test le paquetage de la tache1 (faite le a la main `./test_image`).  
- test_geometrie : test le paquetage de la tache2.  
- test_contour : test notre implémentation des contour en liste chainée.  
- test_EPS : test notre conversion dans le format EPS.  
- test_bezier : test notre implémentation des courbes de bezier. (fonctions "distance_point_bezier2", "approx_bezier2")  
- test_simplification_contour : test les fonctions "distance_point_segment", genere aussi les resultats de la tache6.  
- test_simplification_bezier2 : test les fonctions "simplification_bezier2" en generant les images resultats de la tache7.  

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






## Tache 7

**Paquetage bezier :**

Ce paquetage represente simplement toute les fonctions qui sont utilisé pour manipuler des courbes de bezier.

**Paquetage test_bezier :**

Test les focntion distance_point_courbe_bezier2 avec l'exemple page 51 du poly ainsi que la fonction approx_bezier2 de la page 50 du poly.

**Paquetage sequence_bezier2 :**

Dans celui-çi on a réimplémenter toutes les structures de données de pour notre courbe de bézier.  
On a donc inventé les structure Motif et Dessin.  
Un Motif est une liste chainée contenant des cellules pointant vers des courbes de bézier2.  
Un Dessin est une liste chainée contenant des cellules pointant vers des Motif.  

**Paquetage simplification_bezier2 :**

Dans ce fichier, on a implémenter la fonction simplification_douglas_peucker_Bezier2 avec des liste chainée. Celle çi nous renvoie un Motif_Bezier2.

**Paquetage test_simplification_bezier2 :**

Ce genere les resultats pour la tache 7 partie 1.
(Elle test donc la fonction douglas_peucker avec d = 1, 3, 10 et 30)

**Paquetage faire_simplification_bezier2 :**

fichier pour generer des images EPS, prend en arguments un nom de fichier, un nom de sortie et une distance seuil, et applique donc la simplification par courbe de bezier2 sur cette image.

## Tache 8

**Paquetage test_performance :**

Dans ce paquetage nous avons créer une commande qui prend un nom de fichier, une distance seuil et la méthode pour simplifier. Et génère l'image EPS equivalente avec la simplification demandées. ainsi que les statistiques equivalente (nombre de contours et segments de l'image d'origine et nombre de segments de l'image simplifiée.)

**Paquetage génération_tache8_part2.sh :**

Qui prend les noms d'images qui sont dans le fichier fichiers_performance.txt et les simplifie automatique en segments et en bézier avec une distance seuil = [0, 0.5, 1, 2, 4, 8, 16]

Au final en comparant les différentes images générées on peut remarquer plusieur choses :

- Il semblerait que notre projet soit assez bien optimisée car notre plus grosse image test prend 8 secondes a simplifier.

- On remarque aussi que la simplification par courbe de bezier semble plus efficace que celle par segments. On a des images simplifiée plus proche de l'image réel, et avec moins d'éléments.



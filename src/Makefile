#############################################################################
# Fichier Makefile 
# UE MAP401 - DLST - UGA - 2020/2021
#############################################################################
# utilisation des variables internes $@ $< $^ $*
# $@ : correspond au nom de la cible
# $< : correspond au nom de la premiere dependance
# $^ : correspond � toutes les d�pendances
# $* : correspond au nom du fichier sans extension 
#       (dans les regles generiques uniquement)
#############################################################################
# information sur la regle executee avec la commande @echo
# (une commande commancant par @ n'est pas affichee a l'ecran)
#############################################################################


#############################################################################
# definition des variables locales
#############################################################################

# compilateur C
CC = clang

# chemin d'acces aux librairies (interfaces)
INCDIR = .

# chemin d'acces aux librairies (binaires)
LIBDIR = .

# options pour l'�dition des liens
LDOPTS = -L$(LIBDIR) -lm

# options pour la recherche des fichiers .o et .h
INCLUDEOPTS = -I$(INCDIR)

# options de compilation
COMPILOPTS = -g -Wall $(INCLUDEOPTS)

# liste des executables
EXECUTABLES = test_image test_geometrie test_contour test_EPS


#############################################################################
# definition des regles
#############################################################################

########################################################
# la r�gle par d�faut
all : $(EXECUTABLES)

########################################################
# regle generique : 
#  remplace les regles de compilation separee de la forme
#	module.o : module.c module.h
#		$(CC) -c $(COMPILOPTS) module.c
%.o : %.c %.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module "$*
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

########################################################
# regles explicites de compilation separee de modules
# n'ayant pas de fichier .h ET/OU dependant d'autres modules
image.o : image.c image.h types_macros.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module image"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_image.o : test_image.c image.h 
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_image"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

geometrie.o : geometrie.c geometrie.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module geometrie"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_geometrie.o : test_geometrie.c geometrie.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_geometrie"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

sequence_point.o : sequence_point.c sequence_point.h geometrie.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module sequence_point"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<


contour.o : contour.c contour.h image.h geometrie.h sequence_point.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module contour"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<
		

test_contour.o : test_contour.c contour.h sequence_point.h geometrie.h image.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_contour"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

EPS.o : EPS.c EPS.h contour.h geometrie.h image.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_contour"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_EPS.o : test_EPS.c EPS.h contour.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_contour"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<	
########################################################
# regles explicites de creation des executables

test_image : test_image.o image.o 
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

test_geometrie : test_geometrie.o geometrie.o 
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@


test_contour : test_contour.o contour.o sequence_point.o geometrie.o image.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

test_EPS : test_EPS.o EPS.o image.o geometrie.o contour.o sequence_point.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

tests:
	@echo "---------------------------------------------"
	@echo "Lancement du make all"
	@echo "---------------------------------------------"
	@sleep 5
	make all
	@echo "---------------------------------------------"
	@echo "Lancement test_image"
	@echo "---------------------------------------------"
	@sleep 5
	#./test_image
	@echo "---------------------------------------------"
	@echo "Lancement test_geometrie"
	@echo "---------------------------------------------"
	@sleep 5
	./test_geometrie
	@echo "---------------------------------------------"
	@echo "Lancement test_contour"
	@echo "---------------------------------------------"
	@sleep 5
	./test_contour
	@echo "---------------------------------------------"
	@echo "Lancement test_EPS"
	@echo "---------------------------------------------"
	@sleep 5
	./test_EPS

# regle pour "nettoyer" le r�pertoire
clean:
	rm -fR $(EXECUTABLES) *.o *.eps ../RESULTATS/*.o.eps ../RESULTATS/*.contours ../RESULTATS/*.contours
clear:
	rm -fR $(EXECUTABLES) *.o *.eps ../RESULTATS/*.o.eps ../RESULTATS/*.contours ../RESULTATS/*.contours

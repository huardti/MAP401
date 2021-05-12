#############################################################################
# Fichier Makefile 
# UE MAP401 - DLST - UGA - 2019/2020
#############################################################################
# utilisation des variables internes $< $@ $*
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
COMPILOPTS = -g -Wall -Wextra $(INCLUDEOPTS)

# liste des executables
EXECUTABLES = main test_geom


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
geom2d.o : geom2d.c geom2d.h 
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module geom2d"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<
contour_image.o : contour_image.c contour_image.h image.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module contour_image"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<
option.o : option.c option.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module option"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<
tab_variable.o : tab_variable.c tab_variable.h 
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module tab_variable"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<
mod_eps.o : mod_eps.c mod_eps.h 
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module mod_eps"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<
simplification.o:simplification.c simplification.h geom2d.h tab_variable.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module simplification"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<


test_image.o : test_image.c image.h 
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_image"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<
test_geom.o : test_geom.c geom2d.h tab_variable.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module geom2d"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<
main.o: main.c contour_image.h image.h geom2d.h simplification.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_image"
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
test_geom : test_geom.o geom2d.o tab_variable.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

main : contour_image.o geom2d.o image.o option.o tab_variable.o mod_eps.o simplification.o main.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

# regle pour "nettoyer" le r�pertoire
clean:
	rm -fR $(EXECUTABLES) *.o 


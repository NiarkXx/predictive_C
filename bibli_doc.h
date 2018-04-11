/**

Recherche de mot dans un dictionnaire

Bibliothèque créée par Ludovic Barbier

ISMIN 1A 

2017-2018

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define Taille_dic 22740
#define Taille_max 30

typedef struct _Mot
{
	char lemot[Taille_max];
	struct _Mot *suiv;
	struct _Mot *prec;
}Mot;

Mot** creation();
unsigned long long hachage(char monmot[Taille_max]);
void insertion(Mot **tab, char monmot[Taille_max]);
Mot** lecture_fichier();
void recherche(Mot **tab, char motatrouver[Taille_max]);
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
unsigned long long hachage(char monmot[Taille_max], int n);
void insertion(Mot **tab, char monmot[Taille_max], int n);
Mot** lecture_fichier(int n);
Mot* recherche(Mot **tab, char motatrouver[Taille_max], int n);
Mot* recherche_2eme(Mot **tab, char motatrouver[Taille_max], int n, char mot1[Taille_max]);
Mot* recherche_3eme(Mot **tab, char motatrouver[Taille_max], int n, char mot1[Taille_max], char mot2[Taille_max]);
bool recherche_mot(Mot **tab, char motatrouver[Taille_max], int n);
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

#define Taille_dic_pred 22740
#define Taille_max_pred 30

typedef struct _Motpred
{
	char lemot[Taille_max_pred];
	int occur;
	struct _Motpred *suiv;
	struct _Motpred *prec;
}Motpred;

Motpred** creationpred();
unsigned long long hachagepred(char monmot[Taille_max_pred], int n);
void insertionpred(Motpred **tab, char monmot[Taille_max_pred], int occurance, int n);
Motpred** lecture_fichier_pred(int n);
Motpred* recherche_pred(Motpred **tab, char motatrouver[Taille_max_pred], int n);
Motpred* recherche_pour_ajout(Motpred **tab, char motatrouver[Taille_max_pred], int n);
Motpred* recherche_2eme_pred(Motpred **tab, char motatrouver[Taille_max_pred], int n, char mot1[Taille_max_pred]);
Motpred* recherche_3eme_pred(Motpred **tab, char motatrouver[Taille_max_pred], int n, char mot1[Taille_max_pred], char mot2[Taille_max_pred]);
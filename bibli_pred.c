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


Motpred** creationpred()
{
	int i;
	Motpred **tab;
	tab = (Motpred **) malloc(Taille_dic_pred*sizeof(Motpred*));
	for (i=0; i<Taille_dic_pred; i++)
	{
		tab[i] = (Motpred *) malloc(sizeof(Motpred));
	}
	return tab;
}

unsigned long long hachagepred(char monmot[Taille_max_pred], int n)
{
	unsigned long long hach;
	hach = 0;
	int i=0;
	while (monmot[i] != '\0' && i<n)
	{
		hach = hach + monmot[i]*(128^i);
		i++;
	}
	hach = hach % Taille_dic_pred;
	return hach;
}

void insertionpred(Motpred **tab, char monmot[Taille_max_pred], int occurance, int n)
{
	unsigned long long placement = hachagepred(monmot, n);
	Motpred *maillon = malloc(sizeof(Motpred));
	strcpy(maillon -> lemot, monmot);
	maillon -> occur = occurance; 
	Motpred *ptr = tab[placement];
	while (ptr -> suiv != NULL)
	{
		ptr = ptr -> suiv;
	}
	ptr -> suiv = maillon;
	maillon -> prec = ptr;
}

Motpred** lecture_fichier_pred(int n)
{
	Motpred **tab = creationpred();
	FILE *fp = fopen("dictionnaire.txt", "r");
	char monmot[Taille_max_pred];
	int occurance;
	while (fscanf(fp, "%s %d\n", monmot, &occurance) != EOF)
	{	
		insertionpred(tab, monmot, occurance, n);
	}
	return tab;
}

Motpred* recherche_pour_ajout(Motpred **tab, char motatrouver[Taille_max_pred], int n)
{
	int trouve = 0;
	unsigned long long placement = hachagepred(motatrouver, n);
	Motpred* ptr = tab[placement];
	while (ptr != NULL && trouve != 1)
	{
		if (strcmp(ptr -> lemot, motatrouver) == 0)
		{
			trouve = 1;
			ptr -> occur++;
		}
		ptr = ptr -> suiv;
	}
	ptr = tab[placement];
	if (trouve != 1)
	{
		Motpred *maillon = malloc(sizeof(Motpred));
		strcpy(maillon -> lemot, motatrouver);
		while (ptr -> suiv != NULL)
		{
			ptr = ptr -> suiv;
		}
		ptr -> suiv = maillon;
		maillon -> prec = ptr;
	}
}



Motpred* recherche_pred(Motpred **tab, char motatrouver[Taille_max_pred], int n)
{
	int trouve = 0;
	unsigned long long placement = hachagepred(motatrouver, n);
	Motpred* ptr = tab[placement];
	while (ptr != NULL && trouve != 1)
	{
		if (strcmp(ptr -> lemot, motatrouver) == 0)
		{
			trouve = 1;
		}
		ptr = ptr -> suiv;
	}
	if (trouve == 1)
	{
		return ptr -> prec;
	}
	else 
	{
		return NULL;
	}
}

Motpred* recherche_2eme_pred(Motpred **tab, char motatrouver[Taille_max_pred], int n, char mot1[Taille_max_pred])
{
	int trouve = 0;
	unsigned long long placement = hachagepred(motatrouver, n);
	Motpred* ptr = tab[placement];
	while (ptr != NULL && trouve != 1)
	{
		if (strncmp(ptr -> lemot, motatrouver, n) == 0 && strcmp(ptr->lemot, mot1)!=0)
		{
			trouve = 1;
		}
		ptr = ptr -> suiv;
	}
	if (trouve == 1)
	{
		return ptr -> prec;
	}
	else 
	{
		return NULL;
	}
}

Motpred* recherche_3eme_pred(Motpred **tab, char motatrouver[Taille_max_pred], int n, char mot1[Taille_max_pred], char mot2[Taille_max_pred])
{
	int trouve = 0;
	unsigned long long placement = hachage(motatrouver, n);
	Motpred* ptr = tab[placement];
	while (ptr != NULL && trouve != 1)
	{
		if (strncmp(ptr -> lemot, motatrouver, n) == 0 && strcmp(ptr->lemot, mot1)!=0 && strcmp(ptr->lemot, mot2)!=0)
		{
			trouve = 1;
		}
		ptr = ptr -> suiv;
	}
	if (trouve == 1)
	{
		return ptr -> prec;
	}
	else 
	{
		return NULL;
	}
}
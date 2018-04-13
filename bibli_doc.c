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

Mot** creation()
{
	int i;
	Mot **tab;
	tab = (Mot **) malloc(Taille_dic*sizeof(Mot*));
	for (i=0; i<Taille_dic; i++)
	{
		tab[i] = (Mot *) malloc(sizeof(Mot));
	}
	return tab;
}



unsigned long long hachage(char monmot[Taille_max], int n)
{
	unsigned long long hach;
	hach = 0;
	int i=0;
	while (monmot[i] != '\0' && i<n)
	{
		hach = hach + monmot[i]*(128^i);
		i++;
	}
	hach = hach % Taille_dic;
	return hach;
}

void insertion(Mot **tab, char monmot[Taille_max], int n)
{
	unsigned long long placement = hachage(monmot, n);
	Mot *maillon = malloc(sizeof(Mot));
	strcpy(maillon -> lemot, monmot);
	Mot *ptr = tab[placement];
	while (ptr -> suiv != NULL)
	{
		ptr = ptr -> suiv;
	}
	ptr -> suiv = maillon;
	maillon -> prec = ptr;
}



Mot** lecture_fichier(int n)
{
	Mot **tab = creation();
	FILE *fp = fopen("french_dic.txt", "r");
	char monmot[Taille_max];
	while (fscanf(fp, "%s \n", monmot) != EOF)
	{
		insertion(tab, monmot, n);
	}
	return tab;
}

Mot* recherche(Mot **tab, char motatrouver[Taille_max], int n)
{
	int trouve = 0;
	unsigned long long placement = hachage(motatrouver, n);
	Mot* ptr = tab[placement];
	while (ptr != NULL && trouve != 1)
	{
		if (strncmp(ptr -> lemot, motatrouver, n) == 0)
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

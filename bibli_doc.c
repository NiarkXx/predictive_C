/**

Recherche de mot dans un dictionnaire

Bibliothèque créée par Ludovic Barbier

ISMIN 1A

2017-2018

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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



unsigned long long hachage(char monmot[Taille_max])
{
	unsigned long long hach;
	hach = 0;
	int i=0;
	while (monmot[i] != '\0')
	{
		hach = hach + monmot[i]*(128^i);
		i++;
	}
	hach = hach % Taille_dic;
	return hach;
}

void insertion(Mot **tab, char monmot[Taille_max])
{
	unsigned long long placement = hachage(monmot);
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



Mot** lecture_fichier()
{
	Mot **tab = creation();
	FILE *fp = fopen("dictionnaire.txt", "r");
	char monmot[Taille_max];
	while (fscanf(fp, "%s \n", monmot) != EOF)
	{
		insertion(tab, monmot);
	}
	return tab;
}

void recherche(Mot **tab, char motatrouver[Taille_max])
{
	int trouve = 0;
	unsigned long long placement = hachage(motatrouver);
	Mot* ptr = tab[placement];
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
		printf("Le mot est dans le dictionnaire \n");
	}
	else
	{
		printf("Le mot n'est pas dans le dictionnaire \n");
	}
}

void ecritureFichier(char string[])
{
	FILE *file=fopen("dictionnaire.txt","w");


	if (file!=NULL) {


	}
	printf("Error : Can't read the file\n");
	fclose(file);
}

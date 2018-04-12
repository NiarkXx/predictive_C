#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 300
#define MAX_LENGTH_WORD 30

int main(int argc, char const *argv[])
{
	// char c;
	// while(c != '\n') 
	// {
 //    c=getchar();
 //    putchar (c);
	// }
	char tab[] = "Bonjour";
	printf("%d \n", strlen(tab));
	strcpy(tab, " ");
	tab[0]='\0';
	printf("%d \n", strlen(tab));
	tab[0]='a';
	printf("%d \n", strlen(tab));
	return 0;
}


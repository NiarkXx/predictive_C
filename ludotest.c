#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 300
#define MAX_LENGTH_WORD 30
void writeWordIntoDic(char word_to_add[MAX_LENGTH_WORD]);
void initArray(char *array);
void insertion_dic(char sentence[MAX_LENGTH]);

int main(int argc, char const *argv[])
{
	// char c;
	// while(c != '\n') 
	// {
 //    c=getchar();
 //    putchar (c);
	// }
	// char tab[] = "Bonjour";
	// printf("%d \n", strlen(tab));
	// strcpy(tab, " ");
	// tab[0]='\0';
	// printf("%d \n", strlen(tab));
	// tab[0]='a';
	// printf("%d \n", strlen(tab));
	insertion_dic("abris abribus arbre airbus");
	return 0;
}

void writeWordIntoDic(char word_to_add[MAX_LENGTH_WORD])
{
 FILE *file = fopen("dictionnaire.txt","r+");
 int cursor = 0;
 char word_dic[MAX_LENGTH_WORD];
 FILE *fileCopy = fopen("dictionnaire_tmp.txt","w+");
 bool done = false;
 int occurence = 1;
 int removeTest;
 int renameTest;

 if (file != NULL && fileCopy != NULL) {
        rewind(file);
        if (fgetc(file) == EOF) {
            fprintf(fileCopy, "%s %d\n", word_to_add, 1);
        }
        else {
            rewind(file);
            initArray(word_dic);
            while(fscanf(file, "%s %d\n", word_dic, &occurence)==2)
            {
               if(!done)
               {
                    if(strcmp(word_dic,word_to_add)==0)
                    {
                         occurence++;
                         fprintf(fileCopy,"%s %d\n",word_dic, occurence);
                         done=true;
                    }
                    else if(strcmp(word_dic,word_to_add)<0)
                    {
                         fprintf(fileCopy, "%s %d\n",word_dic,occurence );
                    }
                    else
                    {
                         fprintf(fileCopy,"%s %d\n",word_to_add,1);
                         fprintf(fileCopy,"%s %d\n",word_dic,occurence);
                         done=true;
                    }
               }
               else
               {
                    fprintf(fileCopy,"%s %d\n",word_dic,occurence);
               }
            }
            if(!done)
            {
               fprintf(fileCopy,"%s %d\n",word_to_add,1);
            }
            
        }

    } else
        printf("Error : Can't open the file");

    fclose(file);
    fclose(fileCopy);


    removeTest = remove("dictionnaire.txt");
    if (removeTest != 0)
        printf("Error to remove the file");

    renameTest = rename("dictionnaire_tmp.txt", "dictionnaire.txt");

    if (renameTest != 0) {
        printf("Error to rename");

    }
}

void insertion_dic(char sentence[MAX_LENGTH])
{
  int i = 0;
  int j = 0;
  char word[MAX_LENGTH_WORD];
  initArray(word);
  while(sentence[i] != '\0')
  {
    if(sentence[i] == ' ')
    {
      writeWordIntoDic(word);
      initArray(word);
      j = 0;
    }
    else  
    {
      word[j] = sentence[i];
      j++;
    }
      i++;

  }
  if(word[0]!='\0')
  {
  	writeWordIntoDic(word);
  }

}

void initArray(char *array)
{
    for (int i=0;i<MAX_LENGTH_WORD;i++)
        array[i]='\0';
}
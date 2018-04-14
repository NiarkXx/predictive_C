#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <termios.h>
#include <assert.h>
#include <unistd.h>
#include "bibli_doc.h"
#include "bibli_pred.h"

//----------------- CONSTANTS -----------------

#define MAX_LENGTH 300
#define MAX_LENGTH_WORD 30
#define clear() printf("\033[H\033[J")


//----------------- STRUCTURES -----------------



//----------------- PROTOTYPES -----------------
void menu(void);
void typeSMSPredictive(void);
void typeSMSNonPredictive(void);
void selectMode(void);
void cleanBuffer(void);
void writeWordIntoDic(char string[Taille_max_pred]);
int getch(void);
void insertion_dic(char sentence[MAX_LENGTH]);
void initArray(char *array);

//----------------- GLOBALS -----------------


bool enablePredictive = false;
char smsArray[MAX_LENGTH];
char currentWord[MAX_LENGTH_WORD];


//----------------- MAIN -----------------
int main(int argc, char const *argv[]) {

    Motpred *mon_mot = (Motpred *)malloc(sizeof(Motpred));
    strcpy(mon_mot -> lemot, "avion");
    mon_mot -> occur = 2;
    Mot* mot2 = (Mot *)mon_mot;
    printf("%s\n", mot2->lemot);
    free(mot2);

     //menu();


     return 0;
}

//----------------- FUNCTIONS -----------------

void menu()
{
     int input=0;
     bool quit=false;
     while(quit == false)
     {
          clear();
          printf("\n\nPredictive Text Simulation \n" );
          printf("---------------------------------\n");
          printf("1) Enable/Disable Predictive Text. ( Currently : " );

          if(enablePredictive ==true)
               printf("TRUE )\n" );
          else
               printf("FALSE )\n" );

          printf("2) Type a SMS\n" );
          printf("3) Quit\n" );
          scanf("%d",&input );

          switch (input) {

               case 1:
               enablePredictive= !enablePredictive;
               break;

               case 2:
               selectMode();
               break;
               case 3:
               quit=true;
               break;
          }
     }
}

void typeSMSNonPredictive()
{
     char inputText[MAX_LENGTH];

     printf("Type your text : \n" );
// cleanBuffer();
//readInput(inputText);
}


void selectMode()
{
     if (enablePredictive) {
          typeSMSPredictive();
          printf("\n \ntypeSMSPredictive\n" );
     }
     else
          typeSMSNonPredictive();
}

void typeSMSPredictive()
{
     Mot** dico = (Mot **)malloc(sizeof(Mot*));
     clear();
     cleanBuffer();
     int input=0;
     char saisie;
     char *wordAfter;
     bool vide;
     Mot* word1 = (Mot *)malloc(sizeof(Mot));
     Mot* word2 = (Mot *)malloc(sizeof(Mot));
     Mot* word3 = (Mot *)malloc(sizeof(Mot));
     do
     {
          clear();
          printf("Type your SMS\n");
          if(vide)
          {
               printf("%s ", smsArray);
               saisie = getch();
          }
          else
          {
               
               printf("1) %s 2) %s 3) %s\n", word1->lemot, word2->lemot, word3->lemot);
// printf("Word 1 Word 2 Word 3\n");
               printf("%s ", smsArray);
               printf("%s", currentWord);
               saisie = getch();
          }

          if(saisie == ' ')
          {
               if(!vide)
               {
                    free(dico);
               }
               strcat(smsArray, " ");
               strcat(smsArray, currentWord);
               strcpy(currentWord, " ");
               currentWord[0]='\0';
               vide = true;
          }
          else if(saisie == '/')
          {
               if(!vide)
               {
                    free(dico);
               }
               scanf("%d",&input );
               cleanBuffer();
               switch (input) {
                    case 1:
                    strcat(smsArray, " ");
                    strcat(smsArray, word1->lemot);
                    strcpy(currentWord, " ");
                    currentWord[0]='\0';
                    vide = true;
                    break;
                    case 2:
                    strcat(smsArray, " ");
                    strcat(smsArray, word2->lemot);
                    strcpy(currentWord, " ");
                    currentWord[0]='\0';
                    vide = true;
                    break;
                    case 3:
                    strcat(smsArray, " ");
                    strcat(smsArray, word3->lemot);
                    strcpy(currentWord, " ");
                    currentWord[0]='\0';
                    vide = true;
                    break;
                    default:
                    printf("ERROR\n");
                    break;
               }
          }
          else if(saisie != '\n' && vide)
          {
               if(!vide)
               {
                    free(dico);
               }
               currentWord[0] = saisie;
               vide = false;
          }
          else if(saisie != '\n')
          {
               if(!vide)
               {
                    free(dico);
               }
               strcat(currentWord, &saisie);
          }
     }while(saisie != '\n');

     free(word1);
     free(word2);
     free(word3);

     strcat(smsArray, " ");
     strcat(smsArray, currentWord);

     insertion_dic(smsArray);

     strcpy(currentWord, " ");
     currentWord[0]='\0';
     strcpy(smsArray, " ");
     smsArray[0]='\0';
}

void cleanBuffer(void)
{
     int c=0;
     while(c !='\n' && c!=EOF)
     {
          c=getchar();
     }
}

int getch(void) {
     int c=0;

     struct termios org_opts, new_opts;
     int res=0;
//-----  store old settings -----------
     res=tcgetattr(STDIN_FILENO, &org_opts);
     assert(res==0);
//---- set new terminal parms --------
     memcpy(&new_opts, &org_opts, sizeof(new_opts));
     new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL);
     tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
     c=getchar();
//------  restore old settings ---------
     res=tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);
     assert(res==0);
     return(c);
}

void writeWordIntoDic(char word_to_add[MAX_LENGTH_WORD])
{
     FILE *file = fopen("dictionnaire.txt","r+");
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
               while(fscanf(file, "%s %d", word_dic, &occurence)==2)
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
     int i = 1;
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

void proposition_3_words(Motpred* word1, Motpred* word2, Motpred* word3)
{
  int compteur_mot = 0;
  dico = lecture_fichier_pred(strlen(currentWord));
  word1 =  recherche_pred(dico, currentWord, strlen(currentWord)) ;
  if(word1 == NULL)
  {
    dico = lecture_fichier(strlen(currentWord));
  }
  else
  {
    compteur_mot = 1;
    word2 = recherche_2eme_pred(dico, currentWord, strlen(currentWord), word1->lemot);
    if(word2 != NULL)
    {
      compteur_mot = 2;
      word3 = recherche_3eme(dico, currentWord, strlen(currentWord), word1->lemot, word2->lemot);
      if(word3 != NULL)
      {
        compteur_mot = 3;
      }
    }
    else
    {
      dico = lecture_fichier(strlen(currentWord));
      word2 = recherche_2eme(dico, currentWord, strlen(currentWord), word1 -> lemot);
    }
  }
  if(word1 != NULL && word2!=NULL)
  {
    compteur_mot = 2;
    word3 = recherche_3eme(dico, currentWord, strlen(currentWord), word1->lemot, word2->lemot);
  }
  else
  {
    word3 = NULL;
  }
  if(word3 != NULL && word1!= NULL && word2 != NULL)
  {
    compteur_mot = 3;
  }
}
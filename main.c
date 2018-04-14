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

    // Motpred *mon_mot = (Motpred *)malloc(sizeof(Motpred));
    // strcpy(mon_mot -> lemot, "avion");
    // mon_mot -> occur = 2;
    // Mot* mot2 = (Mot *)mon_mot;
    // printf("%s\n", mot2->lemot);
    // free(mot2);

     menu();


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
     clear();
     cleanBuffer();
     int input=0;
     char saisie;
     char *wordAfter;
     bool vide;
     Motpred* word1 = (Motpred *)malloc(sizeof(Motpred));
     Motpred* word2 = (Motpred *)malloc(sizeof(Motpred));
     Motpred* word3 = (Motpred *)malloc(sizeof(Motpred));
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
               strcat(smsArray, " ");
               strcat(smsArray, currentWord);
               strcpy(currentWord, " ");
               currentWord[0]='\0';
               vide = true;
          }
          else if(saisie == '/')
          {
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
               currentWord[0] = saisie;
               vide = false;
          }
          else if(saisie != '\n')
          {
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
  Motpred** dicopred = (Motpred**)malloc(sizeof(Motpred*));
  Mot **dico = (Mot**)malloc(sizeof(Mot*));
  int compteur_mot = 0;
  dicopred = lecture_fichier_pred(strlen(currentWord));
  word1 =  recherche_pred(dicopred, currentWord, strlen(currentWord)) ;
  if(word1 == NULL) //-------La recherche prédictive ne trouve pas de mot correspondant
  {
    dico = lecture_fichier(strlen(currentWord)); //--------On change de dictionnaire, on cherche dans le dictionnaire français
    word1 = (Mot*)recherche(dico, currentWord, strlen(currentWord));
    if(word1 != NULL)
    {
      compteur_mot = 1;
      word2 = (Mot*)recherche(dico, currentWord, strlen(currentWord));
      if (word2 != NULL)
      {
        compteur_mot = 2;
        word3 = (Mot*)recherche(dico, currentWord, strlen(currentWord));
        if (word3 != NULL)
        {
          compteur_mot = 3;
        }
      }
      else
      {
        word3 = NULL;
      }
    }
    else
    {
      word2 = NULL;
      word3 = NULL;
    }
  }
  else //-----------Si la recherche prédictive a trouvé un mot
  {
    compteur_mot = 1;
    word2 = recherche_2eme_pred(dicopred, currentWord, strlen(currentWord), word1->lemot); //---------On continue la recherche prédictive pour un 2ème mot
    if(word2 != NULL)//------------------ La recherche prédictive a trouvé un deuxième mot
    {
      compteur_mot = 2;
      word3 = recherche_3eme_pred(dicopred, currentWord, strlen(currentWord), word1->lemot, word2->lemot); //---------On continue la recherche prédictive pour un 3ème mot
      if(word3 != NULL)//-------------La recherche prédictive a trouvé un troisième mot
      {
        compteur_mot = 3;
      }
      else //-----------------La recherche prédictive n'a pas trouvé de troisième mot
      {
        dicopred = lecture_fichier(strlen(currentWord)); //--------On change de dictionnaire, on cherche dans le dictionnaire prédictif
        word3 = (Mot *)recherche_3eme(dico, currentWord, strlen(currentWord), word1->lemot, word2->lemot);
        if(word3 != NULL) //-----------------La recherche dans le dicopred français a trouvé un troisième mot
        {
          compteur_mot = 3;
        }
      }
    }
    else //-----------------La recherche prédictive n'a pas trouvé de deuxième mot
    {
      dicopred = lecture_fichier(strlen(currentWord)); //--------On change de dictionnaire, on cherche dans le dictionnaire prédictif
      word2 = (Mot*)recherche_2eme(dico, currentWord, strlen(currentWord), word1 -> lemot); //------------On cherche un deuxième mot dans le dicopred français
      if(word2 != NULL) //----------------------La recherche dans le dicopred francais a trouvé un deuxième mot
      {
        compteur_mot = 2;
        word3 = (Mot*)recherche_3eme(dico, currentWord, strlen(currentWord), word1->lemot, word2->lemot); //------------------ On cherche un troisième mot dans le dicopred français
        if(word3 != NULL) //------------------------ La recherche a trouvé un troisième mot dans le dicopred français
        {
          compteur_mot = 3;
        }
      }
      else //--------------La recherche dans le dicopred français n'a pas trouvé de deuxième mot
      {
        word3 = NULL; //----------------- Le troisième mot est NULL
      }
    }
  }
  free(dico);
  free(dicopred);
}
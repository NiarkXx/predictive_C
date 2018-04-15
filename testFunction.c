#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "bibli_pred.h"


//----------------- CONSTANTS -----------------

#define MAX_LENGTH 300
#define MAX_LENGTH_WORD 30
#define clear() printf("\033[H\033[J")

//----------------- STRUCTURES -----------------



//----------------- PROTOTYPES -----------------
void typeSMSNonPredictive(void);
void saveSMS(char *sms);
void initArray(char *array);
void selectMode(void);
void menu(void);
void cleanBuffer(void);
void deleteWordIntoDic(void);
void readRegister(void);
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

     //saveSMS(sms);


     return 0;
}

//----------------- FUNCTIONS -----------------


void typeSMSNonPredictive()
{
    int charNb=0;
    char buffer[MAX_LENGTH];

    initArray(buffer);
    cleanBuffer();

     printf("Type your text : \n" );

     fgets(smsArray,MAX_LENGTH,stdin);

     while(smsArray[charNb] !='\n')
     {
       buffer[charNb]=smsArray[charNb];
       charNb++;
     }

     saveSMS(buffer);
}

void initArray(char *array)
{
     for (int i=0;i<MAX_LENGTH_WORD;i++)
          array[i]='\0';
}

void cleanBuffer(void)
{
     int c=0;
     while(c !='\n' && c!=EOF)
     {
          c=getchar();
     }
}

void saveSMS(char *sms)
{
  time_t timestamp;
  FILE *file=fopen("smsRegister.txt","a");

  timestamp= time(NULL);

  if(file!=NULL)
    fprintf(file, "%s --> %s",sms,ctime(&timestamp));

  else
    printf("Error : Can't open the file\n" );

  fclose(file);
}


void selectMode()
{
     if (enablePredictive) {
          //typeSMSPredictive();
          printf("\n \ntypeSMSPredictive\n" );
     }
     else
          typeSMSNonPredictive();
}


void menu()
{
     int input=0;
     bool quit=false;
     while(quit == false)
     {

          printf("\n\nPredictive Text Simulation \n" );
          printf("---------------------------------\n");
          printf("1) Enable/Disable Predictive Text. ( Currently : " );

          if(enablePredictive ==true)
               printf("TRUE )\n" );
          else
               printf("FALSE )\n" );

          printf("2) Type a SMS\n" );
          printf("3) Delete a word in the prediction Dictionnary\n" );
          printf("4) Read the smsRegister\n" );
          printf("5) Quit\n" );
          scanf("%d",&input );

          input=(int)input;

          if(input!= 1 && input !=2  && input!= 3 && input!= 4 && input!= 5)
          {
            printf("Error: Please type a right value (1 , 2 , 3,  4 or 5) \n");

          }
          else
          {
            switch (input) {
              case 1:
              enablePredictive= !enablePredictive;

              break;

              case 2:
              selectMode();
              break;
              case 3:
              deleteWordIntoDic();
              break;

              case 4:
              readRegister();
              break;

              case 5:
              quit=true;
              break;

              default:
              break;
            }

          }
     }
}


void deleteWordIntoDic()
{
     FILE *file = fopen("dictionnaire.txt","r+");
     FILE *fileCopy = fopen("dictionnaire_tmp.txt","w+");
     bool done = false;
     char word_dic[MAX_LENGTH_WORD];
     int occurence = 1;
     int removeTest;
     int renameTest;
     char wordToDelete[MAX_LENGTH_WORD];
     Motpred** dico = (Motpred**)malloc(sizeof(Motpred*));

     if (file != NULL && fileCopy != NULL)
      {
        rewind(file);
        if (fgetc(file) == EOF) {
           printf("Error : The file is empty\n" );
        }
        else
         {
           rewind(file);
           initArray(word_dic);
           cleanBuffer();
           printf("Type the word to delete : \n");

           scanf("%s",wordToDelete);

           dico = lecture_fichier_pred((int)strlen(wordToDelete));

           if(recherche_pred(dico, wordToDelete, (int)strlen(wordToDelete))!=NULL)
           {
             while(fscanf(file, "%s %d", word_dic, &occurence)==2)
             {
               if(strcmp(wordToDelete,word_dic)!=0)
               {
                 fprintf(fileCopy, "%s %d\n",word_dic,occurence );
               }
               
             }
             done=true;
           }
           else
            printf("Error : This word does not exists in the file \n");
         }
     }
     else
      printf("Error : Can't open the file");

     fclose(file);
     fclose(fileCopy);

     if(done)
     {
       removeTest = remove("dictionnaire.txt");
       if (removeTest != 0)
       printf("Error to remove the file");

       renameTest = rename("dictionnaire_tmp.txt", "dictionnaire.txt");

       if (renameTest != 0) {
         printf("Error to rename");
     }
     else
      remove("dictionnaire_tmp.txt");
  }
}


void readRegister()
{
  FILE *file=fopen("smsRegister.txt","r");

  char sms[MAX_LENGTH];



  if(file!= NULL)
  {
    // while(fscanf(file,"%s \n",sms)==1)
    //   printf("%s\n",sms);
    while(fgets(sms,MAX_LENGTH,file)!=NULL)
      printf("%s\n",sms);

  }
  else
    printf("Error : Can't open the file\n" );

  fclose(file);
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "bibli_doc.h"
#include "bibli_pred.h"

//----------------- CONSTANTS -----------------

#define MAX_LENGTH 300
#define MAX_LENGTH_WORD 30



//----------------- STRUCTURES -----------------



//----------------- PROTOTYPES -----------------
void menu(void);
void typeSMSPredictive(void);
void typeSMSNonPredictive(void);
void selectMode(void);
void cleanBuffer(void);
void readInput(char *string);
bool searchEnter(char *string);
bool searchSpace(char *currentWord, char *wordAfter );
bool searchBackSlash(char *string);
void writeWordIntoDic(char string[]);

//----------------- GLOBALS -----------------


bool enablePredictive = false;
char smsArray[MAX_LENGTH];
char currentWord[MAX_LENGTH_WORD];


//----------------- MAIN -----------------
int main(int argc, char const *argv[]) {



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
     readInput(inputText);
}


void selectMode()
{
     if (enablePredictive) {
               typeSMSPredictive();
               printf("typeSMSPredictive\n" );
     }
     else
               typeSMSNonPredictive();
}

void typeSMSPredictive()
{
     system("clear");
     int input=0;
     char *saisie;
     char *wordAfter;

     do
     {
          system("clear");
          printf("Type your SMS\n");
          printf("1) Word 1   2) Word 2   3) Word 3\n" );
          printf("%s", smsArray);
          printf("%s", currentWord);
          saisie = getchar();
          if(saisie == ' ')
          {
               strcat(smsArray, currentWord);
               strcpy(currentWord, " ");
               currentWord[0]='\0';
          }
          else if(saisie == '/')
          {
               scanf("%d",&input );
               switch (input) {
               case 1:
                    break;
               case 2:
                    break;
               case 3:
                    break;
               default:
                    printf("ERROR");
                    break;
               }
          }
          else if(saisie != '\n')
          {
               strcat(currentWord, saisie);
          }
     }while(saisie != '\n');
}

void cleanBuffer(void)
{
     int c=0;
     while(c !='\n' && c!=EOF)
     {
          c=getchar();
     }
}

// bool searchEnter(char *string)
// {
//      bool value=false;

//      for(int i=0;i<strlen(string);i++)
//      {
//           if(string[i]=='\n')
//                value= true;
//      }
//      return value;
// }

// bool searchBackSlash(char *string)
// {
//      bool value=false;
//      for(int i=0;i<strlen(string);i++)
//      {
//           if(string[i]=='/')
//                value= true;
//      }
//      return value;
// }

// void readInput(char *string)
// {
//      char text[MAX_LENGTH_WORD];
//      if (scanf("%30s", text) != 0)
//      {
//           strcat(currentWord, string);
//      }
//      else
//           cleanBuffer();
// }

// bool searchSpace(char currentWord)
// {
//      bool value=false;
//      int counter=0;
//      bool done=false;
//      for(int i=0;i<strlen(currentWord);i++)
//      {
//           if(currentWord[i]==' ')
//           {
//                value=true;
//           }

//           if(value && done==false)
//           {
//                for(int j=i;j<strlen(currentWord);j++)
//                {
//                     done=true;
//                     wordAfter[counter]=currentWord[j];
//                     counter++;

//                }
//           }
//      }

//      return value;

// }


void writeWordIntoDic(char string[])
{
     FILE *file=fopen("dictionnaire.txt","r+");
     int cursor=0;
     char word[MAX_LENGTH];
     FILE *fileCopy=fopen("dictionnaire_tmp.txt","w+");
     bool done=false;

     if (file!=NULL && fileCopy!=NULL) {
          rewind(file);

          while(fscanf(file, "%s", word)!=EOF)
          //while(fscanf(file, "%s", word)==1)
          {
               if(done!=true)
               {
                    if(strcoll(word,string)<0)
                    {
                         fprintf(fileCopy, "%s\n",word );
                    }
                    else
                    {
                         fprintf(fileCopy,"%s\n",string);
                         fprintf(fileCopy,"%s\n",word);
                         done=true;
                    }
               }
               else
                    fprintf(fileCopy,"%s\n",word);
          }
     }
     else
          printf("Error : Can't read the file\n");

     fclose(file);
     fclose(fileCopy);
     remove("dictionnaire.txt");
     rename("dictionnaire_tmp.txt","dictionnaire.txt");
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

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
bool searchSpace(char *string);
bool searchEnter(char *string);
void wait(float time);
void writeWordIntoDic(char string[]); 

//----------------- GLOBALS -----------------


bool enablePredictive = false;
char smsArray[MAX_LENGTH];
char currentWord[MAX_LENGTH_WORD];


//----------------- MAIN -----------------
int main(int argc, char const *argv[]) {



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
     cleanBuffer();
     readInput(inputText);
}


void selectMode()
{
     switch (enablePredictive) {
          case true:
               typeSMSPredictive();
               printf("typeSMSPredictive\n" );
               break;
          case false:
               typeSMSNonPredictive();
               break;
     }
}

void typeSMSPredictive()
{
     system("clear")
     int input=0;
     bool send=false;
     char *saisie;
     printf("Type your SMS\n");

     while(send == false)
     {
          wait(1);
          readInput(&saisie);
          printf("1) Word 1   2) Word 2   3) Word 3\n" );
          printf("%s", smsArray);
          printf("%s", currentWord);
          if(searchSpace)
          {
               strcat(smsArray, currentWord);
               currentWord[0] = "\0";
          }
          if(searchEnter)
          {
               send = true;
          }
          
          if(searchBackSlash)
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
                    printf("ERROR")
                    break;
               }
          }
     }
}

void cleanBuffer(void)
{
     int c=0;
     while(c !='\n' && c!=EOF)
     {
          c=getchar();
     }
}

bool searchEnter(char *string)
{
     bool value=false;

     for(int i=0;i<strlen(string);i++)
     {
          if(string[i]=='\n')
               value= true;
     }
     return value;
}

bool searchBackSlash(char *string)
{
     bool value=false;
     for(int i=0;i<strlen(string);i++)
     {
          if(string[i]=='/')
               value= true;
     }
     return value;
}

void readInput(char *string)
{
     char *position=NULL;
     if (fgets(string,MAX_LENGTH+1,stdin)!=NULL)
     {
          if(position=strchr(string,'\n'))
          *position='\0';
          strcat(currentWord, string);
     }
     else
          cleanBuffer();
}

bool searchSpace(char *string)
{
     bool value=false;
     for(int i=0;i<strlen(string);i++)
    {
          if(string[i]==' ')
               value= true;
    }
   return value;
}

void wait(float time)
{
    clock_t waiting = clock() + (time * CLOCKS_PER_SEC); 
    while(clock() < waiting);
}

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
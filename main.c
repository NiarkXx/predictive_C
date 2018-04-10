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
          else if(searchEnter)
          {
               send = true;
          }
          
          else if(searchBackSlash)
          {
               scanf("%d",&input );
               switch (input) {
               case 1:
                    memcpy(currentWord, word1, strlen(word1));
                    strcat(smsArray, currentWord);
                    currentWord[0] = "\0";
                    break;
               case 2: 
                    memcpy(currentWord, word2, strlen(word2));
                    strcat(smsArray, currentWord);
                    currentWord[0] = "\0";
                    break;
               case 3:
                    memcpy(currentWord, word3, strlen(word3));
                    strcat(smsArray, currentWord);
                    currentWord[0] = "\0";
                    break;
               default:
                    printf("ERROR")
                    break;
               }
          }
          else

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
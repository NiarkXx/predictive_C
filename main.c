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
void displayDictionnary(bool typeOfDic );
void createDictionnary( char nameDictionnary[], bool typeOfDic);

//----------------- GLOBALS -----------------


bool enablePredictive = false;


//----------------- MAIN -----------------
int main(int argc, char const *argv[]) {

     createDictionnary("french_dic.txt",1);
     displayDictionnary(1);

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
          if(serachSpace)
          {
               
          }
          if(searchEnter)
          {
               send = true;
          }
          
          if(search_backslash)
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
     for(int i=0;i<strlen(string);i++)
     {
          if((int)string[i]==13)
               return true;
          else
               return false;
     }

}

void readInput(char *string)
{
	char *position=NULL;
	if (fgets(string,MAX_LENGTH+1,stdin)!=NULL)
	{
		if(position=strchr(string,'\n'))
		*position='\0';
     }
	else
		cleanBuffer();
}

void wait(float time)
{
    clock_t waiting = clock() + (time * CLOCKS_PER_SEC); 
    while(clock() < waiting);
}
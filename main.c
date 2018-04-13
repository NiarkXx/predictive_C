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
// void readInput(char *string);
// bool searchEnter(char *string);
// bool searchSpace(char *currentWord, char *wordAfter );
// bool searchBackSlash(char *string);
void writeWordIntoDic(char string[Taille_max_pred]);
int getch(void);
void insertion_dic(char sentence[MAX_LENGTH]);

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
  do
  {
    clear();
    printf("Type your SMS\n");
    printf("1) Word 1   2) Word 2   3) Word 3\n" );
    printf("%s ", smsArray);
    printf("%s", currentWord);
    saisie = getch();
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
        strcat(smsArray, "Word 1");
        strcpy(currentWord, " ");
        currentWord[0]='\0';
        vide = true;
        break;
        case 2:
        strcat(smsArray, " ");
        strcat(smsArray, "Word 2");
        strcpy(currentWord, " ");
        currentWord[0]='\0';
        vide = true;
        break;
        case 3:
        strcat(smsArray, " ");
        strcat(smsArray, "Word 3");
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


void writeWordIntoDic(char string[MAX_LENGTH_WORD])
{
 FILE *file = fopen("dictionnaire.txt","r+");
 int cursor = 0;
 char word[MAX_LENGTH_WORD];
 FILE *fileCopy = fopen("dictionnaire_tmp.txt","w+");
 bool done = false;
 int occurence = 0;

 if (file != NULL && fileCopy != NULL) {
  rewind(file);

  while(fscanf(file, "%s %d", word, &occurence)!=EOF)
  {
    if(done!=true)
    {
      if(strcoll(word,string)<0)
      {
        fprintf(fileCopy, "%s %d\n",word,occurence );
      }
      else if(strcoll(word,string)==0)
      {
        occurence++;
        fprintf(fileCopy,"%s %d\n",word, occurence);
        done=true;
      }
      else
      {
        fprintf(fileCopy,"%s %d\n",string,1);
        fprintf(fileCopy,"%s %d\n",word,occurence);
        done=true;
      }
    }
    else
    {
      fprintf(fileCopy,"%s %d\n",word,occurence);
    }
  }
}
else
  printf("Error : Can't read the file\n");

fclose(file);
fclose(fileCopy);
remove("dictionnaire.txt");
rename("dictionnaire_tmp.txt","dictionnaire.txt");
}

void insertion_dic(char sentence[MAX_LENGTH])
{
     int i = 1;
     int j = 0;
     int k;
     char word[MAX_LENGTH_WORD];
     while(sentence[i] != '\0')
     {
          if(sentence[i] == ' ')
          {
               writeWordIntoDic(word);
               for(k=0; k<=j; k++)
               {
                    word[k]='\0';
               }
               
               j = 0;
          }
          else  
          {
               word[j] = sentence[i];
               j++;
          }

          i++;

     }

}
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
int proposition_3_words_pred(Motpred* word1, Motpred* word2, Motpred* word3);
void proposition_3_words(Mot* word1, Mot* word2, Mot* word3, int compteur_mot);
bool deleteWordIntoDic();
void readRegister();
void typeSMSNonPredictive();
void saveSMS(char *sms);
void addWordIntoDic();
void modifyWordIntoDic();

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
     clear();
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
          printf("3) Read the smsRegister\n" );
          printf("4) Add a word to the prediction Dictionnary\n");
          printf("5) Delete a word to the prediction Dictionnary\n" );
          printf("6) Modify a word from the prediction Dictionnary\n");
          printf("7) Quit\n" );
          scanf("%d",&input );

          input=(int)input;

          
          switch (input) {
           case 1:
           enablePredictive= !enablePredictive;

           break;

           case 2:
           selectMode();
           break;
           case 3:
           readRegister();

           break;

           case 4:
           addWordIntoDic();
           break;

           case 5:
           deleteWordIntoDic();
           break;

           case 6:
           modifyWordIntoDic();
           break;

           case 7:
           quit=true;
           break;

           default:
           printf("Error: Please type a right value (1 , 2 , 3 , 4 , 5 , 6 or 7) \n");
           break;
            

          }
     }
}

void typeSMSNonPredictive()
{
    int charNb=0;
    char buffer[MAX_LENGTH];

    initArray(buffer);
    cleanBuffer();
    clear();
     printf("Type your text : \n" );

     fgets(smsArray,MAX_LENGTH,stdin);

     while(smsArray[charNb] !='\n')
     {
       buffer[charNb]=smsArray[charNb];
       charNb++;
     }

     saveSMS(buffer);
     initArray(smsArray);
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
     bool vide = true;
     int nbr_word;
     Motpred* word1 = (Motpred *)malloc(sizeof(Motpred));
     Motpred* word2 = (Motpred *)malloc(sizeof(Motpred));
     Motpred* word3 = (Motpred *)malloc(sizeof(Motpred));
     Mot* word_dic1 = (Mot *)malloc(sizeof(Mot));
     Mot* word_dic2 = (Mot *)malloc(sizeof(Mot));
     Mot* word_dic3 = (Mot *)malloc(sizeof(Mot));
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
               nbr_word = proposition_3_words_pred(word1, word2, word3);
               if(nbr_word != 3)
               {
                proposition_3_words(word_dic1, word_dic2, word_dic3, nbr_word);
               }
               if(nbr_word == 0)
               {
                    printf("1) %s 2) %s 3) %s\n", word_dic1 -> lemot, word_dic2 -> lemot, word_dic3 -> lemot);
 
               }
               else if(nbr_word == 1)
               {
                    printf("1) %s 2) %s 3) %s\n", word1 -> lemot, word_dic2 -> lemot, word_dic3 -> lemot);
               }
               else if(nbr_word == 2)
               {
                    printf("1) %s 2) %s 3) %s\n", word1-> lemot, word2 -> lemot, word_dic3 -> lemot);
               }
               else
               {
                    printf("1) %s 2) %s 3) %s\n", word1 -> lemot, word2 -> lemot, word3 -> lemot);
               }
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
                    if(nbr_word == 0)
                    {
                         strcat(smsArray, word_dic1->lemot);
                    }
                    else
                    {
                         strcat(smsArray, word1->lemot);
                    }
                    strcpy(currentWord, " ");
                    currentWord[0]='\0';
                    vide = true;
                    break;
                    case 2:
                    strcat(smsArray, " ");
                    if(nbr_word <= 1)
                    {
                         strcat(smsArray, word_dic2->lemot);
                    }
                    else
                    {
                         strcat(smsArray, word2->lemot);
                    }
                    strcpy(currentWord, " ");
                    currentWord[0]='\0';
                    vide = true;
                    break;
                    case 3:
                    strcat(smsArray, " ");
                    if(nbr_word <= 2)
                    {
                         strcat(smsArray, word_dic3->lemot);
                    }
                    else
                    {
                         strcat(smsArray, word3->lemot);
                    }
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
               vide = false;
          }
     }while(saisie != '\n');

     free(word1);
     free(word2);
     free(word3);
     free(word_dic1);
     free(word_dic2);
     free(word_dic3);

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

void addWordIntoDic()
{
     Motpred** dicopred = (Motpred**)malloc(sizeof(Motpred*));
     dicopred = lecture_fichier_pred((int)MAX_LENGTH_WORD);
     char wordToAdd[MAX_LENGTH_WORD];
     clear();
     printf("Type the word to add :\n");
     scanf("%30s", wordToAdd);
     if(recherche_pred(dicopred, wordToAdd, MAX_LENGTH_WORD) == NULL)
     {
          writeWordIntoDic(wordToAdd);
     }
     else
     {
          printf("This word already exists in the prediction dictionnary\n");
     }
}

void modifyWordIntoDic()
{
     Motpred** dicopred = (Motpred**)malloc(sizeof(Motpred*));
     dicopred = lecture_fichier_pred((int)MAX_LENGTH_WORD);
     char wordToAdd[MAX_LENGTH_WORD];
     bool done = false;
     clear();
     done = deleteWordIntoDic();
     if(done)
     {
          printf("Type the word to add :\n");
          scanf("%30s", wordToAdd);
          if(recherche_pred(dicopred, wordToAdd, MAX_LENGTH_WORD) == NULL)
          {
               writeWordIntoDic(wordToAdd);
          }
          else
          {
               printf("This word already exists in the prediction dictionnary\n");
          }
     }
     

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
     Mot** dico = (Mot**)malloc(sizeof(Mot*));
     dico = lecture_fichier(MAX_LENGTH_WORD);
     int i = 1;
     int j = 0;
     char word[MAX_LENGTH_WORD];
     initArray(word);
     while(sentence[i] != '\0')
     {
          if(sentence[i] == ' ')
          {
               if (recherche_mot(dico, word, MAX_LENGTH_WORD))
               {
                    writeWordIntoDic(word);
               }

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

int proposition_3_words_pred(Motpred* word1, Motpred* word2, Motpred* word3)
{
  Motpred** dicopred = (Motpred**)malloc(sizeof(Motpred*));
  Motpred* word1_tmp = (Motpred *)malloc(sizeof(Motpred));
  Motpred* word2_tmp = (Motpred *)malloc(sizeof(Motpred));
  Motpred* word3_tmp = (Motpred *)malloc(sizeof(Motpred));
  int compteur_mot = 0;
  dicopred = lecture_fichier_pred(strlen(currentWord));
  word1_tmp = recherche_pred(dicopred, currentWord, strlen(currentWord));
  if(word1_tmp == NULL) //-------La recherche prédictive ne trouve pas de mot correspondant
  {
    word1 = NULL;
    word2 = NULL;
    word3 = NULL;
  }
  else //-----------Si la recherche prédictive a trouvé un mot
  {
    strcpy(word1->lemot, word1_tmp -> lemot);
    compteur_mot = 1;
    word2_tmp = recherche_2eme_pred(dicopred, currentWord, strlen(currentWord), word1 -> lemot); //---------On continue la recherche prédictive pour un 2ème mot
    if(word2_tmp != NULL)//------------------ La recherche prédictive a trouvé un deuxième mot
    {
      strcpy(word2 -> lemot, word2_tmp -> lemot);
      compteur_mot = 2;
      word3_tmp = recherche_3eme_pred(dicopred, currentWord, strlen(currentWord), word1 -> lemot, word2 -> lemot); //---------On continue la recherche prédictive pour un 3ème mot
      if(word3_tmp != NULL)//-------------La recherche prédictive a trouvé un troisième mot
      {
        strcpy(word3 -> lemot, word3_tmp ->lemot);
        compteur_mot = 3;
      }
    }
    else //-----------------La recherche prédictive n'a pas trouvé de deuxième mot
    {
      word2 = NULL;
      word3 = NULL;
    }
  }
  free(dicopred);
  return compteur_mot;
}

void proposition_3_words(Mot* word1, Mot* word2, Mot* word3, int compteur_mot)
{
  Mot** dico = (Mot**)malloc(sizeof(Mot*));
  Mot* word1_tmp = (Mot *)malloc(sizeof(Mot));
  Mot* word2_tmp = (Mot *)malloc(sizeof(Mot));
  Mot* word3_tmp = (Mot *)malloc(sizeof(Mot));
  dico = lecture_fichier(strlen(currentWord));
  if(compteur_mot == 0)
  {
    word1_tmp = recherche(dico, currentWord, strlen(currentWord));
    if(word1_tmp != NULL)
    {
      strcpy(word1 -> lemot, word1_tmp -> lemot);
      word2_tmp = recherche_2eme(dico, currentWord, strlen(currentWord), word1 -> lemot);
      
      if(word2_tmp != NULL)
      {
          strcpy(word2 -> lemot, word2_tmp -> lemot);
          word3_tmp = recherche_3eme(dico, currentWord, strlen(currentWord), word1 -> lemot, word2 -> lemot);
          if(word3_tmp != NULL)
          {
               strcpy(word3 -> lemot, word3_tmp -> lemot);
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
    else
    {
      word1 = NULL;
      word2 = NULL;
      word3 = NULL;
    }
  }
  else if(compteur_mot == 1)
  {
    word2_tmp = recherche_2eme(dico, currentWord, strlen(currentWord), word1 -> lemot);
    if(word2_tmp!= NULL)
    {
      strcpy(word2 -> lemot, word2_tmp -> lemot);
      word3_tmp = recherche_3eme(dico, currentWord, strlen(currentWord), word1 -> lemot, word2 -> lemot);
      
      if (word3_tmp != NULL)
      {
          strcpy(word3 -> lemot, word3_tmp -> lemot);
      }
      else
      {
          word3 = NULL;
      }
    }
    else
    {
      word3 = NULL;
    }
  }
  else  if(compteur_mot == 2)
  {
    word3_tmp = recherche_3eme(dico, currentWord, strlen(currentWord), word1 -> lemot, word2 -> lemot);
    if(word3_tmp != NULL)
    {
     strcpy(word3 -> lemot, word3_tmp -> lemot);
    }
    else
      {
          word3 = NULL;
      }
  }
  free(dico);
}

bool deleteWordIntoDic()
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

           scanf("%30s",wordToDelete);

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
  return done;
}

void readRegister()
{
  FILE *file=fopen("smsRegister.txt","r");

  char sms[MAX_LENGTH];



  if(file!= NULL)
  {
     if (fgetc(file) == EOF) 
     {
           printf("Error : The file is empty\n" );
        }
        else
        {
          while(fgets(sms,MAX_LENGTH,file)!=NULL)
               printf("%s\n",sms);
        }
          

  }
  else
    printf("Error : Can't open the file\n" );

  fclose(file);
}
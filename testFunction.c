#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//#include <SDL/SDL.h>

#define MAX_LENGTH 300
#define MAX_LENGTH_WORD 50



//void readWithEvent(void);
//void createWindow(void);
// bool searchEnter(char *string);
// bool searchBackSlash(char *string);
// bool searchSpace(char *string);
void writeWordIntoDic(char string[]);
bool searchSpace(char *currentWord, char* wordAfter );

int main(int argc, char const *argv[]) {
     char current[MAX_LENGTH_WORD]="Je suis une phrase";
     char nextWord[MAX_LENGTH_WORD];
     bool spaceExist;
     // char sentence[20] ="Jesuisunephrase";
     // bool test;
     //test=searchEnter(sentence);
     //test=searchBackSlash(sentence);
     // test=searchSpace(sentence);
     //
     //
     // if(test==true)
     //      printf("True\n" );
     // else if(test==false)
     //      printf("false\n" );
     // else
     //      printf("Error\n" );
     //writeWordIntoDic("Ptdrrr");

     spaceExist=searchSpace(current,nextWord);

     printf("Bool : %d \n Current : %s \n NextWord : %s \n",spaceExist,current, nextWord );
     return EXIT_SUCCESS;
}

// bool searchEnter(char *string)
// {
//      bool value=false;
//
//      for(int i=0;i<strlen(string);i++)
//      {
//           if(string[i]=='\n')
//                value= true;
//      }
//      return value;
// }
//
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
//
bool searchSpace(char *currentWord, char *wordAfter )
{
     bool value=false;
     int counter=0;
     bool done=false;
     for(int i=0;i<strlen(currentWord);i++)
     {
          if(currentWord[i]==' ')
          {
               value=true;
          }

          if(value && done==false)
          {
               for(int j=i;j<strlen(currentWord);j++)
               {
                    done=true;
                    wordAfter[counter]=currentWord[j];
                    counter++;

               }
          }
     }

     return value;

}


void readSMS()
{
     FILE *file=fopen("","");
}



// void writeWordIntoDic(char string[])
// {
// 	FILE *file=fopen("dictionnaire.txt","r+");
//      int cursor=0;
//      char word[MAX_LENGTH];
//      FILE *fileCopy=fopen("dictionnaire_tmp.txt","w+");
//      bool done=false;
//
// 	if (file!=NULL && fileCopy!=NULL) {
//           rewind(file);
//
//           while(fscanf(file, "%s", word)!=EOF)
//           //while(fscanf(file, "%s", word)==1)
//           {
//                if(done!=true)
//                {
//                     if(strcoll(word,string)<0)
//                     {
//                          fprintf(fileCopy, "%s\n",word );
//                     }
//                     else
//                     {
//                          fprintf(fileCopy,"%s\n",string);
//                          fprintf(fileCopy,"%s\n",word);
//                          done=true;
//                     }
//                }
//                else
//                     fprintf(fileCopy,"%s\n",word);
//           }
// 	}
//      else
// 	    printf("Error : Can't read the file\n");
//
// 	fclose(file);
//      fclose(fileCopy);
//      remove("dictionnaire.txt");
//      rename("dictionnaire_tmp.txt","dictionnaire.txt");
// }

//-------------------------------------------------------
// void createWindow()
// {
//      if(SDL_Init(SDL_INIT_VIDEO)==-1)
//      {
//           fprintf(stderr, "Error Initialization SDL_VIDEO : %s \n",SDL_GetError());
//           exit(EXIT_FAILURE);
//      }
//      else
//      {
//           SDL_SetVideoMode(640,480,32, SDL_HWSURFACE);
//
//           // SDL_Window *screen = SDL_CreateWindow("My Game Window",
//           //                 SDL_WINDOWPOS_UNDEFINED,
//           //                 SDL_WINDOWPOS_UNDEFINED,
//           //                 640, 480,
//           //                 SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL);
//
//      }
//
// }
//
//
// void readWithEvent()
// {
//      bool continueToWait=true;
//      int keyValue;
//      char castKeyValue;
//
//      while(continueToWait)
//      {
//           SDL_Event event;
//           while(SDL_PollEvent(&event))
//           {
//                //SDL_PollEvent(&event);
//                // if(event.type==SDL_KEYDOWN)
//                // {
//                //      printf("Right event\n" );
//                //      keyValue=event.key.keysym.sym;
//                //      castKeyValue=(char)keyValue;
//                //      printf("%d --> %c\n",keyValue,castKeyValue );
//                //
//                // }
//                // else
//                // {
//                //      printf("Wrong event\n" );
//                //
//                // }
//                switch (event.type) {
//
//                     case SDL_QUIT:
//                          continueToWait=false;
//                          break;
//
//                     case SDL_KEYDOWN:
//                     keyValue= event.key.keysym.sym;
//                     castKeyValue=(char)keyValue;
//                     printf("%d --> %c\n",keyValue,castKeyValue );
//                     switch (event.key.keysym.sym) {
//                          case SDLK_b:
//                          printf("It's B key\n" );
//                          break;
//                     }
//                     break;
//                     default :
//                          break;
//                }
//           }
//      }
// }

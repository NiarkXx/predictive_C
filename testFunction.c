#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//#include <SDL/SDL.h>



//void readWithEvent(void);
//void createWindow(void);
bool searchEnter(char *string);
int main(int argc, char const *argv[]) {

     char sentence[20] ="Je suis une \n phrase";
     bool test;
     test=searchEnter(sentence);
     if(test==true)
          printf("True\n" );
     else if(test==false)
          printf("false\n" );
     else
          printf("Error\n" );

     return EXIT_SUCCESS;
}

bool searchEnter(char *string)
{
     for(int i=0;i<strlen(string);i++)
     {
          if(string[i]=='\n')
               return true;
          else
               return false;
     }
}



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

#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "header.h"

int main (void)
{
//creation fenetre
SDL_Surface *screen =NULL;
Mix_Music *musique;
SDL_Init(SDL_INIT_VIDEO);
screen = SDL_SetVideoMode(720,475,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
SDL_WM_SetCaption("Solve To Escape",NULL);
SDL_WM_SetIcon(IMG_Load("icon.png"),NULL);
if (screen==NULL)
{
printf("error: %s ",SDL_GetError());
exit(EXIT_FAILURE);
}
//chargement music
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
           { 
           printf("%s",Mix_GetError());
           }
           musique=Mix_LoadMUS("music.wav");
           Mix_PlayMusic(musique, -1);



SDL_ShowCursor(SDL_DISABLE);
menu(screen);
//fermeture
pause();
Mix_FreeMusic(musique);

Mix_CloseAudio();
SDL_Quit();
return 0;
}

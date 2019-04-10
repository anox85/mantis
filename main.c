#include<stdio.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include"enemie.h"
#include <string.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h> 
#include "enemie.h" 

int main( int argc, char *argv[ ] )
{

SDL_Surface *screen=NULL;
SDL_Surface *background=NULL;
SDL_Surface *ciseaux=NULL;
SDL_Surface *ciseaux2=NULL;
SDL_Surface *papier=NULL;
SDL_Surface *papier2=NULL;
SDL_Init(SDL_INIT_VIDEO);

screen=SDL_SetVideoMode(1400, 475, 32, SDL_HWSURFACE);
SDL_WM_SetCaption("animation-char", NULL);  
background=SDL_LoadBMP("background.bmp");
ciseaux2 = IMG_Load("ciseaux2.png");
papier2 = IMG_Load("papier2.png");
SDL_Rect positionback,positiondet;

//initialisation&affichage

ciseaux=IMG_Load("ciseaux.png");
papier=IMG_Load("papier.png");

SDL_Rect ciseauxPosition ; 
ciseauxPosition.y=0;

SDL_Rect papierPosition; 
papierPosition.x=0;

SDL_BlitSurface(ciseaux,NULL,background,&ciseauxPosition);
SDL_FreeSurface(ciseaux);
SDL_Flip(screen);

SDL_BlitSurface(papier,NULL,background,&papierPosition);
SDL_FreeSurface(papier);
SDL_Flip(screen);

// fin initialisation&affichage

int t=80;
int x,y;
int k=0;

positionback.x=0;
positionback.y=0;
SDL_BlitSurface(background,NULL,screen,&positionback);
SDL_Flip(screen);
SDL_Delay(2000);
 
ciseauxPosition.y=y;

papierPosition.x=x;

deplacement_enemie_verticale (ciseauxPosition);
deplacement_papier_horizentale (papierPosition);
animation(&screen ,&ciseaux,&ciseaux2,&papier,&papier2,positiondet); 
 

}

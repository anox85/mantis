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

void deplacement_enemie_verticale (SDL_Rect ciseauxPosition) 
{
int direction=0;
 int y_initiale=ciseauxPosition.y;
if (direction == 0)
{
    
      if (ciseauxPosition.y<= ( y_initiale+50))
    
{ciseauxPosition.y ++;}
 
// descend
    
      else if(ciseauxPosition.y >= ( y_initiale+50))
    {direction = 1;}
}




else if (direction == 1)
{
    if (ciseauxPosition.y >=  y_initiale)

{ciseauxPosition.y --;} 

// monte
    
        else if(ciseauxPosition.y <=  y_initiale)
    {direction = 0;}
    
}

}



void deplacement_papier_horizentale (SDL_Rect papierPosition) 
{
int direction=0;
 int pos_x_init=papierPosition.x;
if (direction == 0)
{
    
      if (papierPosition.x <= (pos_x_init+50))
    
{papierPosition.x ++;}
 
// à droite 
    
      else if(papierPosition.x >= (pos_x_init+50))
    {direction = 1;}
}




else if (direction == 1)
{
    if (papierPosition.x >= pos_x_init)

{papierPosition.x --;} 

// à gauche 
    
        else if(papierPosition.x <= pos_x_init)
    {direction = 0;}    
}
}

void animation(SDL_Surface *ecran , SDL_Surface *ciseaux,  SDL_Surface *ciseaux2, SDL_Surface *papier, SDL_Surface *papier2 ,SDL_Rect positiondet)
{int k=0;
int t=80;
if(k=1)
{
                                SDL_BlitSurface(ciseaux,NULL,ecran,&positiondet);
SDL_Flip(ecran);

SDL_Delay(t);
}

else if(k=2)
{
				SDL_BlitSurface(ciseaux2,NULL,ecran,&positiondet);
SDL_Flip(ecran);

SDL_Delay(t);
}

else if(k=3)
{
				SDL_BlitSurface(papier,NULL,ecran,&positiondet);
SDL_Flip(ecran);

SDL_Delay(t);
}

else if(k=4)
{
				SDL_BlitSurface(papier2,NULL,ecran,&positiondet);
SDL_Flip(ecran);

SDL_Delay(t);
}
}







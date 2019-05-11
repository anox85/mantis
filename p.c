#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "partage_d'ecran.h"


void initialiser_momo(joueur *j1)
{
    j1->p[0]=IMG_Load("momo.png");

    j1->pp.x = 20;
    j1->pp.y = 200;

}

void initialiser_sousana(joueur *j2)
{
    j2->p[1]=IMG_Load("sousana.png");

    j2->pp.x = largeur/2 + 10;
    j2->pp.y = 200;

}

void initialiser_background1(background *b1)
{
    b1->background=SDL_LoadBMP("background.bmp");
    b1->pb.x=0;
    b1->pb.y=0;
    b1->pb.w=largeur/2;
    b1->pb.h=hauteur;
}

void initialiser_background2(background *b2)
{
    b2->background=SDL_LoadBMP("background.bmp");
    b2->pb.x=largeur/2;
    b2->pb.y=0;
    b2->pb.w=largeur/2;
    b2->pb.h=hauteur;
}

void Render_momo(joueur *j1,SDL_Surface* screen)
{
    SDL_Rect R;
    R.x = j1->x;
    R.y = j1->y;
  
    SDL_BlitSurface(j1->p , NULL , screen  , &R);
}

void Render_sousana(joueur *j2,SDL_Surface* screen)
{
    SDL_Rect R;
    R.x = j2->x;
    R.y = j2->y;
  
    SDL_BlitSurface(j2->p , NULL , screen  , &R);
}








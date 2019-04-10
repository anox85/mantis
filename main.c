#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include <SDL/SDL_ttf.h>
#include "header.h"


int main()
{

    


//fonction

SDL_Surface *screen=NULL;
    SDL_Surface *image=NULL;
    SDL_Surface *sprite=NULL;
    SDL_Surface *enigme=NULL;
    SDL_Rect positionecran;
    SDL_Rect positionSprite;

    SDL_Rect rect;
    SDL_Rect positionenigme;
    rect.h = 400;
    rect.w = 1600;
   
    SDL_Event event;
    SDL_Event test_event;
    int done =1;
    int boucle_jeux=1;
    int test=0;
    positionecran.x = 0;
    positionecran.y = 0;
    positionSprite.x=50;
    positionSprite.y=220;
    positionenigme.x=20;
    positionenigme.y=10;



    while(boucle_jeux)
    {SDL_Init(SDL_INIT_VIDEO);
        if(SDL_Init(SDL_INIT_VIDEO)!=0)
        {
            printf("unable to initialize SDL: %s\n",SDL_GetError());
            return 1;
        }
        screen=SDL_SetVideoMode(1600, 400, 32,SDL_HWSURFACE|SDL_DOUBLEBUF);
        
        image = SDL_LoadBMP("background.bmp");

        SDL_BlitSurface(image , NULL , screen  , &positionecran);
        if(screen==NULL)
        {
            printf("unabble to set video mode :%s\n",SDL_GetError());
            return 1;
        }



        sprite = IMG_Load("detective.png" );
        SDL_SetColorKey(sprite, SDL_SRCCOLORKEY, SDL_MapRGB(sprite->format, 255, 255, 255));
        SDL_BlitSurface(sprite , NULL , screen  , &positionSprite);
       
        SDL_Flip(screen);

        enigme = IMG_Load("enigmee.png" );
       
        SDL_BlitSurface(enigme , NULL , screen  , &positionenigme);
        
        SDL_Flip(screen);
        if(enigme==NULL)
        {
            printf("unable to laod flag: %s\n",SDL_GetError());
            return 1;
        }

        pause=getchar();
        
        
	SDL_EnableKeyRepeat(10, 10);
        while(done)
        {
            SDL_WaitEvent(&test_event);
            switch(test_event.type)
            {
            case SDL_QUIT:
                done=0;
                break ;
            case SDL_KEYDOWN:
                switch(test_event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    done=0;
                    break;
                case SDLK_LEFT:
                    positionSprite.x-=10;
                    if(positionSprite.x <= rect.y) {
                        positionSprite.x= positionSprite.x + 10;
                    }
                    break;
                case SDLK_RIGHT:
                    positionSprite.x+=10;
                    if(positionSprite.x >= (rect.w-70)) {
                        positionSprite.x= positionSprite.x - 10;
                    }
                    break;
                case SDLK_UP:
                    positionSprite.y-=10;
                    if(positionSprite.y <= rect.x) {
                        positionSprite.y= positionSprite.y + 10;
                    }
                    break;
                case SDLK_DOWN:
                    positionSprite.y+=10;
                    if(positionSprite.y >= (rect.h - 170)) {
                        positionSprite.y= positionSprite.y - 10;
                    }
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
    

        

}
}



char mot[50];

size_t n=20;

if (strcmp(mot,"strdup(selected)")==0)
		
{
    SDL_Surface *screen = NULL, *texte = NULL, *image = NULL;
    
    SDL_Event event;
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 0, 0};
    int continuer = 1;

    
    TTF_Init();

 screen=SDL_SetVideoMode(1600, 400, 32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Gestion du texte avec SDL_ttf", NULL);

 //image = IMG_Load("background.bmp");

    /* Chargement de la police */
    police = TTF_OpenFont("angelina.ttf", 65);
    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
    texte = TTF_RenderText_Blended(police, "felicitation", couleurNoire);

   
    
        

        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
  
        SDL_BlitSurface(image, NULL, screen, &positionecran); /* Blit du fond */

        
        SDL_BlitSurface(texte, NULL, screen, &positionecran); /* Blit du texte */
        SDL_Flip(screen);
    

    TTF_CloseFont(police);
    TTF_Quit();

    SDL_FreeSurface(texte);
    SDL_Quit();

    

}
            
            SDL_BlitSurface(image , NULL , screen  , &positionecran);
            SDL_Flip(screen);
            SDL_BlitSurface(sprite , NULL , screen  , &positionSprite);
            SDL_Flip(screen);
            SDL_BlitSurface(enigme , NULL , screen  , &positionSprite);
            SDL_Flip(screen);
        }
 
    


        SDL_FreeSurface(image);
        SDL_FreeSurface(sprite);
	 SDL_FreeSurface(enigme);
        
        SDL_Quit;
        return 0;
    }

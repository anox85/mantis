#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"

void menu(SDL_Surface *screen);
void jeu(SDL_Surface *screen);
int main (void);
void pause();



//fonction pause
void pause()
{
    int continuer = 1;
    SDL_Event event;
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}


//fonction menu

void menu(SDL_Surface *screen)
{
int bouclemenu=1,x,y;
Mix_Chunk *effect=NULL;
SDL_Surface *menu=NULL,*cur=NULL,*play=NULL,*setting=NULL,*out=NULL;
SDL_Rect positionmenu;
SDL_Rect positioncur;
SDL_Rect playpos;
SDL_Rect settingpos;
SDL_Rect outpos;

SDL_Event event;


//chargement image menu
positionmenu.x=0;
positionmenu.y=0;
menu= IMG_Load("menu.png");
SDL_BlitSurface(menu,NULL,screen, &positionmenu);

//chargement image play
playpos.x=250;
playpos.y=100;
play=IMG_Load("playtrans.png");
SDL_BlitSurface(play,NULL,screen,&playpos);

//chargement image settings
settingpos.x=250;
settingpos.y=190;
setting=IMG_Load("settingstrans.png");
SDL_BlitSurface(setting,NULL,screen,&settingpos);

//chargement image quit
outpos.x=250;
outpos.y=280;
out=IMG_Load("quittrans.png");
SDL_BlitSurface(out,NULL,screen,&outpos);

cur=IMG_Load("cur3.png");
SDL_BlitSurface(cur,NULL,screen,&positioncur);



while (bouclemenu)
{
    SDL_PollEvent(&event); /* Récupération de l'événement dans event */
    switch(event.type) /* Test du type d'événement */
    {
          
        case SDL_QUIT: /* Si c'est un événement de type "Quitter" */
		{
		bouclemenu= 0;
		SDL_Quit();
		}
        break;


	case SDL_MOUSEMOTION:
		x=event.motion.x;
		y=event.motion.y;
		positioncur.x=x;
		positioncur.y=y;

		//condition image play
		if(( x > playpos.x ) && ( x < playpos.x + playpos.w ) && ( y > playpos.y ) && ( y < playpos.y + playpos.h ))
			play=IMG_Load("play.png");
		else
			play=IMG_Load("playtrans.png");
		//condition image settings
		if(( x > settingpos.x ) && ( x < settingpos.x + settingpos.w ) &&( y > settingpos.y )&&( y < settingpos.y +settingpos.h))
			setting=IMG_Load("settings.png");
		else
			setting=IMG_Load("settingstrans.png");
		//condition image quit
		if(( x > outpos.x ) && ( x < outpos.x + outpos.w ) && ( y > outpos.y ) && ( y < outpos.y + outpos.h ))
			out=IMG_Load("quit.png");
		else
			out=IMG_Load("qiuttrans.png");

		break;
		case SDL_MOUSEBUTTONUP:
		if(( x > playpos.x ) && ( x < playpos.x + playpos.w ) && ( y > playpos.y ) && ( y < playpos.y + playpos.h ))
		jeu(screen);

		if(( x > outpos.x ) && ( x < outpos.x + outpos.w ) && ( y > outpos.y ) && ( y < outpos.y + outpos.h ))
		{
		Mix_PlayChannel( -1, effect,0);
		 bouclemenu=0;
		SDL_Quit();}

	break;
   }
          



    

SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
SDL_BlitSurface(menu,NULL,screen, &positionmenu);
SDL_BlitSurface(play,NULL,screen,&playpos);
SDL_BlitSurface(setting,NULL,screen,&settingpos);
SDL_BlitSurface(out,NULL,screen,&outpos);
SDL_BlitSurface(cur,NULL,screen,&positioncur);

SDL_Flip(screen);
}
pause();

SDL_FreeSurface(cur);
SDL_FreeSurface(menu);
SDL_FreeSurface(play);
SDL_FreeSurface(setting);
SDL_FreeSurface(out);



}

void jeu(SDL_Surface *screen)
{
SDL_Surface *fond=NULL,*image=NULL;
SDL_Rect positionfond;
SDL_Rect positionimage;

SDL_Event event;

positionfond.x=0;
positionfond.y=0;


fond= SDL_LoadBMP("background.bmp");

SDL_BlitSurface(fond,NULL,screen, &positionfond);


positionimage.x=200;
positionimage.y=200;
positionimage.w=100;

image=IMG_Load("detective.png");
SDL_SetColorKey(image, SDL_SRCCOLORKEY, SDL_MapRGB(image->format, 255, 255, 255));
SDL_BlitSurface(image,NULL,screen,&positionimage);

SDL_Flip(screen);



int done=1;
SDL_EnableKeyRepeat(10,10);
SDL_Event eventperso;
while (done)
{
    SDL_WaitEvent(&eventperso); /* Récupération de l'événement dans event */
SDL_Rect rect;
switch(eventperso.type) /* Test du type d'événement */
    {
        case SDL_QUIT: /* Si c'est un événement de type "Quitter" */
           {
		done = 0;
		SDL_Quit();
           }
        break;
	case SDL_KEYDOWN:
		    switch (eventperso.key.keysym.sym)
		    {
		        case SDLK_LEFT:
                    	positionimage.x-=10;
                    	if(positionimage.x <= rect.y) {
                        	positionimage.x= positionimage.x + 10;
                    }
                    break;
                	case SDLK_RIGHT:
		            positionimage.x+=10;
		            if(positionimage.x >= (rect.w-70)) {
		                positionimage.x= positionimage.x - 10;
                    }
                    break;
		        case SDLK_UP:
		            positionimage.y-=10;
		            if(positionimage.y <= rect.x) {
		                positionimage.y= positionimage.y + 10;
                    }
                    break;
		        case SDLK_DOWN:
		            positionimage.y+=10;
		            if(positionimage.y >= (rect.h - 170)) {
		                positionimage.y= positionimage.y - 10;
                    }
                    break;
			case SDLK_ESCAPE:
				menu(screen);
			break;
		    }
       break;
	
    }


SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
SDL_BlitSurface(fond,NULL,screen, &positionfond);
SDL_SetColorKey(image, SDL_SRCCOLORKEY, SDL_MapRGB(image->format, 255, 255, 255));
SDL_BlitSurface(image,NULL,screen,&positionimage);
SDL_Flip(screen);
}
SDL_FreeSurface(image);
SDL_FreeSurface(fond);
}


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

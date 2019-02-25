.#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
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
SDL_Flip(screen);

positionimage.x=200;
positionimage.y=200;
positionimage.w=100;

image=IMG_Load("detective.png");
SDL_SetColorKey(image, SDL_SRCCOLORKEY, SDL_MapRGB(image->format, 255, 255, 255));



SDL_BlitSurface(image,NULL,screen,&positionimage);

SDL_Flip(screen);



int done=1;
SDL_EnableKeyRepeat(10,10);
while (done)
{
    SDL_WaitEvent(&event); /* Récupération de l'événement dans event */
    switch(event.type) /* Test du type d'événement */
    {
        case SDL_QUIT: /* Si c'est un événement de type "Quitter" */
           {
 done = 0;
SDL_Quit();
            }
            break;
case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
                case SDLK_RIGHT: /* Appui sur la touche Echap, on arrête le programme */
                    positionimage.x+=5;
                    break;
                case SDLK_LEFT:
positionimage.x-=5;
                 break;
case SDLK_UP:
positionimage.y-=5;
break;
case SDLK_DOWN:
positionimage.y+=5;
break;
case SDLK_ESCAPE:
menu(screen);
break;
            }
            break;
case SDL_MOUSEMOTION:
positionimage.x=event.button.x;
positionimage.y=event.button.y;
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

void menu(SDL_Surface *screen)
{
int bouclemenu=1,x,y;
Mix_Chunk *effect=NULL;
SDL_Surface *menu=NULL,*cur=NULL,*play=NULL,*setting=NULL,*out=NULL;
SDL_Rect positionmenu;
SDL_Rect positioncur;
SDL_Rect positionannimation;
SDL_Rect playpos;
SDL_Rect settingpos;
SDL_Rect outpos;
effect = Mix_LoadWAV( "walk.wav" );

if( effect == NULL )
    {
        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
    }
         






playpos.x=250;
playpos.y=100;

settingpos.x=250;
settingpos.y=190;

outpos.x=250;
outpos.y=280;

SDL_Event event;


positionmenu.x=0;
positionmenu.y=0;





menu= IMG_Load("menu.png");

SDL_BlitSurface(menu,NULL,screen, &positionmenu);
//SDL_Flip(screen);






play=IMG_Load("playtrans.png");
SDL_BlitSurface(play,NULL,screen,&playpos);
//SDL_Flip(screen);

setting=IMG_Load("settingstrans.png");
SDL_BlitSurface(setting,NULL,screen,&settingpos);
//SDL_Flip(screen);

out=IMG_Load("quittrans.png");
SDL_BlitSurface(out,NULL,screen,&outpos);
//SDL_Flip(screen);



cur=IMG_Load("cur3.png");
SDL_BlitSurface(cur,NULL,screen,&positioncur);
//SDL_Flip(screen);










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
/*case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
                
case SDLK_UP:
positioncur.y-=77;
if(positioncur.y<132)
positioncur.y=286;
break;
case SDLK_DOWN:
positioncur.y+=77;

if(positioncur.y>286)
{
positioncur.y=132;
}
break;
case SDLK_SPACE:
if(positioncur.y==286)
{ bouclemenu=0;
SDL_Quit();}
if(positioncur.y==132)
jeu(screen);
break;
}
break;*/

case SDL_MOUSEMOTION:
x=event.motion.x;
y=event.motion.y;

positioncur.x=x;
positioncur.y=y;

if(( x > playpos.x ) && ( x < playpos.x + playpos.w ) && ( y > playpos.y ) && ( y < playpos.y + playpos.h ))

play=IMG_Load("play.png");

else
play=IMG_Load("playtrans.png");

if(( x > settingpos.x ) && ( x < settingpos.x + settingpos.w ) && ( y > settingpos.y ) && ( y < settingpos.y + settingpos.h ))
setting=IMG_Load("settings.png");
else
setting=IMG_Load("settingstrans.png");


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
int main (void)
{
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
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
           { 
           printf("%s",Mix_GetError());
           }
           musique=Mix_LoadMUS("music.wav");
           Mix_PlayMusic(musique, -1);


SDL_ShowCursor(SDL_DISABLE);
menu(screen);

pause();
Mix_FreeMusic(musique);

Mix_CloseAudio();
SDL_Quit();
return 0;
}

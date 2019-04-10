#ifndef HEYTHEM_H_
#define HEYTHEM_H_


#define TIME_BETWEEN_2_FRAMES 20

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

#define PLAYER_WIDTH 70
#define PLAYER_HEIGHT 115



#define YSAUT 8
#define GRAVITY 2

#define Collision_droite 20
#define Collision_gauche 30
#define Collision_top 40
#define Collision_bas 50



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define RIGHT 1
#define LEFT 2

#define MAX_FRAMES 6 
#define SPRITE_W 76
#define SPRITE_H 80
#define SPEED 10
#define PLAYER_ACCELERATION 18




#define ENEMY_Height 80
#define ENEMY_Width 76

#define Backg_W 8000
#define Backg_H 720

#define MAXF 8
#define MAXF_ENEMY 6

#define NON 0
#define OUI 1

#define LIFE_BAR_WIDTH 272
#define LIFE_BAR_HEIGHT 86

typedef struct Acteurs Acteurs;
struct Acteurs
{
	  SDL_Surface *screen;
    SDL_Event event ;

	//fond
	SDL_Surface *fond ;
	SDL_Rect posFond;

  //fond noir
  SDL_Surface* backg_collision;
  SDL_Surface* backg;
  SDL_Rect camera;

};

typedef struct Enemy Enemy ;
struct Enemy 
{

SDL_Surface *sprite , *sprite2  , *sprite3 , *sprite4 , *sprite5  , *sprite6 , *sprite7 , *sprite8 ;

/* Coordonnées de l'enemy */
int x , y , x2 , y2  , x3 , y3 , x4 , y4 ,x12,y12 , x5 , y5 , w5 , h5 , x6 , y6 , w6 , h6  , x7 , y7 , w7 , h7
, x8 , y8 , w8 , h8 ;


SDL_Rect frame;
//SDL_Rect dst;

};
typedef struct Hero Hero ;
struct Hero 
{

SDL_Surface *sprite;

/* Coordonnées du héros */
Sint16 x , y ;
Sint16 Ysaut;

 

float x1 , x2 , x3 , x4 , x5 , x6 , x7 , x8 , x9 , x10 , x11 , x12 , x13 , x14 , x15 , x16 ;  //points de verification de collision parfaite 
float y1 , y2 , y3 , y4 , y5 , y6 , y7 , y8 , y9 , y10 , y11 , y12 , y13 , y14 , y15 , y16 ;  // points de verification de collision parfaite 





};

int x ;
int y;
int verification_collision_player_map_droite(Acteurs* acteurs , Hero* hero) ;
SDL_Color GetPixel (SDL_Surface *pSurface , int x , int y) ;
void update_points_de_collisione2(Enemy *enemy,int x,int y );
void update_points_de_collisione(Enemy *enemy,int x,int y );








#endif /* HEYTHEM_H_ */


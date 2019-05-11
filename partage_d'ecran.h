#include <SDL/SDL.h>
#define largeur 1200
#define hauteur 600
typedef struct joueur joueur;

struct joueur
{
SDL_Surface *p[6];
SDL_Rect pp;
float x,y;
float vx,vy;
};

typedef struct background background;

struct background{
SDL_Surface *background;
SDL_Rect pb;
};

void initialiser_momo(joueur *j);
void initialiser_sousana(joueur *j);

void initialiser_background1(background *b1);
void initialiser_background2(background *b2);

void Render_momo(joueur *j1,SDL_Surface* screen);
void Render_sousana(joueur *j2,SDL_Surface* screen);





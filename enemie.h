#ifndef ENEMIE_H_
#define ENEMIE_H_

void deplacement_enemie_verticale (SDL_Rect ciseauxPosition);

void deplacement_papier_horizentale (SDL_Rect papierPosition) ;

void animation(SDL_Surface *ecran , SDL_Surface *ciseaux,  SDL_Surface *ciseaux2, SDL_Surface *papier, SDL_Surface *papier2 ,SDL_Rect positiondet);

#endif /* FONCTIONS_H_ */

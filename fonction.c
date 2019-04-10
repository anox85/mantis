#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include <SDL/SDL_ttf.h>
#include "header.h"


char *readStringSDL()//saisie avec clavier
{

	char *s_dst;
    SDL_Event event;
 
    size_t pos = 0;
    int unicode;
 
    SDL_EnableUNICODE(1);
 
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_RETURN:
                s_dst[pos] = '\n';
            break;
            default:
                unicode = event.key.keysym.unicode;
                if (unicode == 8 && pos > 0)
                {
                    s_dst[pos] = '\0';
                    pos--;
                }
                else
                    if (unicode >= 32 && unicode <= 127 && pos < 20)
                    {
                        s_dst[pos] = (char)unicode;
                        pos++;
                    }
             break;
             }
         break;
        }
    }
 
    SDL_EnableUNICODE(0);
 
    return s_dst;
}



char* choose_random_word() {

    char nomfich[20]="fich";
    size_t lineno = 0;
    size_t selectlen;
    char selected[256]; /* Arbitrary, make it whatever size makes sense */
    char current[256];
    selected[0] = '\0'; /* Don't crash if file is empty */

    nomfich = fopen(nomfich, "r"); /* Add your own error checking */
    while (fgets(current, sizeof(current), nomfich)) {
        if (drand48() < 1.0 / ++lineno) {
            strcpy(selected, current);
        }
    }
    fclose(nomfich);
    selectlen = strlen(selected);
    if (selectlen > 0 && selected[selectlen-1] == '\n') {
        selected[selectlen-1] = '\0';
    }
    return strdup(selected);
}




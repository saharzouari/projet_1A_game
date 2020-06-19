/**
* @file temps.c

*
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "temps.h"



Time Timer(Time t, int *tick)
{
    int tmp = t.mm * 60 + t.ss ;
    if( SDL_GetTicks() - *tick >= 1000 )
    {
        *tick = SDL_GetTicks() ;
        tmp--;
        if( tmp < 0 )
            tmp = 0 ;
        t.mm = tmp / 60 ;
        t.ss = tmp % 60 ;
    }
    return t;
}
void afficherTime(Time t)
{ SDL_Rect pos;
pos.x=0;

pos.y=0;
TTF_Font *Font = TTF_OpenFont("breakway.ttf",60);
SDL_Color couleur ={255,255,255};
char time_in_text[6];
sprintf(time_in_text,"%.2d:%.2d",t.mm,t.s);
SDL_Surface *time =TTF_RenderText_Blended(Font, time_in_text, couleur);
SDL_BlitSurface(time, NULL,screen,&pos);
}

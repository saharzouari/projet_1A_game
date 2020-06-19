/**
* @file sahar.c

*
*/
//Include SDL functions and datatypes
#include "SDL/SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "sahar.h"

int main( int argc, char* args[] )
{
TTF_Init();
    SDL_Surface *screen = NULL;
    SDL_Surface *image = NULL;
 //Start SDL

    //Set up screen
    screen = SDL_SetVideoMode( 1200, 600, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
     
     Mix_Music *music;
     music = Mix_LoadMUS("music.ogg");
     Mix_PlayMusic(music,-1);



   image = IMG_Load("bg.png");

   
   

   

   



  		perso p;
		camera c;
		enemie e;
		mini M;
		
		initialiserperso(&p);
		initialisercamera(&c,image);
		load_enemie (&e);
		//map (&M);

               SDL_Flip(image);
                SDL_Flip(screen);   
   
   SDL_Event event;
   
int done;

int tick=0;
int i=0;

   while(done)
    {
      
      //fps

	c.FrmEnd=SDL_GetTicks();//pour accelerer le jeu 
	
	

    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
           case SDL_QUIT:
           done = 0;
           break;
           case SDL_KEYDOWN:
            {
               
		if(event.key.keysym.sym==SDLK_ESCAPE) done = 0;

                if(event.key.keysym.sym==SDLK_RIGHT)
                   {
		   p.right=1;
		p.acc=-0.04;
		   p.ianim=1;
}
                if(event.key.keysym.sym==SDLK_LEFT)
                   {
		   p.left=1;
		p.acc=-0.04;
			}

                if(event.key.keysym.sym==SDLK_UP)
                  jump(&p);
			
		if(event.key.keysym.sym==SDLK_s)
		   p.sprint=1;p.maxtimer=4;
		
                
               break;
            }



case SDL_MOUSEBUTTONDOWN:
if(SDL_BUTTON_LEFT)
{
int k=event.motion.x;
int z=(p.posPlayer.x)-k;
if(z>0) {(p.left)=1;(p.ianim)=1;}
else {(p.right)=1;}}
break;


case SDL_MOUSEBUTTONUP :
{(p.right)=0;(p.left)=0;
break;
}



	case SDL_KEYUP:
	{
		

                if(event.key.keysym.sym==SDLK_RIGHT)
                   {p.right=0;p.ianim=0;}

                if(event.key.keysym.sym==SDLK_LEFT)
                   p.left=0;

		if(event.key.keysym.sym==SDLK_s)
		   p.sprint=0;p.maxtimer=4;

		
	}
        }
    }
	c.FrmEnd=SDL_GetTicks();
	deplacer_personnage(&p);
	annimation(&p);
	c=scrolling(c,&p);
	e=deplacement_aleatoire(e);
	annimation_enemie(&e);
	afficher(p,screen,image,c);
	afficher_enemie(e,image,screen);
	SDL_Flip(screen);
	
    }


    SDL_FreeSurface(screen);
    Mix_FreeMusic(music);
    SDL_FreeSurface(image);
    SDL_FreeSurface(p.image2);
    

   

    //Quit SDL
    SDL_Quit();

	
    
    return 0;
    

}

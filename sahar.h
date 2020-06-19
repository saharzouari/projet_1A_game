/**
* @file sahar.h

*
*/
#include "SDL/SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>


typedef struct perso
{
	SDL_Surface *image2;
	SDL_Rect posPlayer;
   	int done ;
   	int right,left,sprint;
  	 int maxspeed;
   	double xVel,yVel,canJump;
   	double v_jump;
   	double gravity ;
	int acc;
	int ianim,ianim_c,timer,maxtimer;
	char playerX[50];
	char animchar[50];
	TTF_Font *textF ;
}perso;

typedef struct
{
   
    SDL_Surface* imagemini;
SDL_Rect posmini;
SDL_Surface* imagenokta;
SDL_Rect posnokta;

}mini;

typedef struct camera
{
	SDL_Rect posdT;
	SDL_Rect pXR;
	SDL_Rect cXR;
	double FPS;
	int dT;
   double FrmStrt,FrmEnd;
	char DT[50];
	SDL_Rect cam;
	char camX[50];
}camera;

typedef struct enemie
{
	SDL_Surface *sprite ;
	SDL_Rect positionsprite;
	int actframe;
	int maxframe ;
	SDL_Rect frame ;
	int direction;
  	int distance;
  	int position_initiale;
}enemie ;

typedef struct vie
{
	
	SDL_Rect position;
	SDL_Surface *fond1;
	SDL_Surface *fond2;
	SDL_Surface *fond3;
	SDL_Surface *fond4;
	SDL_Surface *fond5;
        SDL_Surface *fond6;
}vie;

void initialiserperso(perso *p)
{

   	p->image2 = IMG_Load("wegf.png");
   	p->posPlayer.x=70;
   	p->posPlayer.y=150;
   	p->posPlayer.w=1200;
   	p->posPlayer.h=600;
   	p->done = 1;
   	p->maxspeed=5;
   	p->canJump=1;
   	p->v_jump = -7;
   	p->gravity = 0.2;
   	p->acc=0;
   	p->ianim=0;
   	p->ianim_c=1;
   	p->timer=0;
	p->maxtimer=4;
	p->textF = TTF_OpenFont("bebas.ttf", 20);
}

void initialisercamera(camera *c,SDL_Surface *image)
{
	c->FPS = 60;
   	c->posdT.x=200;
   	c->posdT.y=20;
   	c->pXR.x=200;
   	c->cXR.x=200;
   	c->pXR.y=40;
   	c->cXR.y=60;
   	c->FPS = 60;
   	c->dT;
   	c->FrmStrt=0;
   	c->FrmEnd=0;
	c->cam.x=0;
   	c->cam.y=0;
   	c->cam.w=image->w;
   	c->cam.h=image->h;
}



void deplacer_personnage(perso *p)
{
	
//x movement
	if(p->right==1) p->xVel+=0.3;
	if(p->left==1) p->xVel-=0.3;
	if(p->right ==0 && p->xVel>0.2) p->xVel-=0.1;
	if(p->left ==0 && p->xVel<-0.2) p->xVel+=0.1;

	if(p->right==0 && p->left ==0 && p->xVel>=-0.2 && p->xVel<0.2) p->xVel=0; //STOP threshhold

	//speed control
	if(p->sprint==1) p->maxspeed = 9;
	if(p->sprint==0) p->maxspeed = 5;

	p->posPlayer.x+=p->xVel;


	p->posPlayer.y+=p->yVel;
	p->yVel += p->gravity*2;




	

	if(p->posPlayer.y>400) {p->yVel=0;p->canJump=1;}
	if(p->posPlayer.y<400) p->canJump=0;

	if(p->xVel>p->maxspeed) p->xVel=p->maxspeed;
	if(p->xVel<-p->maxspeed) p->xVel=-p->maxspeed;
	
}

void annimation(perso *p)
{
	
	//animation
	p->timer++;
	if( p->timer>p->maxtimer  && p->canJump==1 )
	{
		if(p->right==1)
		{
		sprintf(p->animchar,"run/right/run%d.png",p->ianim_c);
		p->image2=IMG_Load(p->animchar);
		p->ianim_c++;
		if(p->ianim_c>8) p->ianim_c=1;
		p->timer=0;
		}
		if(p->left==1)
		{
		sprintf(p->animchar,"run/left/run%d.png",p->ianim_c);
		p->image2=IMG_Load(p->animchar);
		p->ianim_c++;
		if(p->ianim_c>8) p->ianim_c=1;
		p->timer=0;
		}
	}

	if(p->right==0 && p->left == 0) p->image2=IMG_Load("wegf.png");
	if(p->canJump==0 && p->xVel>=0) p->image2=IMG_Load("jump.png");
         if(p->canJump==0 && p->xVel<0) p->image2=IMG_Load("jump2.png");
	if(p->canJump==0 && p->xVel>=0 && p->yVel>0) p->image2=IMG_Load("fall.png");
	if(p->canJump==0 && p->xVel<0 && p->yVel>0) p->image2=IMG_Load("fall2.png");
}


void afficher(perso p,SDL_Surface *screen,SDL_Surface *image,camera c)
{
	SDL_BlitSurface(image,&c.cam,screen,NULL);
	SDL_BlitSurface(p.image2,NULL,screen,&p.posPlayer);
	

}

//jump
   void jump(perso *p)
	{
	if (p->canJump==1) p->yVel=p->v_jump;
	}

camera scrolling (camera c,perso *p)
{
	

	if(p->posPlayer.x>700 && -c.cam.x+c.cam.w>1210) {c.cam.x+=p->xVel;p->posPlayer.x=700;}
	if(p->posPlayer.x<300 && c.cam.x>10) {c.cam.x+=p->xVel;p->posPlayer.x=300;}
	if(p->posPlayer.x>1110 || p->posPlayer.x<0) p->xVel=0;

	c.dT=SDL_GetTicks()-c.FrmEnd;
	if (1000/c.FPS>c.dT)
	{
        SDL_Delay(1000/c.FPS-c.dT);
	}
	
	return c;


}

void load_enemie (enemie *e)
{
e->direction=0;
e->positionsprite.x=500 ;
e->positionsprite.y=400;
e->actframe=0;
e->maxframe=4;
e->frame.x=0 ;
e->frame.y=0;
e->frame.w = 88 ;
e->frame.h =80 ;
e->distance=120;
e->position_initiale=500;
}

void afficher_enemie(enemie e,SDL_Surface *background,SDL_Surface *ecran)
{
SDL_BlitSurface (e.sprite,&e.frame,ecran,&e.positionsprite);

}


void annimation_enemie(enemie *e)
{
e->actframe +=1 ;
        SDL_Delay(100);

if ( e->actframe > e->maxframe) 
{
e->actframe =0;
} 
e->frame.x= e->actframe * e->frame.w ;
}


enemie deplacement_aleatoire(enemie enemyy)
{
   if (enemyy.direction % 2 == 1)
   {
      if (enemyy.positionsprite.x < enemyy.position_initiale + enemyy.distance)
      {
         enemyy.positionsprite.x += 10;
	 enemyy.sprite=IMG_Load("aa.png");
	 
      }
      else
      {
         enemyy.direction++;
      }
   }
   else if (enemyy.direction % 2 == 0)
   {
      if (enemyy.positionsprite.x > enemyy.position_initiale)
      {
         enemyy.positionsprite.x -= 10;
	 enemyy.sprite=IMG_Load("bb.png");
      }
      else
      {
         enemyy.direction++;
      }
   }
   return (enemyy);
}


int collisionbb(perso p,enemie e)
{
 int x ; 
if ( ((p.posPlayer.y+p.posPlayer.h>=e.positionsprite.y)&&(p.posPlayer.y<=e.positionsprite.y+e.positionsprite.h)&&(p.posPlayer.x+p.posPlayer.w>=e.positionsprite.x)&&(p.posPlayer.x<=e.positionsprite.x+e.positionsprite.w)) )
{
	x=1 ; 
}

else x=0 ; 
return x ;
}
void initialiservie(vie *vie)
{

vie->position.x = 0 ;
vie->position.y = 0 ;
vie->fond1 = IMG_Load("1.png");
vie->fond2 = IMG_Load("2.png");
vie->fond3 = IMG_Load("3.png");
vie->fond4 = IMG_Load("4.png");
vie->fond5 = IMG_Load("5.png");
vie->fond6 = IMG_Load("6.jpg");

}

/*void affichervie(vie *vie,perso *p ,enemie e,SDL_Surface *ecran , int *i )
{
 int k=collisionbb(*p,e);

if(k==1)
{
(p->posPlayer).x=0;
(*i)++;
}

if((*i)==0)
{

SDL_BlitSurface(vie->fond1,NULL, ecran,&vie->position);
SDL_Flip(ecran);
}

else if((*i)==1)
{

SDL_BlitSurface(vie->fond2,NULL, ecran,&vie->position);
SDL_Flip(ecran);
}
else if((*i)==2)
{
//(*posj).x=0;
SDL_BlitSurface(vie->fond3,NULL, ecran,&vie->position);
SDL_Flip(ecran);
}
 else if((*i)==3)
{
//(*posj).x=0;
SDL_BlitSurface(vie->fond4,NULL, ecran,&vie->position);
SDL_Flip(ecran);
}
else if((*i)==4)
{
//(*posj).x=0;
SDL_BlitSurface(vie->fond5,NULL, ecran,&vie->position);
SDL_Flip(ecran);
}
 else if((*i)==5)
{
//(*posj).x=0;
SDL_BlitSurface(vie->fond6,NULL, ecran,&vie->position);
SDL_Flip(ecran);
}

//strsep(5);


}*/

void map (mini *M)
{

M->imagemini=IMG_Load("mini.png");
M->imagenokta=IMG_Load("nokta.png");
M->posmini.x=180;
M->posmini.y=20;
M->posnokta.x=320;
M->posnokta.y=50;


}
void afficherMAP (mini M,SDL_Surface *ecran)
{
SDL_BlitSurface(M.imagemini,NULL,ecran,&M.posmini);
SDL_BlitSurface(M.imagenokta,NULL,ecran,&M.posnokta);
}

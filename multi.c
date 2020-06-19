/**
* @file main.c
* @brief partage d ecran.
* @author black diamond
* @version 0.19
* @date juin 18, 2020
*
* testing program for multiplayer 
*
*/
void loadPlayer(void)
{

        for(hero.i=0;hero.i<18;hero.i++){
		    sprintf( hero.imageHeroFile,"perso/right/%d.png",hero.i+1);
		if(hero.rightImage[hero.i])
			SDL_FreeSurface(hero.rightImage[hero.i]);
       	hero.rightImage[hero.i] = IMG_Load(hero.imageHeroFile);
	}



	for(hero.k=0;hero.k<22;hero.k++)
	{
		sprintf( hero.imageHeroFile,"perso/left/%d.png",hero.k+1);
		if(hero.leftImage[hero.k])
			SDL_FreeSurface(hero.leftImage[hero.k]);
		hero.leftImage[hero.k] = IMG_Load(hero.imageHeroFile);
	}


	for(hero.l=0;hero.l<12;hero.l++){
		sprintf( hero.imageHeroFile,"perso/down/%d.png",hero.l+1);
		if(hero.downImage[hero.l])
			SDL_FreeSurface(hero.downImage[hero.l]);
		hero.downImage[hero.l] = IMG_Load(hero.imageHeroFile);
	}


	for(hero.f=0;hero.f<11;hero.f++){
		sprintf( hero.imageHeroFile,"perso/up/%d.png",hero.f+1);
		if(hero.upImage[hero.f])
			SDL_FreeSurface(hero.upImage[hero.f]);
		hero.upImage[hero.f] = IMG_Load(hero.imageHeroFile);
		}
}

*/

void loadmultiPlayer(void)
{
         for(hero2.i=0;hero2.i<18;hero2.i++){
		sprintf( hero2.imageHeroFile,"perso/right/%d.png",hero2.i+1);
		if(hero2.rightImage[hero2.i])
			SDL_FreeSurface(hero2.rightImage[hero2.i]);
		hero2.rightImage[hero2.i] = IMG_Load(hero2.imageHeroFile);
		}



	for(hero2.k=0;hero2.k<22;hero2.k++)
	{
		sprintf( hero2.imageHeroFile,"perso/left/%d.png",hero2.k+1);
		if(hero2.leftImage[hero2.k])
		SDL_FreeSurface(hero2.leftImage[hero2.k]);
			hero2.leftImage[hero2.k] = IMG_Load(hero2.imageHeroFile);
	}


	for(hero2.l=0;hero2.l<12;hero2.l++){
		sprintf( hero2.imageHeroFile,"perso/down/%d.png",hero2.l+1);
		if(hero2.downImage[hero2.l])
			SDL_FreeSurface(hero2.downImage[hero2.l]);
		hero2.downImage[hero2.l] = IMG_Load(hero2.imageHeroFile);
	}


	for(hero2.f=0;hero2.f<11;hero2.f++){
		sprintf( hero2.imageHeroFile,"perso/up/%d.png",hero2.f+1);
		if(hero2.upImage[hero2.f])
		SDL_FreeSurface(hero2.upImage[hero2.f]);
		hero2.upImage[hero2.f] = IMG_Load(hero2.imageHeroFile);
	    }
}


void initializePlayer(void)
   {
       loadPlayer();
       /* Charge le sprite de notre héros */

       	hero.sprite = IMG_Load("perso/right/1.png");
	    Enemy.sprite=IMG_Load("perso.png");
       	hero.upcounter = 1;
       	hero.downcounter= 1;
       	hero.leftcounter= 1;
       	hero.rightcounter= 1;
       	hero.score=0;
	//Indique l'état et la direction de notre héros
    	hero.direction = RIGHT;
    	hero.etat = WALK;
    	//Réinitialise le timer de l'animation et la frame
   	hero.frameNumber = 0;
    	hero.frameTimer = TIME_BETWEEN_2_FRAMES;
     	/* Coordonnées de démarrage de notre héros */
    	hero.x=(6160*map.zoom)-map.camera.x;
	hero.y=(6512*map.zoom)-map.camera.y;
	hero.score=0;
	Enemy.x=(6700*map.zoom);
	Enemy.y=(6690*map.zoom);
	hero.speed=5;
	hero.speed_tick=0;
}


void initializemultiPlayer(void){
       	loadPlayer();
	loadmultiPlayer();
       	/* Charge le sprite de notre héros */

       	hero.sprite = IMG_Load("perso/right/1.png");
        hero2.sprite = IMG_Load("perso/right/2.png");
       	hero.upcounter = 1;
       	hero.downcounter= 1;
       	hero.leftcounter= 1;
       	hero.rightcounter= 1;
       	hero.score=0;
        hero2.upcounter = 1;
       	hero2.downcounter= 1;
       	hero2.leftcounter= 1;
       	hero2.rightcounter= 1;
       	hero2.score1=0;
	//Indique l'état et la direction de notre héros
	hero.direction = RIGHT;
	hero.etat = WALK;
   	hero2.direction = RIGHT;
   	hero2.etat = WALK;
	//Réinitialise le timer de l'animation et la frame
	hero.frameNumber = 0;
	hero.frameTimer = TIME_BETWEEN_2_FRAMES;
	hero2.frameNumber = 0;
	hero2.frameTimer = TIME_BETWEEN_2_FRAMES;


	/* Coordonnées de démarrage de notre héros */
	hero.x = 300;
	hero.y =300-(hero.sprite->h);
	hero.speed=5;
	hero.speed_tick=0;
	/* Coordonnées de démarrage de notre héros */
	hero2.x = 300;
	hero2.y =300-(hero2.sprite->h);
	hero2.speed=5;
	hero2.speed_tick=0;
   }



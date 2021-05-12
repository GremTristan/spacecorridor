#include "manage_texture.h"
#include "manage_data.h"
#include <stdio.h>

#include "sdl2-light.h"
#include "sdl2-ttf-light.h"

/**
 * \brief La fonction gère les évènements ayant eu lieu et qui n'ont pas encore été traités
 * \param event paramètre qui contient les événements
 * \param world les données du monde
 */

void handle_events(SDL_Event *event,world_t *world){
    Uint8 *keystates;
    while( SDL_PollEvent( event ) ) {
        
        
        //Si l'utilisateur a cliqué sur le X de la fenêtre
        if( event->type == SDL_QUIT ) {
            //On indique la fin du jeu
            world->game = 0;
        }
       
        //si une touche est appuyée
        if(event->type == SDL_KEYDOWN){
            //si la touche appuyée est 'D'
            if(event->key.keysym.sym == SDLK_d){
                printf("La touche D est appuyée\n");
            }
            // si la flèche gauche est appuyée
            if(event->key.keysym.sym == SDLK_LEFT){
                world->vaisseau.x-=MOVING_STEP;
                
            }
            // si la flèche droite est appuyée
            if(event->key.keysym.sym == SDLK_RIGHT){
                world->vaisseau.x+=MOVING_STEP;
                
            }
            // si la flèche du haut est appuyée
            if(event->key.keysym.sym == SDLK_UP){
                
                world->vy+=1;
            }
            // si la flèche du bas est appuyée
            if(event->key.keysym.sym == SDLK_DOWN){
               
                world->vy-=1;
            }
            // si la touche appuyée est 'echap'
            if(event->key.keysym.sym == SDLK_ESCAPE){
                world->game = 0;
            }
        }
    }
}


/**
 * \brief La fonction gère le temps écoulé dans le jeu
 */

unsigned int timer(){
	return (SDL_GetTicks())/1000;
}


/**
 * \brief La fonction met à jour le timer du jeu
 * \param world le monde
 */

void update_timer(world_t * world){
	if((world->win!=1)&&(world->gameover!=1)){
		world->temps_ecoule = timer();
	   }
}
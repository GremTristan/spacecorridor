/**
 * \file main.c
 * \brief Programme principal initial du niveau 1
 * \author Mathieu Constant
 * \version 1.0
 * \date 18 mars 2021
 */

#include "sdl2-light.h"
#include "sdl2-ttf-light.h"



#include "manage_texture.h"
#include "manage_data.h"
#include "manage_events.h"



/**
 * \brief Largeur de l'écran de jeu
 */
#define SCREEN_WIDTH 300

/**
 * \brief Hauteur de l'écran de jeu
 */
#define SCREEN_HEIGHT 480


/**
 * \brief Taille d'un vaisseau
 */

#define SHIP_SIZE 20


/**
 * \brief Taille d'un météorite
*/

#define METEORITE_SIZE 32


/**
 * \brief Hauteur de la ligne d'arrivée
 */


#define FINISH_LINE_HEIGHT -1000


/**
 * \brief Pas de déplacement horizontal du vaisseau
*/

#define MOVING_STEP 4


/**
  * \brief Vitesse initiale de déplacement vertical des éléments du jeu
*/

#define INITIAL_SPEED 1


#define L 6





/**
 *  \brief programme principal qui implémente la boucle du jeu
 */



int main( int argc, char* args[] ){

	//initialisation des données générales
	SDL_Event event;
    world_t world;
    textures_t textures;
    SDL_Surface *surface;
    SDL_Renderer *renderer;
    SDL_Window *window;
    SDL_Surface *screen;
    
    surface =  SDL_LoadBMP("ressources/bird.bmp");
  
    init(&window,&renderer,&textures,&world); //initialisation du jeu
    SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );
    world.game=1;  //initialisation de la boucle de jeu
      
    while(world.game==1){ //tant que le jeu n'est pas fini
        	
        refresh_graphics(renderer,&world,&textures); //rafraichissement de l'écran
       
       apply_surface(0,0,surface,screen,&world);

        update_data(&world); //mise à jour des données liée à la physique du monde
       
        handle_events(&event,&world);  //gestion des évènements
        
		update_timer(&world);   //mise à jour du timer
		 
        pause(10);	   
      
    }
	
    return 0;
}

#include "manage_texture.h"
#include "sdl2-light.h"
#include "manage_data.h"
#include <stdio.h>
#include "manage_events.h"
#include "sdl2-ttf-light.h"





/**
 * \brief fonction qui initialise le jeu: initialisation de la partie graphique (SDL), chargement des textures, initialisation des données
 * \param window la fenêtre du jeu
 * \param renderer le renderer
 * \param textures les textures
 * \param world le monde
 */

void init(SDL_Window **window, SDL_Renderer ** renderer, textures_t *textures, world_t * world){
    init_sdl(window,renderer,SCREEN_WIDTH, SCREEN_HEIGHT);
    init_data(world);
    init_textures(*renderer,textures);

    
}


void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, world_t* world)
{
    SDL_Rect offset;
 
    offset.x = x;
    offset.y = y;
 
    //On blitte la surface
    SDL_BlitSurface( source, world->clip, destination, &offset );
}

void clip_sprite(world_t *world){
     //On coupe la partie en haut à gauche (premier sprite)
    world->clip[ 0 ].x = 0;
    world->clip[ 0 ].y = 0;
    world->clip[ 0 ].w = 50;
    world->clip[ 0 ].h = 35;
 
    //On coupe la partie en haut à droite (second sprite)
    world->clip[ 1 ].x = 50;
    world->clip[ 1 ].y = 0;
    world->clip[ 1 ].w = 64;
    world->clip[ 1 ].h = 35;
 
    //On coupe la partie en bas à gauche (troisième sprite)
    world->clip[ 2 ].x = 114;
    world->clip[ 2 ].y = 0;
    world->clip[ 2 ].w = 37;
    world->clip[ 2 ].h = 32;
}
/**
* \brief fonction qui nettoie le jeu: nettoyage de la partie graphique (SDL), nettoyage des textures, nettoyage des données
* \param window la fenêtre du jeu
* \param renderer le renderer
* \param textures les texturesz
* \param world le monde
*/


void clean(SDL_Window *window, SDL_Renderer * renderer, textures_t *textures, world_t * world){
    clean_data(world);
    clean_textures(textures);
    clean_sdl(renderer,window);
}

/**
 * \brief La fonction initialise les textures nécessaires à l'affichage graphique du jeu
 * \param screen la surface correspondant à l'écran de jeu
 * \param textures les textures du jeu
*/

void init_textures(SDL_Renderer *renderer, textures_t *textures){
    
    textures->background = load_image( "ressources/wallpaper.bmp",renderer);
    textures->texture_vaisseau = load_image( "ressources/fusee.bmp", renderer);
    textures->texture_finish_line = load_image( "ressources/barre.bmp", renderer);
    textures->texture_meteorite = load_image( "ressources/nuage.bmp", renderer);
	textures->font = load_font("ressources/arial.ttf",35);
    
    
}

/**
 * \brief La fonction applique la texture du fond sur le renderer lié à l'écran de jeu
 * \param renderer le renderer
 * \param texture la texture liée au fond
*/

void apply_background(SDL_Renderer *renderer, SDL_Texture *texture){
    if(texture != NULL){
      apply_texture(texture, renderer, 0, 0);
    }
}


/**
 * \brief La fonction applique la texture du sprite sur le renderer lié à l'écran de jeu
 * \param renderer le renderer
 * \param texture la texture liée au sprite
*/

void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite){
    if(texture != NULL){
      apply_texture(texture, renderer, sprite->x, sprite->y);
    }
}


/**
 * \brief La fonction applique la texture du mur d'astéroïdes sur le renderer lié à l'écran de jeu
 * \param renderer le renderer
 * \param texture la texture liée au mur d'astéroïdes
 * \param sprite le sprite
 * \param nb_mur_x le nombre d'astéroïdes composant le mur horizontalement
 * \param nb_mur_y le nombre d'astéroïdes composant le mur verticalement
*/

void apply_mur(SDL_Renderer *renderer, world_t *world, textures_t *textures){
//    //Initialisataion des positions en x et y pour éviter d'écraser les données du pointeur
//    int nb1=sprite->x;
//    int nb2=sprite->y;
//    int i, j;
//    if(texture != NULL){
//        for(i=0; i<nb_mur_x; i++){
//            //On applique nb_mur_y fois de ligne d'astéroïdes
//            for(j=0; j<nb_mur_y; j++){
//                //On applique nb_mur_x fois de colonne d'astéroïdes
//                apply_texture(texture, renderer, nb1, nb2);
//                nb1+=METEORITE_SIZE;
//            }
//            //On réinitialise la position en x de la ligne suivante
//            nb1=sprite->x;
//            nb2+=METEORITE_SIZE;
//        }
//    }
//}
//
    for (int k = 0 ; k < L ; k ++){
        int h = world->tab_mur[k].h/METEORITE_SIZE;
        int w = world->tab_mur[k].w/METEORITE_SIZE;
        for (int i = 0 ; i < h ; i ++){
            for (int j = 0 ; j < w ; j++){
                apply_texture(textures->texture_meteorite ,renderer, (world->tab_mur[k].x +j*METEORITE_SIZE)-(METEORITE_SIZE/2), world->tab_mur[k].y + i*METEORITE_SIZE);

            }
        }
    }
}



/**
 * \brief La fonction rafraichit l'écran en fonction de l'état des données du monde
 * \param renderer le renderer lié à l'écran de jeu
 * \param world les données du monde
 * \param textures les textures
 */

void refresh_graphics(SDL_Renderer *renderer, world_t *world, textures_t *textures){
    
    //on vide le renderer
    clear_renderer(renderer);
    
    //application des textures dans le renderer
    apply_background(renderer, textures->background);
	
    apply_mur(renderer, world,textures);
    apply_mur(renderer, world,textures);
    apply_mur(renderer, world,textures);
    apply_mur(renderer, world,textures);
     
    apply_sprite(renderer, textures->texture_finish_line, &world->finish_line);

    apply_sprite(renderer, textures->texture_vaisseau, &world->vaisseau);

	int temps= world->temps_ecoule;
	char timer[100];
	sprintf(timer, "TIMER : %u", temps);
	apply_text(renderer, 10, 5, 150, 50, timer, textures->font);
	
	if((world->win)==1){
		apply_text(renderer, ((SCREEN_WIDTH/2))-75, ((SCREEN_HEIGHT/2)-80), 150, 80, "WIN", textures->font);
		char win1[100];
		sprintf(win1, "Vous avez fini en %u sec", temps);
		apply_text(renderer, 50, ((SCREEN_HEIGHT/2)), 200, 90, win1, textures->font);
	}
	
	if((world->gameover)==1){
		apply_text(renderer, ((SCREEN_WIDTH/2))-75, ((SCREEN_HEIGHT/2)-80), 150, 80, "GAME OVER", textures->font);
		pause(500);
		world->game=0;
	}		
	
	
    // on met à jour l'écran
    update_screen(renderer);
}


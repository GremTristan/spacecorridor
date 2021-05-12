//
//  manage_texture.h
//
//
//  Created by Tristan Gremling on 29/03/2021.
//
#ifndef manage_texture_h
#define manage_texture_h

#include <stdio.h>
#include "manage_data.h"
#include "sdl2-light.h"
#include "sdl2-ttf-light.h"

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
 * \brief Représentation pour stocker les textures nécessaires à l'affichage graphique
*/

struct textures_s{
    SDL_Texture* background; /*!< Texture liée à l'image du fond de l'écran. */
    SDL_Texture* texture_vaisseau; /*!< Texture lié au vaisseau. */
    SDL_Texture* texture_finish_line; /*!< Texture lié à la ligne d'arrivée. */
    SDL_Texture* texture_meteorite; /*!< Texture lié à une météorite. */
	TTF_Font * font; /*!< Texture lié à la police d'écriture. */
};


/**
 * \brief Type qui correspond aux textures du jeu
*/

typedef struct textures_s textures_t;




/**
 * \brief Type qui correspond aux données du monde
 */

typedef struct world_s world_t;

/**
 * \brief Type qui correspond aux données des textures
 */


typedef struct textures_s textures_t;

/**
 * \brief Type qui correspond aux données du sprite
 */

typedef struct sprite_s sprite_t;

/**
 * \brief Représentation d'un sprite
*/



void init(SDL_Window **window, SDL_Renderer ** renderer, textures_t *textures, world_t * world);

void clean(SDL_Window *window, SDL_Renderer * renderer, textures_t *textures, world_t * world);

void init_textures(SDL_Renderer *renderer, textures_t *textures);


void apply_background(SDL_Renderer *renderer, SDL_Texture *texture);


void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite);


void apply_mur(SDL_Renderer *renderer, world_t *world, textures_t *textures);


void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, world_t* world);

void clip_sprite(world_t *world);

void refresh_graphics(SDL_Renderer *renderer, world_t *world,textures_t *textures);


#endif /* manage_texture_h */

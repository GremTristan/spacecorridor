#ifndef manage_events_h
#define manage_events_h

#include <stdio.h>
#include "manage_data.h"
#include "sdl2-light.h"

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






void handle_events(SDL_Event *event,world_t *world);

unsigned int timer();

void update_timer(world_t * world);


#endif /* manage_events_h */

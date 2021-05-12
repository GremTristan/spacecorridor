//
//  manage_data.h
//  
//
//  Created by Tristan Gremling on 29/03/2021.
//

#ifndef manage_data_h
#define manage_data_h

#include <stdio.h>


#include "manage_texture.h"
#include "sdl2-light.h"


#define L 6





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

struct sprite_s{
    int x; /*!< Champ indiquant la position en x du centre du sprite */
    int y; /*!< Champ indiquant la position en y du centre du sprite */
    int h; /*!< Champ indiquant la hauteur du sprite */
    int w; /*!< Champ indiquant la largeur du sprite */
};





/**
 * \brief Représentation du monde du jeu
*/

struct world_s{
    sprite_t vaisseau; /*!< Champ représentant le vaisseau */
    sprite_t finish_line; /*!< Champ représentant la ligne d'arrivée */
    sprite_t mur; /*!< Champ représentant un mur de météorites */
    sprite_t tab_mur[L] ;/*!< Champ représentant les murs de météorites */
    int frametime;
    int vy ; /*!< Champ représentant la vitesse d'un sprite */
    int gameover; /*!< Champ indiquant si l'on est à la fin du jeu */
    int win;/*!< Champ indiquant si l'on a franchie la ligne  */
    SDL_Rect clip[3];
	int game;
    int temps_ecoule;

};


/**
 * \brief La fonction initialise le sprite
 * \param sprite les données du sprite
 * \param x et y les coordonnées du centre du sprite
 * \param w et h respectivement la largeur et la hauteur du sprite
 */
 void init_sprite(sprite_t *sprite, int x, int y, int w, int h);


/**
 * \brief La fonction initialise les murs
 * \param sprite les données des différents murs
 * \param x et y les coordonnées du centre des murs
 * \param w et h respectivement la largeur et la hauteur des murs
 */
void init_mur(world_t *world, int x, int y, int w, int h, int i);


/**
 * \brief La fonction nettoie les textures
 * \param textures les textures
*/
void clean_textures(textures_t *textures);


/**
 * \brief La fonction initialise les données du tableau de murs
 * \param world les données du monde
 */
void init_tab_mur(world_t * world);


/**
 * \brief La fonction initialise les données du monde du jeu
 * \param world les données du monde
 */
void init_data(world_t * world);


/**
 * \brief La fonction gère les collisions entre 2 sprites
 * \param sp1 sprite mur
 * \param sp2 sprite vaisseau
 * \param world le monde
 */
void sprites_collide(sprite_t *sp1, sprite_t *sp2, world_t * world);


/**
 * \brief La fonction met à jour les données des murs
 * \param world les données du monde
 */
void update_mur(world_t * world);


/**
 * \brief La fonction met à jour les données en tenant compte de la physique du monde
 * \param world les données du monde
 */
void update_data(world_t *world);


 /**
 * \brief La fonction teste les collisions entre les murs et le vaisseau
 * \param world les données du monde
 */
void test_collide(world_t * world);


/**
 * \brief La fonction indique si le jeu est fini en fonction des données du monde
 * \param world les données du monde
 * \return 1 si le jeu est fini, 0 sinon
 */
int is_game_over(world_t *world);



/**
 * \brief La fonction nettoie les données du monde
 * \param world les données du monde
 */
void clean_data(world_t *world);


/**
 * \brief La fonction gère les limites
 * \param world les données du monde
 */
void limite();



#endif /* manage_data_h */

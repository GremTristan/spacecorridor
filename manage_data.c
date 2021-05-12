//
//  manage_data.c
//  
//
//  Created by Tristan Gremling on 29/03/2021.
//
#include "manage_texture.h"
#include "manage_data.h"
#include <stdio.h>

#include "sdl2-light.h"
#include "manage_events.h"
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



 
 
 void init_sprite(sprite_t *sprite, int x, int y, int w, int h){
    sprite->x=x;
    sprite->y=y;
    sprite->w=w;
    sprite->h=h;
 }


void init_mur(world_t *world, int x, int y , int w , int h, int i){
    
    
    world->mur.x = x;
    world->mur.y = y;
    world->mur.h = h;
    world->mur.w = w;
    world->tab_mur[i] = world->mur;
    
}
 

void clean_textures(textures_t *textures){
    clean_texture(textures->background);
    clean_texture(textures->texture_vaisseau);
    clean_texture(textures->texture_finish_line);
    clean_texture(textures->texture_meteorite);
	clean_font(textures->font);
}

 
void init_tab_mur(world_t * world){
	
    init_mur(world,48,0,96,192,0);
    init_mur(world,252,0,96,192,1);
    init_mur(world,16,-352,32,160,2);
    init_mur(world,188,-352,224,160,3);
    init_mur(world,48,-672,96,192,4);
    init_mur(world,252,-672,96,192,5);
	
 }


void init_data(world_t * world){
	
	
	//Initialisation de l'environnement TTF
	init_ttf();
	
	
	
    //on initialise les données du vaisseau
    
    init_sprite(&world->vaisseau,(SCREEN_WIDTH-SHIP_SIZE)/2,SCREEN_HEIGHT-(2*SHIP_SIZE),SHIP_SIZE,SHIP_SIZE);
   
    
    

    //Initialisation des données de la ligne d'arrivée
    init_sprite(&world->finish_line,0,FINISH_LINE_HEIGHT,0,0);
    
    
    //Initialisation de la vitesse
    world->vy=0;
    
    //Initialisation des murs de météorites
    
   init_tab_mur(world);
    
    
    //on n'est pas à la fin du jeu
    world->gameover = 0;
    world->win = 0;
    
}

 
void sprites_collide(sprite_t *sp1, sprite_t *sp2, world_t * world){
//  formules pour calculers
    if((abs((sp1->x)+((sp1->w-SHIP_SIZE)/2)-(sp2->x))<=((sp1->w-SHIP_SIZE)+(sp2->w-SHIP_SIZE))/2)&&(abs((sp1->y)+((sp1->h-SHIP_SIZE)/2)-(sp2->y))<=((sp1->h-SHIP_SIZE)+(sp2->h-SHIP_SIZE))/2)){
        world->vy=0;
        printf("perdu !\n");
        world->gameover=1;
    }
 }

 
void update_mur(world_t * world){
	for(int i = 0;i < 6;i++){
       (world->tab_mur[i].y)+=(world->vy ); // Incrémentation de la vitesse sur le mur d'astéroïde
    }
}
 
 
 void test_collide(world_t * world){
	for(int i = 0; i < 6 ; i++){
        sprites_collide(&world->tab_mur[i], &world->vaisseau, world);
    }    
 }


void update_data(world_t *world){

    world->finish_line.y+=world->vy; //Incrémentation de la vitesse sur la ligne d'arrivée
    
	update_mur(world);  // Incrémentation de la vitesse sur le mur d'astéroïde

	test_collide(world); // Test des colissions entre les élements
    
    limite(world);  // Définition des limites du monde
    

}


int is_game_over(world_t *world){
    return world->gameover;
}

int is_game_win(world_t *world){
    return world->win;
}


void clean_data(world_t *world){
    /* utile uniquement si vous avez fait de l'allocation dynamique (malloc); la fonction ici doit permettre de libérer la mémoire (free) */
    
}


void limite(world_t *world){
    
    if (world->vaisseau.x < 0){
        world->vaisseau.x = 1;
    }
    if (world->vaisseau.x > 270){
        world->vaisseau.x = 269;
    }
    if(world->vaisseau.y <= world->finish_line.y){
       world->vy = 0;
	   world->win = 1;
    }
}





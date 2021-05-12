//
//  test.h
//  
//
//  Created by Tristan Gremling on 29/03/2021.
//

#ifndef teste_h
#define teste_h

#include <stdio.h>
#include "manage_data.h"
#include "sdl2-light.h"


void teste_init_sprite(sprite_t *sprite, int x, int y, int w, int h);

void teste_init_mur(world_t *world, int x, int y, int w, int h, int i);


void teste_clean_textures(textures_t *textures);

void teste_init_data(world_t * world);

void teste_update_data(world_t *world);

void teste_is_game_over(world_t *world);

void teste_clean_data(world_t *world);

void teste_limite();

void teste_sprites_collide(sprite_t *sp1, sprite_t *sp2, world_t * world);

#endif /* test_h */

//
//  teste.c
//  
//
//  Created by Tristan Gremling on 29/03/2021.
//

#include "test.h"
#include "manage_data.h"








void teste_init_sprite(sprite_t *sprite, int x, int y, int w, int h){
    init_sprite(sprite, x, y, w, h);
    printf("Coordonnées sprites x: |%d| y: |%d| w: |%d| h: |%d|",sprite->x,sprite->y,sprite->w,sprite->h);
}

void teste_init_mur(world_t *world, int x, int y, int w, int h, int i){
            //   int_mur(world, x ,y ,w,h,i);
            //   for(int a = 0 ; a<i ; a++){
            //       printf("Coordonnées mur |%d|    x: |%d| , y: |%d|\n",world->tab_mur[i].x,world->tab_mur[i].y);
            //   }
            //   print_sprite(&world->mur);
            init_mur(world,x,y,w,h,i);
            printf("Coordonnées mur |%d| x: |%d| y: |%d| w: |%d| h: |%d|",i ,world->tab_mur[i].x,world->tab_mur[i].y,world->tab_mur[i].w,world->tab_mur[i].h);
}



void teste_is_game_over(world_t *world){
    sprite_t *sp1,*sp2;
    sprites_collide(sp1,sp2,world);
    is_game_over(world);
}

void teste_clean_data(world_t *world);

void teste_limite(world_t *world){
 printf("Coordonnés des limites x: |%d| -x: |%d| y: |%d|",0,270,world->finish_line.y);

}

void teste_sprites_collide(sprite_t *sp1, sprite_t *sp2, world_t * world){
    sprites_collide(sp1,sp2,world);
    printf("Coordonnées de colission x : |%d| , y: |%d|", sp1->x , sp1->y);

}

int main(){

    world_t *world;
    
    teste_init_sprite(&world->vaisseau,0,0,30,20);
    teste_init_mur(world,10,10,10,10,0);
    teste_is_game_over(world);
    teste_limite(world);
    teste_sprites_collide(&world->vaisseau,&world->tab_mur[1],world);

   
}


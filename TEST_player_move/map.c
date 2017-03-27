/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "map.h"
#include "ze engine.h"
#include "Llist.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "curses.h"
#include "object.h"
#include "wall.h"
#include "player.h"
#include "cacti.h"
#include "box.h"
#include "dog.h"
#include "enemy.h"
#include "map.h"
#include <stdbool.h>
#include <time.h>

void MAP_populate(map_t *map)
{
    int8_t x;
    int8_t y;
    object_t *object;
    char coord;

    for(y = 0; y < SCREEN_H; y++)
    {
        for(x = 0; x < SCREEN_W; x++)
        {
            coord = *(map->map_data + x + (y * SCREEN_W));
            if(coord == 'W')
            {
                object = LLIST_push(&worldObjects, sizeof(wall_t));

                WALL_init((wall_t*) object, x, y, TRUE, 5);

            }
            if(coord == 'C')
            {
                object = LLIST_push(&worldObjects, sizeof(cacti_t));
                CACTI_init((cacti_t*) object, x, y);
                
            }
            if(coord == 'B')
            {
                object = LLIST_push(&worldObjects, sizeof(box_t));
                BOX_init((box_t*)object,x,y);
                
            }
            if(coord == 'P')
            {
               object = LLIST_push(&worldObjects, sizeof(_player_t)); 
               PLAYER_init((_player_t*)object, x,y);
               
               player1 = (_player_t*)object;
            }
            if(coord == 'R')
            {
                object = LLIST_push(&worldObjects, sizeof(dog_t)); 
                DOG_init((dog_t*)object,x,y);
                
                
            }
        }
    }
}
#if 1
char TEST_map_wBuilding[SCREEN_H][SCREEN_W] = {
    "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
    "  P                                                                   ",
    "                                                                     ",
    "        C                                                            ",
    "                   W   W                W                            ",
    "                   W   W      BB                                     ",
    "                   W   W                                             ",
    "         WWWWWW    W   W                         W                   ",
    "         W    WWWWWW   W                                             ",
    "         W             W                                             ",
    "         WWWWWWWWWWWWWWW                                             ",
    "                                       W     R                       ",
    "                               WWWWWW                                ",
    "      W                        W    W                                ",
    "                               W  R W     W                          ",
    "                               WWWW W                                ",
    "                                                                     ",
    "           W                                                         ",
    "                                                                     ",
    "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"
};
#else

char TEST_map_wBuilding[SCREEN_H][SCREEN_W] = {
    "                                                                     ",
    "                                                                     ",
    "                                                      R              ",
    "                                                                     ",
    "                                                                     ",
    "                                                                     ",
    "                                                                     ",
    "                                                                     ",
    "                             W                                       ",
    "                             W                                       ",
    "                             W                                       ",
    "                                                                     ",
    "                                                                     ",
    "                                                                     ",
    "                                                                     ",
    "                             C      C      C C                       ",
    "                                                                     ",
    "                                                                     ",
    "                                                             P       "
};
#endif
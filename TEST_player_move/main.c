/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: LIA2017
 *
 * Created on den 2 mars 2017, 14:32
 */
#include "ze engine.h"
#include "Llist.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <conio.h>
#include "curses.h"
#include "object.h"
#include "wall.h"
#include <stdbool.h>
#include <time.h>


char player_char[1][1] = {'&#9996'};
char *welcome[3] = {"                WELCOME", "         to the walking simulator", ""};
llist_t enemies;





typedef struct player
{
    char name[16];
    coord_t pos;
    char *image;
} player_t;



typedef struct map
{
    char *map_data;
    char name[];

} map_t;

#if 0
char TEST_map_wBuilding[SCREEN_H][SCREEN_W] = {
    "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
    "                                                                     ",
    "                                                                     ",
    "                                                                     ",
    "                   W   W                W                            ",
    "                   W   W                                             ",
    "                   W   W                                             ",
    "         WWWWWW    W   W                         W                   ",
    "         W    WWWWWW   W                                             ",
    "         W             W                                             ",
    "         WWWWWWWWWWWWWWW                                             ",
    "                                       W                             ",
    "                               WWWWWW                                ",
    "      W                        W    W                                ",
    "                               W    W     W                          ",
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
    "                                                                     ",
    "                                                                     ",
    "                   W                                                 ",
    "                                                                     ",
    "                                                                     ",
    "                              W                                      ",
    "                                                                     ",
    "                                                                     ",
    "                                                                     ",
    "                       W                                             ",
    "                                                                     ",
    "                                                                     ",
    "                                                                     ",
    "                                                                     ",
    "                                                                     ",
    "                                                                     ",
    "                                                                     ",
    "                                                                     "
};
#endif


void populateMap(map_t *map)
{
    int8_t x;
    int8_t y;
    object_t *object;

    for(y = 0; y < SCREEN_H; y++)
    {
        for(x = 0; x < SCREEN_W; x++)
        {
            if(*(map->map_data + x + (y * SCREEN_W)) == 'W')
            {
                object = LLIST_push(&enemies, sizeof(wall_t));
                
                WALL_init(object, x, y,FALSE,0);
           
            }
        }
    }
}



int8_t validMove(int8_t x, int8_t y)
{
      
    int valid = 1;
    if(x < 0 || x > SCREEN_W - 1)
    {
        valid = 0;
    }
    if(y < 0 || y > SCREEN_H)
    {
        valid = 0;
    }
    if(OBJECT_checkColision(&enemies, x, y))
    {        
        valid = 0;
    }
    return valid;
}

void PLAYER_move(player_t *player)
{
    int x = player->pos.x;
    int y = player->pos.y;
    char dir;
    if(kbhit())
    {
        dir = getch();
    }
    switch(dir)
    {
        case 'w':
            if(validMove(x, y - 1))
            {
                player->pos.y -= 1;
            }
            break;
        case 's':
            if(validMove(x, y + 1))
            {
                player->pos.y += 1;
            }
            break;
        case 'a':
            if(validMove(x - 1, y))
            {
                player->pos.x -= 1;
            }
            break;
        case 'd':
            if(validMove(x + 1, y))
            {
                player->pos.x += 1;
            }
            break;
        default:
            break;
    }


}

void welcome_msg(void)
{
    GPU_clear();
    GPU_text_multiLine_withBoarder(6, 20, welcome, 3, 40, 0, '|', '*');
    GPU_text(9, 24, " press the \"anykey\" to continue ");
    GPU_show();
    getch();
}

void draw_enemies()
{
    node_t search;
    object_t *object;
    search = LLIST_searchStart(&enemies);

    while((object = LLIST_searchNext(&search)))
    { 
        GPU_draw_single(object->pos.x, object->pos.y, object->sign);               
    }

}

void updateObjects(llist_t *list)
{
    node_t search;
    void *object = NULL;

    search = LLIST_searchStart(list);
    object = LLIST_searchNext(&search);
    
    while(object != NULL)
    {   
        if(((object_t*)object)->type == WALL)
        {        
           ((wall_t*)object)->imove(((wall_t*)object));
                  
        } 
        object = LLIST_searchNext(&search);
    }

}

int main(int argc, char** argv)
{
    initscr();
    LLIST_init(&enemies);
    map_t test_map;
    test_map.map_data = &TEST_map_wBuilding;
    populateMap(&test_map);


    clock_t time_update;
    clock_t time_rate;
    int frame_cnt = 0;
    int frame_rate = 0;

    time_update = clock();
    time_rate = clock();

    player_t walker;
    walker.pos.x = 1;
    walker.pos.y = 1;
    strcpy(walker.name, "VANDRAREN");
    walker.image = &player_char;

    welcome_msg();
    while(1)
    {
        if(time_rate < clock())
        {
            time_rate += 1000;
            frame_rate = frame_cnt;
            frame_cnt = 0;
        }

        if(time_update < clock())
        {
            time_update += 50;

            PLAYER_move(&walker);
            printw("player move\n");             
            updateObjects(&enemies);
           
           
       
            GPU_clear();

            printw("Time update: %03i   ", time_update / 1000);
            printw("Frame rate: %i\n", frame_rate);
            printw("x: %i\ny: %i\n", walker.pos.x, walker.pos.y);
            draw_enemies();
            GPU_draw_single(walker.pos.x, walker.pos.y, '@');
            GPU_show();


            frame_cnt++;
        }
    }
    return(EXIT_SUCCESS);
}


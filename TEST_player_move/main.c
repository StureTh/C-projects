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


char player_char[1][6] = {"&#9996"};
char *welcome[5] = {"               WELCOME", "         to MetalGear Solid ","","          ULTIMATE EDITION" ,""};

void welcome_msg(void)
{
    GPU_clear();
    GPU_text_multiLine_withBoarder(6, 20, welcome, 5, 40, 0, '|', '*');
    GPU_text(11, 24, " press the \"anykey\" to continue ");
    GPU_show();
    getch();
}

void draw_enemies()
{
    node_t search;
    object_t *object;
    search = LLIST_searchStart(&worldObjects);

    while((object = LLIST_searchNext(&search)))
    {
        GPU_draw_single(object->pos.x, object->pos.y, object->sign);
    }

}

int main(int argc, char** argv)
{
    initscr();

    LLIST_init(&worldObjects);
    map_t test_map;
    test_map.map_data = (char*) TEST_map_wBuilding;
    MAP_populate(&test_map);


    clock_t time_update;
    clock_t time_rate;
    int frame_cnt = 0;
    int frame_rate = 0;

    time_update = clock();
    time_rate = clock();

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

            OBJECT_updateWorldObjects(&worldObjects);


            GPU_clear();
            draw_enemies();
            printw("Time update: %03i   ", time_update / 1000);
            printw("Frame rate: %i\n", frame_rate);
            printw("x: %i\ny: %i           HP %i\n", player1->base.pos.x, player1->base.pos.y, player1->base.hp);

            
            GPU_show();


            frame_cnt++;
        }
    }
    return(EXIT_SUCCESS);
}


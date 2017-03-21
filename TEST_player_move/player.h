/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   player.h
 * Author: LIA2017
 *
 * Created on den 15 mars 2017, 11:57
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "object.h"
#include <stdbool.h>

struct key_map
{
    char dir_up;
    char dir_down;
    char dir_left;
    char dir_right;
    char attack;
};

typedef struct _player
{
    object_t base;
} _player_t;

_player_t *player1;
void PLAYER_init(_player_t *self, uint8_t x, uint8_t y);


#endif /* PLAYER_H */


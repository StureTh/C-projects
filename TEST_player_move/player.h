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

typedef struct _player
{
    object_t base;
    
    
   
}_player_t;
static void playerMove(_player_t *self);
void PLAYER_init(_player_t *self, uint8_t x, uint8_t y,uint16_t hp);


#endif /* PLAYER_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   wall.h
 * Author: LIA2017
 *
 * Created on den 8 mars 2017, 15:28
 */

#ifndef WALL_H
#define WALL_H

#include "object.h"
#include <stdbool.h>

typedef struct wall
{
   object_t base;
   bool desroyable; 
     void (*imove)(struct wall *self);
       
}wall_t;

void WALL_init(wall_t *self, int8_t x, int8_t y, bool destroyable, int16_t hp);
static void imove(wall_t *self);
#endif /* WALL_H */


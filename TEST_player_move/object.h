/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   object.h
 * Author: LIA2017
 *
 * Created on den 9 mars 2017, 10:23
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "curses.h"
#include <stdint.h>
#include <stdbool.h>

typedef enum
{
    WALL,
    ENVIROMENT,
    PLAYER

} obj_type_t;

typedef struct coodinates
{
    int8_t x;
    int8_t y;

} coord_t;

typedef struct object
{
    obj_type_t type;
    coord_t pos;
    uint16_t hp;
    char sign;


    bool alive;
    bool walkable;
    bool moveable;
    void (*move)(struct object *self);

} object_t;

#endif /* OBJECT_H */


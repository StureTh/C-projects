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

#ifndef _OBJECT_H
#define _OBJECT_H


#include <stdint.h>
#include "curses.h"
#include "Llist.h"


llist_t worldObjects;

typedef enum
{
    WALL,
    ENVIROMENT,
    PLAYER,
    ENEMY

} obj_type_t;

typedef enum
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NONE

} obj_dir_t;

typedef struct coodinates
{
    int8_t x;
    int8_t y;

} coord_t;

typedef struct object
{
    obj_type_t type;
    obj_dir_t move_dir;
    coord_t pos;
    uint16_t hp;
    char sign;

    bool alive;
    bool walkable;
    bool moveable;
    void (*move)(struct object *self);
    void (*onColission)(struct object *self, struct object *obejct);

} object_t;

int8_t OBJECT_checkColision(llist_t *llist_objects, int8_t pos_x, int8_t pos_y, object_t *mover);
int8_t OBJECT_validMove(int8_t x, int8_t y,object_t *self);
void OBJECT_updateWorldObjects(llist_t *list);

#endif /* _OBJECT_H */


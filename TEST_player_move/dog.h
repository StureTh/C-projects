/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dog.h
 * Author: LIA2017
 *
 * Created on den 21 mars 2017, 10:35
 */

#ifndef _DOG_H
#define _DOG_H
#include "object.h"

typedef struct dog
{
    object_t base;
    int attk_dmg;
    
    bool isIdle;
    bool isChasing;
    object_t *target;
         
}dog_t;

void DOG_init(dog_t *self, int8_t x, int8_t y);

#endif /* DOG_H */


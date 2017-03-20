/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   box.h
 * Author: LIA2017
 *
 * Created on den 20 mars 2017, 11:23
 */

#include "object.h"


#ifndef BOX_H
#define BOX_H

typedef struct box
{
    object_t base;
      bool desroyable;
    
}box_t;

void BOX_init(box_t *self, int8_t x, int8_t y);



#endif /* BOX_H */


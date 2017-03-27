/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bullet.h
 * Author: LIA2017
 *
 * Created on den 21 mars 2017, 15:48
 */

#ifndef _BULLET_H_
#define _BULLET_H_

#include "object.h"

typedef struct bullet
{
    object_t base;
    int dmg;
  
    
}bullet_t;
void BULLET_init(bullet_t *self, obj_dir_t direction, coord_t *source_coord);

#endif /* _BULLET_H_ */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cacti.h
 * Author: LIA2017
 *
 * Created on den 13 mars 2017, 10:36
 */

#ifndef CACTI_H

#include "object.h"

typedef struct cacti
{
    object_t base;
    bool desroyable;


} cacti_t;

void CACTI_init(cacti_t *self, int8_t x, int8_t y);
#endif /* CACTI_H */


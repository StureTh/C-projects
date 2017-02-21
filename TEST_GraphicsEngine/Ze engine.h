/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ze engine.h
 * Author: LIA2017
 *
 * Created on den 21 februari 2017, 15:22
 */

#ifndef _ZE_ENGINE_H_
#define _ZE_ENGINE_H_
#define SCREEN_H            60
#define SCREEN_W            80
#include "images.h"


char screen[SCREEN_H][SCREEN_W];
void GPU_clear();
void GPU_show();
void GPU_draw(uint8_t x, uint8_t y, tile_t *tile);


#endif /* _ZE_ENGINE_H_ */


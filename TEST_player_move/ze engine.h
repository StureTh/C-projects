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
#define SCREEN_H            20
#define SCREEN_W            70


#include <stdint.h>


char screen[SCREEN_H][SCREEN_W];
void GPU_clear();
void GPU_show();
void GPU_draw(uint8_t y,uint8_t x, char *image, uint8_t height, uint8_t width);
void GPU_draw_single(uint8_t x, uint8_t y, char ch);
void GPU_text_multiLine_withBoarder(int8_t y, int8_t x, char *string_array[],
        int rows, int string_size, int columns,
        char line_vert, char line_hori);

void GPU_text(int8_t y, int8_t x, char *string);

#endif /* _ZE_ENGINE_H_ */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: LIA2017
 *
 * Created on den 21 februari 2017, 14:52
 */
#include "Ze engine.h"
#include <stdio.h>


/*
 * 
 */
int main(int argc, char** argv)
{
    char *string_array[] = {"Hello world","There is a bat on the screen","and a camel"};
    int nr_of_rows = sizeof(string_array) / sizeof(string_array[0]);
    IMAGE_init();
    GPU_clear();
    GPU_draw(10,20,image_camel.image,image_camel.height,image_camel.width);
    GPU_draw(10,40,image_bat.image,image_bat.height,image_bat.width);
    GPU_text(9,30,"Hello World! Hoho memememem");
    GPU_textMultiLine(15,30,*string_array,nr_of_rows);
    GPU_show();

    return 0;
}


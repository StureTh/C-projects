/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   images.h
 * Author: LIA2017
 *
 * Created on den 21 februari 2017, 15:06
 */

#ifndef _IMAGES_H_
#define _IMAGES_H_
#include <stdint.h>
typedef struct image
{ 
    uint8_t height;
    uint8_t width;
    char *image;
}image_t;

extern image_t image_camel;



#endif /* _IMAGES_H_ */


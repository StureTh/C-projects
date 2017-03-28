/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   map.h
 * Author: LIA2017
 *
 * Created on den 21 mars 2017, 14:35
 */
#include "ze engine.h"
#ifndef MAP_H
#define MAP_H


typedef struct map
{
    int nr;
    char *map_data;


} map_t;
typedef struct THEMAP
{

    map_t section[16];
    
}THEMAP_t;

void MAP_populate(map_t *map);
char TEST_map_wBuilding[SCREEN_H][SCREEN_W];



#endif /* MAP_H */


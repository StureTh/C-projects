/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: Sture
 *
 * Created on den 16 februari 2017, 16:08
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "weapon.h"
#include "defense.h"
#include <stdint.h>
#include <stdbool.h>





 typedef struct player
{
    char name[20];
    int16_t hp;
    uint16_t coin_purse;
    weapon_t *weapon;
   defense_t *defense;
    
}player_t;

//typedef struct player player_t;
player_t PLAYER_initPlayer(void);



#endif /* PLAYER_H */


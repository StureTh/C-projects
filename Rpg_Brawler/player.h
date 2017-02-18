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


#include <stdint.h>
#include <stdbool.h>
#include "defense.h"
#include "weapon.h"




typedef struct player
{
    char name[20];
    uint8_t hp;
    uint16_t coin_purse;
    Weapon_t *weapon;
   defense_t *defense;
    
} player_t;

player_t PLAYER_initPlayer(void);

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* PLAYER_H */


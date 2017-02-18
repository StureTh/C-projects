/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Weapon.h
 * Author: LIA2017
 *
 * Created on den 16 februari 2017, 15:34
 */

#ifndef WEAPON_H
#define WEAPON_H


#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include <stdint.h>

 struct weapon
{
    char name[32];
    int8_t dmg; 
    int8_t accuracy;
    int16_t price;
    
};

typedef struct weapon weapon_t;
typedef struct player player_t;

weapon_t createWeaponTypes(char *name, int16_t price, int8_t dmg);
int8_t WEAPON_useWeapon(player_t *attacker, player_t *opponent, char *msg);

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif
#endif /* WEAPON_H */


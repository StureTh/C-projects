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


#include "defense.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct weapon
{
    char name[32];
    int8_t dmg; 
    int8_t accuracy;
    int16_t price;
    
}weapon_t;

//typedef struct weapon weapon_t;
//typedef struct defense defense_t;

void WEAPON_init(weapon_t *weapon, char *name, int16_t price, int8_t dmg);
weapon_t createWeaponTypes(char *name, int16_t price, int8_t dmg);
int8_t WEAPON_useWeapon(weapon_t *attk_wpn, defense_t *opponent_deff);


#endif /* WEAPON_H */


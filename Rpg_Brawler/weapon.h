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

typedef struct weapon
{
    char name[32];
    int8_t dmg; 
    int8_t accuracy;
    
}Weapon_t;

int8_t WEAPON_useWeapon(player_t *attacker, player_t *opponent, char *msg);

#endif /* WEAPON_H */


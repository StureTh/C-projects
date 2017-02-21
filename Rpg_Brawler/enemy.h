/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   enemy.h
 * Author: Thuren
 *
 * Created on 18 February 2017, 15:01
 */

#ifndef ENEMY_H
#define ENEMY_H
#include "player.h"

//#include "weapon.h"


typedef struct enemy
{
    struct player base;
    uint16_t gold_reward;
    weapon_t enemy_weapon;
    defense_t enemy_defense;

} enemy_t;

 enemy_t create_enemy(char *name, int hp, defense_t def, int gold_reward);
 enemy_t createSwampMonster(int hp, int defense, int dmg);
 enemy_t createCupcakeThief(int hp, int defense, int dmg);
 enemy_t createBeastman(int hp, int defense, int dmg);





#endif /* ENEMY_H */


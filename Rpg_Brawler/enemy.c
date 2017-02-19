#include "player.h"
#include "enemy.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

enemy_t create_enemy(char *name, int hp, defense_t def, int gold_reward)
{
    enemy_t enemy;

    strcpy(enemy.base.name, name);
    enemy.base.hp = hp;
    enemy.base.defense = def.defense;
    enemy.gold_reward = gold_reward;

    return enemy;


}

enemy_t createSwampMonster(int hp, int defense, int dmg)
{
    enemy_t swamp_monster;
    strcpy(swamp_monster.base.name,"Swamp Monster!");
    swamp_monster.base.hp =hp;
    swamp_monster.base.defense->defense = defense;
    swamp_monster.base.weapon->dmg = dmg;
    swamp_monster.gold_reward = 300;
    
    return swamp_monster;
  
}



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
    enemy.enemy_defense.defense = def.defense;
    enemy.gold_reward = gold_reward;

    return enemy;


}

enemy_t createSwampMonster(int hp, int defense, int dmg)
{
    enemy_t swamp_monster;
    strcpy(swamp_monster.base.name, "Swamp Monster");

    swamp_monster.enemy_weapon = createWeaponTypes("Slug", 0, dmg);
    swamp_monster.enemy_defense = createDefenseTypes("FishScale armor", 0, defense);

    swamp_monster.base.hp = hp;
    swamp_monster.gold_reward = 300;


    return swamp_monster;

}

enemy_t createCupcakeThief(int hp, int defense, int dmg)
{
    enemy_t cupcake_thief;
    strcpy(cupcake_thief.base.name, "Cupcake Thief");
    cupcake_thief.enemy_weapon = createWeaponTypes("Rolling pin", 0, dmg);
    cupcake_thief.enemy_defense = createDefenseTypes("Cake tin", 0, defense);
    cupcake_thief.base.hp = hp;
    cupcake_thief.gold_reward = 250;

    return cupcake_thief;
}

enemy_t createBeastman(int hp, int defense, int dmg)
{
    enemy_t beastman_chieftain;
    strcpy(beastman_chieftain.base.name, "Beastman Chieftain");
    beastman_chieftain.enemy_weapon = createWeaponTypes("Double axe", 0, dmg);
    beastman_chieftain.enemy_defense
            = createDefenseTypes("Studded leather", 0, defense);
    beastman_chieftain.base.hp = hp;
    beastman_chieftain.gold_reward = 1000;
    
    return beastman_chieftain;
}




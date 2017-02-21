#include "enemy.h"
#include "images.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>



enemy_t createSwampMonster(int hp, int defense, int dmg)
{
  enemy_t swamp_monster;
  strcpy(swamp_monster.base.name, "Swamp Monster");

  WEAPON_init(&swamp_monster.enemy_weapon, "Slug", 0, dmg);
  DEFENSE_init(&swamp_monster.enemy_defense, "FishScale armor", 0, defense);

  swamp_monster.base.hp = hp;
  swamp_monster.gold_reward = 300;

  swamp_monster.base.image = &the_swamp_monster_image;


  return swamp_monster;

}

enemy_t createCupcakeThief(int hp, int defense, int dmg)
{
  enemy_t cupcake_thief;
  strcpy(cupcake_thief.base.name, "Cupcake Thief");
  
  WEAPON_init(&cupcake_thief.enemy_weapon, "Rolling pin", 0, dmg);
  DEFENSE_init(&cupcake_thief.enemy_defense, "Cake Tin", 0, defense);
  
  cupcake_thief.base.hp = hp;
  cupcake_thief.gold_reward = 250;
  
  cupcake_thief.base.image = &the_hero_image;

  return cupcake_thief;
}

enemy_t createBeastman(int hp, int defense, int dmg)
{
  enemy_t beastman_chieftain;
  strcpy(beastman_chieftain.base.name, "Beastman Chieftain");
  
 WEAPON_init(&beastman_chieftain.enemy_weapon,"Double axe", 0, dmg);
 DEFENSE_init(&beastman_chieftain.enemy_defense,"Studded leather", 0, defense);
  
 
 beastman_chieftain.base.image = &the_hero_image;
  beastman_chieftain.base.hp = hp;
  beastman_chieftain.gold_reward = 1000;

  return beastman_chieftain;
}




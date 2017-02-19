#include "player.h"
#include "shop.h"
#include "defense.h"
#include "enemy.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <stdint.h>



player_t arena_player;

enemy_t stage1_enemies[1];
enemy_t (*currentstage)[];






static void battle_loop(enemy_t *enemies)
{
    int i;
    enemy_t *enemy_array = enemies;
    int enemy_count = sizeof(enemies)/ 4;
    printf("\nnumber of enemies: %i", enemy_count);
   for(i = 0; i < 1; i++ ) 
   {
       int reward;
       reward = battle_start(*(enemy_array + i));
   }
}

 int battle_start(enemy_t enemy)
{
    printf("\n----------sture e en bajskorv!------------\n");
    printf("Player %s", arena_player.name);
    printf("\nEnemy %s hp: %i! dmg %i\n", enemy.base.name, enemy.base.hp, enemy.base.weapon->dmg);
    getche();
    
    
}

 static void Stage1_start()
{
     
     printf("-----------stage 1--------\n");
    currentstage = &stage1_enemies;
    
       
   defense_t enemy1_defense;
   
   enemy_t enemy1 = create_enemy("SwampMonster", 100, enemy1_defense, 2000);
   
   //enemy1.base.weapon = createWeaponTypes("Sloppy salmon", 100, 14);
   printf("prebattle");
   stage1_enemies[0] = enemy1;

   battle_loop(&stage1_enemies); 
    
}
 int8_t GAME_startArena(void)
{
    bool win = false;
  
  arena_player = PLAYER_initPlayer();
  SHOP_shopMenu(&arena_player);
  Stage1_start();
   // SHOP_visitShop(arena_player); 
    
    
    
}
 

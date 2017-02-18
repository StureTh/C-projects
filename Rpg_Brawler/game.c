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




int8_t GAME_startArena(void)
{
  arena_player = PLAYER_initPlayer();
    
   // SHOP_visitShop(arena_player); 
    
    
    
}

static void battle_loop(enemy_t enemies[])
{
    int i;
    int enemy_count = sizeof(enemies) / sizeof(enemies[0]);
    
   for(i = 0; i <enemy_count; i++ ) 
   {
       int reward;
       reward = battle_start(enemies[i]);
   }
}

 int battle_start(enemy_t enemy)
{
    printf("battle");
    getche();
}

 static void Stage1_start()
{
   defense_t enemy1_defense;
   
   enemy_t enemy1 = create_enemy("SwampMonster", 100, enemy1_defense, 2000);
   
   enemy1.base.weapon->dmg = (int8_t)10;
   
   stage1_enemies[0] = enemy1;
   
   battle_loop(stage1_enemies);
   
   
   
   
   

    
      
    
    
}
 

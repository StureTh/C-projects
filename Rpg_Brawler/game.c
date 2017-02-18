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

// static void Stage1_start()
//{
 //   defense_t enemy1_defense;
 //   stage1_enemies[0] = create_enemy("SwampMonster", 200, enemy1_defense, 2000);
    
    
//}
 

#include "player.h"
#include "shop.h"
#include "defense.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <stdint.h>

/*
 * 
 */
int main(int argc, char** argv)
{
    
    populateShopWeapons();
    populateShopeDefensives();
    GAME_startArena();
  /*  player_t player;

    player = PLAYER_initPlayer();
    populateShopeDefensives();
    SHOP_chooseDefenseItem(&player);
    populateShopWeapons();
    SHOP_chooseWeapon(&player);
   */
    return (EXIT_SUCCESS);
}




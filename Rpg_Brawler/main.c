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
    
    
   // GAME_startArena();
    player_t player;

    player = PLAYER_initPlayer();
    populateShopeDefensives();
    populateShopWeapons();
    SHOP_shopMenu(&player);
    
    return (EXIT_SUCCESS);
}


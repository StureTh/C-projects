
#include "shop.h"
#include "game.h"



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





#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <stdint.h>
#include "player.h"

/*
 * 
 */
int main(int argc, char** argv)
{
    player_t player;
    
/*
    
    char name[15];
   
    printf("Enter player name: ");
    scanf("%s", name);
    
    player = PLAYER_createPlayer(name);

    printf("Greetings traveler %s! You have %d coins to buy what you need\n",
           player.name,
           player.coin_purse);
*/
    player = PLAYER_initPlayer();
    
    printf("hp = %i", player.hp);
   

    return (EXIT_SUCCESS);
}


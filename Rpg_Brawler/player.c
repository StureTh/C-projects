#include "player.h"
#include "images.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



static player_t createPlayer(char *name)
{
    player_t new_player;
    strcpy(new_player.name, name);
    new_player.hp = (int16_t)150;
    new_player.coin_purse = 2000;
    new_player.defense;
     new_player.weapon;
     
     new_player.image = &the_hero_image;

    return new_player;
}

player_t PLAYER_init(void)
{
    player_t player;
    char name[15];

    printf("Enter player name: ");
    scanf("%s", name);
    player = createPlayer(name);

    printf("Greetings traveler %s! "
           "You have %d health and %d coins to buy what you need\n",

           player.name,
           player.hp,
           player.coin_purse);

    return player;
}





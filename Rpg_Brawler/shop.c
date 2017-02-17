#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "player.h"



defense_t defense_types[15];

void populateShopeDefensives(void)
{

    defense_types[0] = createDefenseTypes("Round-shield", 250, 50);
    defense_types[1] = createDefenseTypes("Fish-scale-armor", 400, 60);
    defense_types[2] = createDefenseTypes("Lion-shield", 1000, 100);
    defense_types[3] = createDefenseTypes("Rugged leather shield", 50, 10);
    defense_types[4] = createDefenseTypes("Wool-shield", 20, 5);
}

void SHOP_chooseDefenseItem(player_t *current_player)
{

    int shop_choice;


    int i;

    for(i = 0; i < 5; i++)
    {
        printf("%i %s %i %i\n",
               i + 1,
               defense_types[i].name,
               defense_types[i].price,
               defense_types[i].defense);
    }
    printf("loop done");

    scanf("%i", &shop_choice);


    current_player->defense = &defense_types[shop_choice - 1];
    current_player->coin_purse -= current_player->defense->price;

    printf("Get ready %s you chose %s as you main defense."
           "You have %i gold left",
           current_player->name,
           current_player->defense->name,
           current_player->coin_purse);
}


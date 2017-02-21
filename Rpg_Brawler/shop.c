#include "shop.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>





defense_t defense_types[15];
weapon_t weapon_types[15];

void populateShopeDefensives(void)
{

    defense_types[0] = createDefenseTypes("Round-shield", 250, 50);
    defense_types[1] = createDefenseTypes("Fish-scale armor", 400, 60);
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
    if(defense_types[shop_choice - 1].price > current_player->coin_purse)
    {
        printf("You cannot afford %s", defense_types[shop_choice - 1].name);
    }
    else
    {
        current_player->defense = &defense_types[shop_choice - 1];
        current_player->coin_purse -= current_player->defense->price;
    }



    printf("Get ready %s you chose %s as you main defense."
           "You have %i gold left\n",
           current_player->name,
           current_player->defense->name,
           current_player->coin_purse);
}

void populateShopWeapons(void)
{
    weapon_types[0] = createWeaponTypes("Sloppy-fish", 1000, 10);
    weapon_types[1] = createWeaponTypes("Great-sword", 500, 40);
    weapon_types[2] = createWeaponTypes("Double-axe", 600, 45);
}

void SHOP_chooseWeapon(player_t *current_player)
{
    int i;
    int shop_choice;

    for(i = 0; i < 3; i++)
    {
        printf("%i %s %i %i\n",
               i + 1,
               weapon_types[i].name,
               weapon_types[i].price,
               weapon_types[i].dmg);
    }


    scanf("%d", &shop_choice);
    if(weapon_types[shop_choice - 1].price > current_player->coin_purse)
    {
        printf("You don afford %s", weapon_types[shop_choice - 1].name);
    }
    else
    {
        current_player->weapon = &weapon_types[shop_choice - 1];
        current_player->coin_purse -= current_player->weapon->price;
    }


    printf("You have chosen %s as your main weapon. You have %d gold left.\n",
           current_player->weapon->name,
           current_player->coin_purse);
}

void SHOP_shopMenu(player_t *current_player)
{

    int choise = 0;

    while(1)
    {
        printf("To buy weapons press 1:\n To buy defensive items press 2:\n"
               "To leave the shop, press 3:\n");

        scanf("%d", &choise);

        switch(choise)
        {
        case 1:
            SHOP_chooseWeapon(current_player);
            getche();
            system("cls");
            break;


        case 2:
            SHOP_chooseDefenseItem(current_player);
            getche();
            system("cls");
            break;
        case 3:
            return;

        }

    }


}


#include "game.h"


#include "shop.h"
#include "enemy.h"
#include "images.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>


int stage_count = 0;
int stage_index = 0;
int enemy_count;
bool end = false;
player_t arena_player;
enemy_t stage_enemies[100];
enemy_t(*currentstage)[];

void initStage1(void)
{
    enemy_count = 1;
    stage_enemies[0] = createSwampMonster(80, 20, 15);
}

void initStage2()
{
    enemy_count = 2;
    stage_index = 1;
    printf("STAGE TWO");
    stage_enemies[1] = createCupcakeThief(50, 10, 25);
    stage_enemies[2] = createCupcakeThief(50, 10, 25);

}

void initStage3()
{
    enemy_count = 1;
    stage_index = 3;
    stage_enemies[3] = createBeastman(110, 30, 50);
}

void setStage(int8_t stage_NR)
{
    int result = 0;

    switch(stage_NR)
    {
        case 1:
            initStage1();
            result = 1;
            break;

        case 2:
            initStage2();
            break;
        case 3:
            initStage3();
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;

    }
}

static void battle_loop()
{
    int i;


    printf("\nnumber of enemies: %i", enemy_count);
    printf("%i %i", stage_index, enemy_count);
    getche();
    for(i = stage_index; i < stage_index + enemy_count; i++)
    {
        battle_start(&stage_enemies[i]);
    }

}

void battle_start(enemy_t *enemy)
{
    uint8_t turn = 1;
    while(arena_player.hp > 0 && enemy->base.hp > 0)
    {

        system("cls");
        GAME_battleScene(enemy);
        if(turn == 1)
        {
            actionMenu(enemy);
            turn = 0;
        }
        else if(turn == 0)
        {
            enemyAction(enemy);
            turn = 1;
        }
        getche();
    }
    printf("DUDUDUDU");
    turn = 1;

}

void GAME_battleScene(enemy_t *enemy)
{
  int x1;
  int x2;
  int y;
     printf("      Your hp is at %d------------------------The %s hp is at %d\n",
          arena_player.hp, enemy->base.name, enemy->base.hp);
  printf("--------------------------------------------------------------------------\n");
          
  for(y = 0; y <IMG_MAX_H; y++) 
    {
      for(x1 = 0; x1 <IMG_MAX_W; x1++)
        {
          printf("%c", *(arena_player.image + x1 +(y * IMG_MAX_W)));
        }
      printf("                               ");
      
    for(x2 = 0; x2 < IMG_MAX_W; x2++)
        {
          printf("%c", *(enemy->base.image + x2 +(y * IMG_MAX_W)));
        }
    
      printf("\n");
        
    }
  printf("-----------------------------------------------------------------------\n");
    
      

}

void actionMenu(enemy_t *enemy)
{
    int choise = 0;
    int done = 0;
    int dmg = 0;
    int heal = 10;


    printf("Choose your action!");
    scanf("%d", &choise);
    printf("%d", choise);
    while(done == 0)
    {
        switch(choise)
        {
            case 1:
                dmg = WEAPON_useWeapon(arena_player.weapon,
                                       &enemy->enemy_defense);
                printf("You hit enemy for %i damage, KAPOW! ", dmg);
                playerDoDamage(dmg, enemy);

                done = 1;
                break;
            case 2:
                printf(" You sleep zzzzzzzzzzzzzzzzzz!\n And gain %d hp\n"
                       "%s 's current hp is: %d", heal,
                       arena_player.name,
                       arena_player.hp += heal);


                done = 1;
                break;
        }
    }


}

void playerDoDamage(int dmg, enemy_t *opponent)
{
    opponent->base.hp -= dmg;
}

void enemyDoDamage(int dmg, player_t *opponent)
{
    opponent->hp -= dmg;
}

void enemyAction(enemy_t *enemy)
{
    int dmg;
    dmg = WEAPON_useWeapon(&enemy->enemy_weapon, arena_player.defense);
    printf(" %s hit %s for %i damage, KAPOW! ",
           enemy->base.name,
           arena_player.name, dmg);
    enemyDoDamage(dmg, &arena_player);

}

void battleMenu(void)
{
    int choise = 0;


    printf("To continue press 1:\n To visit shop press 2:\n"
           "To quit game press 3:\n");
    scanf("%d", &choise);
    switch(choise)
    {
        case 1:
            battle_loop();
            break;
        case 2:
            SHOP_shopMenu(&arena_player);
            break;
        case 3:
            end = true;
            return;
    }

}

int8_t GAME_startArena(void)
{
    char continue_arena;

    arena_player = PLAYER_initPlayer();

    while(!end)
    {
        battleMenu();

        stage_count++;
        setStage(stage_count);
        printf("hp: %i name: %s",
               stage_enemies[0].base.hp,
               stage_enemies[0].base.name);

        printf("Get ready for stage %i", stage_count);

        getche();



    }


    // SHOP_visitShop(arena_player); 



}


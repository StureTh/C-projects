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


int stage_count = 0;

player_t arena_player;
enemy_t stage_enemies[100];
enemy_t(*currentstage)[];

void initStage1(void)
{
  stage_enemies[0] = createSwampMonster(80, 20, 15);
}

void initStage2()
{
  printf("STAGE TWO");
  stage_enemies[1] = createSwampMonster(80, 20, 15);
  stage_enemies[2] = createSwampMonster(80, 20, 15);
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
  int i = stage_count - 1;
  int enemy_count = stage_count;

  printf("\nnumber of enemies: %i", enemy_count);

  for(stage_count - 1; i < enemy_count; i++)
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
  printf("Your hp is at %d------------------------The %s hp is at %d\n",
          arena_player.hp, enemy->base.name, enemy->base.hp);

}

void actionMenu(enemy_t *enemy)
{
  int choise = 0;
  int done = 0;
  int dmg = 0;

  printf("Choose your action!");
  scanf("%d", &choise);
  printf("%d", choise);
  while(done == 0)
    {
      switch(choise)
        {
          case 1:
            dmg = WEAPON_useWeapon(arena_player.weapon, &enemy->enemy_defense);
            printf("You hit enemy for %i damage, KAPOW! ", dmg);
            playerDoDamage(dmg, enemy);

            done = 1;
            break;
          case 2:
            printf(" You sleep zzzzzzzzzzzzzzzzzz!");
            done = 1;
            break;
        }
    }

  printf("Kapow?");
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
  printf(" %s hit %s for %i damage, KAPOW! ", enemy->base.name, arena_player.name, dmg);
  enemyDoDamage(dmg, enemy);


  printf(" %s hit you KAPOW! You deded", enemy->base.name);
}

int8_t GAME_startArena(void)
{
  char continue_arena;
  bool win = false;
  arena_player = PLAYER_initPlayer();
  SHOP_shopMenu(&arena_player);
  while(!win || continue_arena == 'n' || continue_arena == 'N')
    {
      stage_count++;
      setStage(stage_count);
      printf("hp: %i name: %s", stage_enemies[0].base.hp, stage_enemies[0].base.name);
      printf("Get ready for stage %i", stage_count);
      getche();
      battle_loop();
      printf("Continue or chicken out?: ");
      scanf("%c", &continue_arena);
    }
  // SHOP_visitShop(arena_player); 



}


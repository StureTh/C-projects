#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <stdint.h>

typedef struct player
{
    char name[];
    uint8_t hp;
    uint8_t coin_purse;
    
    
} player_t;
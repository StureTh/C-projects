#include "Ze engine.h"
#include <stdint.h>
#include <stdio.h>

void GPU_clear(void)
{
    uint8_t y;
    uint8_t x;
    for(y = 0; y < SCREEN_H; y++)
    {
        for(x = 0; x < SCREEN_W; x++)
        {
            screen[y][x] = '.';
        }
    }
}

void GPU_draw(uint8_t x, uint8_t y, tile_t *tile)
{

}

void GPU_show(void)
{
     uint8_t y;
    uint8_t x;
    for(y = 0; y < SCREEN_H; y++)
    {
        for(x = 0; x < SCREEN_W; x++)
        {
           printf("%c",screen[y][x]);
        }
    }
}
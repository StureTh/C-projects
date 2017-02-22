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
            screen[y][x] = ' ';
        }
    }
}

void GPU_draw(uint8_t y, uint8_t x, char *image, uint8_t height, uint8_t width)
{
    int i;
    int j;
    
    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            screen[y +i][x+j] = *(image + j + (i*width));
        }
    }

}

void GPU_show(void)
{
    uint8_t y;
    uint8_t x;
    for(y = 0; y < SCREEN_H; y++)
    {
        for(x = 0; x < SCREEN_W; x++)
        {
            printf("%c", screen[y][x]);
        }
       
    }
}
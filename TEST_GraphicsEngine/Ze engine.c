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

void GPU_draw(uint8_t y, uint8_t x, char *image, uint8_t height, uint8_t width)
{
    int i;
    int j;

    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            screen[y + i][x + j] = *(image + j + (i * width));
        }
    }

}

void GPU_text(uint8_t y, uint8_t x, char *string)
{
    uint8_t i = 0;

    char *curr_char = string;

    while(*curr_char != '\0')
    {
        screen[y][x + i] = *curr_char;
        i++;
        curr_char = string + i;

    }
}


void GPU_textMultiLine(uint8_t y, uint8_t x, char *string,uint8_t rows)
{
    uint8_t i;
    uint8_t j = 0;
    int8_t k = -1;
   
    for(i = 0; i< rows; i++)
    {
        j = 0;
        k++;
        while(*(string +k) != '\0')
        {
            screen[y + i][x +j] = *(string +k);
            j++;
            k++;
            

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
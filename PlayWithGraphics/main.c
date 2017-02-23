/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: LIA2017
 *
 * Created on den 22 februari 2017, 15:51
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
typedef struct image
{
    int height;
    int width;
    char *image;
} image_t;

char screen[25][80];

const char bat_data[13][29] = {
    " ._.                  _.____.",
    "  )S\\.              /SSSS.(  ",
    " )SS|            .'SSSS(     ",
    "  )SS).          .'SSS(      ",
    "    )S|.        .'SS(        ",
    "    ).S;      ./SS.(         ",
    "     )S|      )SS(           ",
    "     )S;      :S(            ",
    "      )|    .|.;             ",
    "      .^--^./S(.             ",
    "      ;0..0;SSS\\             ",
    "       Svv_.:_.;              ",
    "            m M              "

};
const char hang_man_data[7][16] = {
    "   ___________ ",
    "   |/        | ",
    "   |         0 ",
    "   |        /|\\  ",
    "   |        / \\  ",
    "   |            ",
    "   |            "
};

void GPU_clear(void)
{
    int i;
    int j;
    for(i = 0; i < 25; i++)
    {
        for(j = 0; j < 80; j++)
        {
            screen[i][j] = ' ';
        }
    }
}

void GPU_draw(int y, int x, char *image, int height, int width)
{
    int i;
    int j;

    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            if(*(image + j + (i * width)) == 'S')
            {
                screen[y + i][x + j] = ' ';
            }
            else if((*(image + j + (i * width)) == ' '))
            {
                continue;
            }
            else
            {
                screen[y + i][x + j] = *(image + j + (i * width));

            }
        }
    }
}

void GPU_multiText(int y, int x, char *string, int rows, int width)
{
    int i;
    int j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < width; j++)
        {
            screen[y +i][x +j] = *(string + j + (i*width));
        }
    }
}

void GPU_multiTextBoarder(int y, int x, char *string, int rows, int width, char vert_line, char hor_line)
{
    int i;
    int j;


    for(i = 0; i < rows; i++)
    {
        screen[y + i ][x - 1] = vert_line;
        screen[y + i][x + width] = vert_line;
        screen[y - 1][x - 1] = hor_line;
        screen[y - 1][x + width] = hor_line;
        for(j = 0; j < width; j++)
        {
            if(i == 0)
            {
                screen[y - 1][x + j] = hor_line;
                screen[y + rows][x + j] = hor_line;
                screen[y + rows][x - 1] = hor_line;
                screen[y + rows][x + width] = hor_line;

            }

            screen[y + i][x + j] = *(string + j + (i * width));
        }
    }
}

void GPU_show(void)
{
    int y;
    int x;
    for(y = 0; y < 25; y++)
    {
        for(x = 0; x < 80; x++)
        {
            printf("%c", screen[y][x]);
        }

    }
}

int main(int argc, char** argv)
{
    image_t image_bat;

    image_bat.height = 13;
    image_bat.width = 29;
    image_bat.image = &bat_data;

    image_t image_hang_man;
    image_hang_man.height = 7;
    image_hang_man.width = 16;
    image_hang_man.image = &hang_man_data;

    const char string_array[3][30] = {"C programming", "is", "Awesome!"};
    const char many_strings[5][30] = {"There is", "a", "Bat", "in", "the cave!"};
    int nr_of_rows = sizeof(string_array) / sizeof(string_array[0]);
    int second_row_counter = sizeof(many_strings) /sizeof(many_strings[0]);

    GPU_clear();
    GPU_draw(0, 0, image_bat.image, image_bat.height, image_bat.width);
    GPU_draw(10, 40, image_hang_man.image, image_hang_man.height, image_hang_man.width);
    GPU_multiTextBoarder(20, 20, string_array, nr_of_rows, 30, '|', '-');
    GPU_multiText(14,15,many_strings,second_row_counter,30);
    GPU_show();

    return(EXIT_SUCCESS);
}


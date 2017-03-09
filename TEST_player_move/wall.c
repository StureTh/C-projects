/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "wall.h"

#include <stdint.h>
#include <stdlib.h>

static void imove(wall_t *self)
{

    int8_t x = self->base.pos.x;
    int8_t y = self->base.pos.y;

    int8_t valid = 0;
    int8_t loops = 0;

    while(loops <= 10)
    {
        x = self->base.pos.x + ((rand() % 3) - 1);
        y = self->base.pos.y + ((rand() % 3) - 1);



        valid = validMove(x, y);

        if(valid == 1)
        {
            self->base.pos.x = x;
            self->base.pos.y = y;
            break;
        }
        loops++;
    }
}

void WALL_init(wall_t *self, int8_t x, int8_t y, bool destroyable, int16_t hp)
{
    self->base.type = WALL;
    self->base.pos.x = x;
    self->base.pos.y = y;

    self->base.sign = '#';
    self->base.alive = FALSE;
    self->base.walkable = FALSE;
    self->base.moveable = FALSE;

    if(destroyable == TRUE)
    {
        self->base.hp = hp;
        self->desroyable = TRUE;
    }
    else
    {
        self->base.hp = INT16_MAX;
        self->desroyable = FALSE;
    }

    self->imove = imove;
}
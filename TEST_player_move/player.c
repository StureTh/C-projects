#include "player.h"
#include <stdint.h>
#include <stdlib.h>
#include "curses.h"

int8_t validMove(int8_t x, int8_t y);
static void playerMove(_player_t *self)
{
    int x = self->base.pos.x;
    int y = self->base.pos.y;
    char dir;

    timeout(0);
    dir = getch();
    
    switch(dir)
    {
        case 'w':
            if(validMove(x, y - 1))
            {
                self->base.pos.y -= 1;
            }
            break;
        case 's':
            if(validMove(x, y + 1))
            {
                self->base.pos.y += 1;
            }
            break;
        case 'a':
            if(validMove(x - 1, y))
            {
                self->base.pos.x -= 1;
            }
            break;
        case 'd':
            if(validMove(x + 1, y))
            {
                self->base.pos.x += 1;
            }
            break;
        default:
            break;
    }

}

void PLAYER_init(_player_t *self, uint8_t x, uint8_t y,uint16_t hp)
{
    self->base.type = PLAYER;
    self->base.pos.x = x;
    self->base.pos.y = y;
    
    self->base.sign = '$';
    self->base.hp = 150;
    
    self->base.move = (void*)playerMove;

}

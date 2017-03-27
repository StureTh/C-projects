#include "player.h"
#include <stdint.h>
#include <stdlib.h>
#include "curses.h"
#include "bullet.h"

int8_t OBJECT_validMove(int8_t x, int8_t y, object_t *self);

void shoot(_player_t *self)
{
    bullet_t *bullet;

    if(self->base.move_dir != NONE)
    {
        bullet = LLIST_push(&worldObjects, sizeof(bullet_t));
        BULLET_init(bullet, self->base.move_dir, &self->base.pos);
    }
}

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
            self->base.move_dir = UP;
            if(OBJECT_validMove(x, y - 1, &self->base))
            {
                self->base.pos.y -= 1;

            }

            break;
        case 's':
            self->base.move_dir = DOWN;
            if(OBJECT_validMove(x, y + 1, &self->base))
            {
                self->base.pos.y += 1;

            }

            break;
        case 'a':
            self->base.move_dir = LEFT;
            if(OBJECT_validMove(x - 1, y, &self->base))
            {
                self->base.pos.x -= 1;

            }

            break;
        case 'd':
            self->base.move_dir = RIGHT;
            if(OBJECT_validMove(x + 1, y, &self->base))
            {
                self->base.pos.x += 1;

            }

            break;

        case 'k':
            shoot(self);
            break;
        default:
            break;
    }

}
void player_takeDmg(_player_t *self, int dmg)
{
    self->base.hp -= dmg;
}
void PLAYER_init(_player_t *self, uint8_t x, uint8_t y)
{
    self->base.type = PLAYER;
    self->base.pos.x = x;
    self->base.pos.y = y;

    self->base.sign = '$';
    self->base.hp = 150;
    self->base.move_dir = NONE;
    self->base.walkable = false;
    self->base.moveable = false;
    self->base.move = (void*) playerMove;
    self->base.onColission = NULL;
    self->base.takeDmg = (void*)player_takeDmg;

}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#include <windef.h>

#include "bullet.h"

static coord_t getSpawnLocation(obj_dir_t direction, coord_t *source_coord)
{

    coord_t spawn_location;
    if(direction == UP)
    {
        spawn_location.x = source_coord->x;
        spawn_location.y = source_coord->y - 1;
    }
    else if(direction == DOWN)
    {
        spawn_location.x = source_coord->x;
        spawn_location.y = source_coord->y + 1;
    }
    else if(direction == LEFT)
    {
        spawn_location.x = source_coord->x - 1;
        spawn_location.y = source_coord->y;
    }
    else if(direction == RIGHT)
    {
        spawn_location.x = source_coord->x + 1;
        spawn_location.y = source_coord->y;
    }
    return spawn_location;
}

void bullet_move(bullet_t *self)
{  
    obj_dir_t direction = self->base.move_dir;

    if(direction == UP)
    {
        if(OBJECT_validMove(self->base.pos.x, self->base.pos.y -1, &self->base))
        {
            self->base.pos.y -= 1;
        }
        else
        {
             LLIST_pop(&worldObjects, self);
        }
    }
    else if(direction == DOWN)
    {
        if(OBJECT_validMove(self->base.pos.x, self->base.pos.y +1, &self->base))
        {
            self->base.pos.y += 1;
        }
        else
        {
            LLIST_pop(&worldObjects, self);
        }
    }
    else if(direction == LEFT)
    {
        if(OBJECT_validMove(self->base.pos.x -1, self->base.pos.y, &self->base))
        {
            self->base.pos.x -= 1;
        }
        else
        {
             LLIST_pop(&worldObjects, self);
        }
    }
    else if(direction == RIGHT)
    {
        if(OBJECT_validMove(self->base.pos.x +1, self->base.pos.y, &self->base))
        {
            self->base.pos.x += 1;
        }
        else
        {
             LLIST_pop(&worldObjects, self);
        }
    }      
}

void onCollision(bullet_t *self, object_t *object)
{
    if(object->takeDmg != NULL)
    {
        object->takeDmg(object, self->dmg);
    }
}

void BULLET_init(bullet_t *self, obj_dir_t direction, coord_t *source_coord)
{
    self->base.type = PROJECTILE;

    if(direction == UP || direction == DOWN)
    {
        self->base.sign = '*';
    }
    else
    {
        self->base.sign = '*';
    }
    self->base.pos = *source_coord; //getSpawnLocation(direction,source_coord);
    self->base.move_dir = direction;
    self->dmg = 10;
    self->base.alive = FALSE;
    self->base.moveable = FALSE;
    self->base.walkable = TRUE;
    self->base.onHit = (void*) onCollision;
    self->base.move = (void*) bullet_move;
}

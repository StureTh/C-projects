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
        spawn_location.y = source_coord->y-1;
    }
    else if(direction == DOWN)
    {
        spawn_location.x = source_coord->x;
        spawn_location.y = source_coord->y+1;
    }
    else if(direction == LEFT)
    {
        spawn_location.x = source_coord->x-1;
        spawn_location.y = source_coord->y;
    }
    else if(direction == RIGHT)
    {
        spawn_location.x = source_coord->x+1;
        spawn_location.y = source_coord->y;
    }
    return spawn_location;
}

void bullet_move(bullet_t *self)
{
    obj_dir_t direction = self->base.move_dir;
    
    if(direction == UP)
    {       
        self->base.pos.y -= 1;
    }
    else if(direction == DOWN)
    {
         self->base.pos.y += 1;
    }
    else if(direction == LEFT)
    {
        self->base.pos.x -= 1;
    }
    else if(direction == RIGHT)
    {
        if(OBJECT_validMove(self->base.pos.x,self->base.pos.y, self))
        {
            self->base.pos.x += 1;
        }
        else
        {
         LLIST_pop(&worldObjects,self);  
        }
        
    }
}
void onCollision(bullet_t *self, object_t object)
{
    if(object.alive)
    {
        object.hp -= self->dmg;
    }
}
void BULLET_init(bullet_t *self, obj_dir_t direction, coord_t *source_coord)
{
    if(direction == UP || direction == DOWN)
    {
        self->base.sign = '*';
    }
    else
    {
         self->base.sign = '*';
    }
    self->base.pos = getSpawnLocation(direction,source_coord);
    self->base.move_dir = direction;
    self->dmg = 10;
    self->base.alive = FALSE;
    self->base.moveable = FALSE;
    self->base.walkable = TRUE;
    self->base.onColission = (void*)onCollision;
    self->base.move = (void*)bullet_move;
}

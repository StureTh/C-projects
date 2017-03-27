/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "object.h"
#include "Llist.h"
#include "cacti.h"
#include "ze engine.h"

#include "dog.h"
#include "player.h"

int8_t OBJECT_checkColision(llist_t *llist_objects, int8_t pos_x, int8_t pos_y, object_t *self)
{
    node_t search;
    int8_t collision = 0;
    object_t *object;

    search = LLIST_searchStart(llist_objects);

    while((object = LLIST_searchNext(&search)))
    {
        if(object->pos.x == pos_x && object->pos.y == pos_y && object != self)
        {
            if(object->walkable == FALSE)
            {
                collision = 1;
            }
            if(self->type == PROJECTILE)
            {
                self->onHit(self, object);
                break;
            }
            if(object->onColission != NULL)
            {
                object->onColission(object, self);
            }
        }    
    }
    return collision;

}

int8_t OBJECT_validMove(int8_t x, int8_t y, object_t *self)
{
    int valid = 1;
    if(x < 0 || x > SCREEN_W - 1)
    {
        valid = 0;
    }
    if(y < 0 || y > SCREEN_H - 1)
    {
        valid = 0;
    }
    if(OBJECT_checkColision(&worldObjects, x, y, self))
    {
        valid = 0;
    }
    return valid;
}

void OBJECT_updateWorldObjects(llist_t *list)
{
    node_t search;
    object_t *object = NULL;
    dog_t *dog;

    search = LLIST_searchStart(list);
    object = LLIST_searchNext(&search);

    while(object != NULL)
    {
        if(object->type == ENEMY)
        {
            dog = (dog_t*) object;
            dog->target = &player1->base;
            dog->isChasing = true;
        }
        if(object->move)
        {
            object->move(object);
        }

        object = LLIST_searchNext(&search);
    }

}

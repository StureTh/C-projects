/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "object.h"
#include "Llist.h"
#include "cacti.h"


int8_t OBJECT_checkColision(llist_t *llist_objects, int8_t pos_x, int8_t pos_y)
{
    node_t search;
    int8_t collision = 0;
    object_t *object;

    search = LLIST_searchStart(llist_objects);

    while((object = LLIST_searchNext(&search)))
    {
        if(object->pos.x == pos_x && object->pos.y == pos_y)
        {
            if(object->walkable == FALSE)
            {
                collision = 1;
            }
            // onColision()
            break;
        }
    }
    return collision;
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "dog.h"
#include <math.h>
#include <stdbool.h>
static obj_dir_t pathfind(coord_t *self_coord, object_t *target)
{
    int shortest_distance;
    int distance = -1;
    obj_dir_t direction;
    int targetX = target->pos.x;
    int targetY = target->pos.y;
    int selfX;
    int selfY;

    if(self_coord->x == targetX)
    {
        if(self_coord->y > targetY)
        {
            shortest_distance = self_coord->y - targetY- 1;
            direction = UP;
        }
        else
        {
             shortest_distance = targetY - self_coord->y-1 ;
            direction = DOWN;
        }
        goto END;
    }
    else if(self_coord->y == targetY)
    {
        if(self_coord->x > targetX)
        {
             shortest_distance = self_coord->x - targetX -1;
            direction = LEFT;
        }
        else
        {
            shortest_distance = targetX - self_coord->x-1;
            direction = RIGHT;
        }
        goto END;
    }
    else
    {
        //up
        selfX = self_coord->x;
        selfY = self_coord->y - 1;
        distance = pow((selfX - targetX), 2) + pow((selfY - targetY), 2);
        distance = sqrt(distance);
        shortest_distance = distance;
        direction = UP;
            
        


        //down
        selfX = self_coord->x;
        selfY = self_coord->y + 1;
        distance = pow((selfX - targetX), 2) + pow((selfY - targetY), 2);
        distance = sqrt(distance);
        if(distance < shortest_distance)
        {
            shortest_distance = distance;
            direction = DOWN;
        }

        //left
        selfX = self_coord->x - 1;
        selfY = self_coord->y;
        distance = pow((selfX - targetX), 2) + pow((selfY - targetY), 2);
        distance = sqrt(distance);
        if(distance < shortest_distance)
        {
            shortest_distance = distance;
            direction = LEFT;
        }

        //right
        selfX = self_coord->x + 1;
        selfY = self_coord->y;
        distance = pow((selfX - targetX), 2) + pow((selfY - targetY), 2);
        distance = sqrt(distance);
        if(distance < shortest_distance)
        {
            shortest_distance = distance;
            direction = RIGHT;
        }
    }
END:
    if(shortest_distance < 2)
    {
       direction = NONE; 
    }
    return direction;
       
    
}
static void moveDog(dog_t *self)
{
    obj_dir_t direction;
    int x = self->base.pos.x;
    int y = self->base.pos.y;

    if(self->isChasing && self->target != NULL)
    {
        direction = pathfind(&self->base.pos, self->target);

        switch(direction)
        {
            case UP:
                self->base.move_dir = UP;
                if(OBJECT_validMove(x, y - 1, &self->base))
                {
                    self->base.pos.y -= 1;

                }

                break;
            case DOWN:
                self->base.move_dir = DOWN;
                if(OBJECT_validMove(x, y + 1, &self->base))
                {
                    self->base.pos.y += 1;

                }

                break;
            case LEFT:
                self->base.move_dir = LEFT;
                if(OBJECT_validMove(x - 1, y, &self->base))
                {
                    self->base.pos.x -= 1;

                }

                break;
            case RIGHT:
                self->base.move_dir = RIGHT;
                if(OBJECT_validMove(x + 1, y, &self->base))
                {
                    self->base.pos.x += 1;

                }

                break;
            default:
                break;
        }

    }
}

static void dogAttack(dog_t *self, object_t *object)
{
   int8_t x = self->base.pos.x;
    int8_t y = self->base.pos.y;
    
    switch(object->move_dir)
    {
        case UP:
            if(OBJECT_validMove(x, y - 1,&self->base))
            {
                self->base.pos.y -= 1;
            }
            break;
            
        case DOWN:
            if(OBJECT_validMove(x, y + 1,&self->base))
            {
                self->base.pos.y += 1;                
            }
            break;
            
        case LEFT:
            if(OBJECT_validMove(x - 1, y,&self->base))
            {
                self->base.pos.x -= 1;              
            }
            break;
            
        case RIGHT:
            if(OBJECT_validMove(x + 1, y,&self->base))
            {
                self->base.pos.x += 1;               
            }
            break;
            
        default:
            break;
    }
}

void DOG_init(dog_t *self, int8_t x, int8_t y)
{
    self->base.type = ENEMY;
    self->base.pos.x = x;
    self->base.pos.y = y;

    self->base.sign = 'D';
    self->base.hp = 50;

    
    self->isChasing = false;
    self->isIdle = false;
    self->target = NULL;
    self->base.alive = true;
    self->base.moveable = true;
    self->base.walkable = false;
    
    self->base.onColission = (void*)dogAttack;
    self->base.move = (void*) moveDog;
 
}
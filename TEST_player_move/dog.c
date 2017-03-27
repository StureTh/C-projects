/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "dog.h"
#include <math.h>

static obj_dir_t pathfind(coord_t *self_coord, object_t *target)
{
    int shortest_distance;
    int distance = -1;
    obj_dir_t direction = NONE;
    int targetX = target->pos.x;
    int targetY = target->pos.y;
    int selfX;
    int selfY;


    if(self_coord->x - 1 == targetX)
    {
        direction = LEFT;
    }
    else if(self_coord->x + 1 == targetX)
    {

        direction = RIGHT;
    }

    else if(self_coord->y - 1 == targetY)
    {

        direction = UP;
    }
    else if(self_coord->y + 1 == targetY)
    {
        direction = DOWN;
    }

    if(direction != NONE)
    {
        goto END2;
    }


    if(self_coord->x == targetX)
    {
        if(self_coord->y > targetY)
        {
            shortest_distance = self_coord->y - targetY - 1;
            direction = UP;
        }
        else
        {
            shortest_distance = targetY - self_coord->y - 1;
            direction = DOWN;
        }
        goto END;
    }
    else if(self_coord->y == targetY)
    {
        if(self_coord->x > targetX)
        {
            shortest_distance = self_coord->x - targetX - 1;
            direction = LEFT;
        }
        else
        {
            shortest_distance = targetX - self_coord->x - 1;
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
END2:
    return direction;


}

static bool dogInRange(dog_t *self)
{
    int8_t targetX = self->target->pos.x;
    int8_t targetY = self->target->pos.y;
    bool in_range = FALSE;

    if(targetX == self->base.pos.x && targetY - 2 == self->base.pos.y)
    {
        self->base.move_dir = DOWN;
        in_range = TRUE;
    }
    else if(targetX == self->base.pos.x && targetY + 2 == self->base.pos.y)
    {
        self->base.move_dir = UP;
        in_range = TRUE;
    }
    else if(targetY == self->base.pos.y && targetX - 2 == self->base.pos.x)
    {
        self->base.move_dir = RIGHT;
        in_range = TRUE;
    }
    else if(targetY == self->base.pos.y && targetX + 2 == self->base.pos.x)
    {
        self->base.move_dir = LEFT;
        in_range = TRUE;
    }
    return in_range;
}

bool canAttack(dog_t *self)
{
    bool can_attk = FALSE;
    if(self->base.attk_timer <= clock() && self->target != NULL)
    {
        can_attk = TRUE;
    }
    return can_attk;
}

void dogAttack(dog_t *self)
{
    obj_dir_t direction = self->base.move_dir;
    self->base.isAttacking = TRUE;
    self->base.attk_timer = clock() + 1500;
    self->base.attk_pos = self->base.pos;

    if(direction == DOWN)
    {
        if(OBJECT_validMove(self->base.pos.y + 1, self->base.pos.x, &self->base))
        {
            self->base.pos.y = self->target->pos.y - 1;
            self->base.sign = '^';
        }

    }
    if(direction == UP)
    {
        if(OBJECT_validMove(self->base.pos.y - 1, self->base.pos.x, &self->base))
        {
            self->base.pos.y = self->target->pos.y + 1;
            self->base.sign = 'v';
        }
    }
    if(direction == LEFT)
    {
        if(OBJECT_validMove(self->base.pos.y, self->base.pos.x - 1, &self->base))
        {
            self->base.pos.x = self->target->pos.x + 1;
            self->base.sign = '>';
        }
    }
    if(direction == RIGHT)
    {
        if(OBJECT_validMove(self->base.pos.y, self->base.pos.x + 1, &self->base))
        {
            self->base.pos.x = self->target->pos.x - 1;
            self->base.sign = '<';
        }
    }

    self->target->hp -= self->attk_dmg;

}

static void moveDog(dog_t *self)
{

    if(canAttack(self) && dogInRange(self))
    {
        dogAttack(self);
        return;
    }
    else if(self->base.isAttacking)
    {
        self->base.pos = self->base.attk_pos;
        self->base.isAttacking = FALSE;
        self->base.sign = 'D';
        return;
    }
    if(self->base.attk_timer >= clock() + 500)
    {
        return;
    }





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

static void dogOnCollision(dog_t *self, object_t *object)
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

static void dog_dead(dog_t *self)
{
    self->base.sign = 'X';
    self->base.move = NULL;
    self->base.onColission = NULL;
    self->target = NULL;
    self->isChasing = FALSE;
    self->base.walkable = TRUE;
    self->base.moveable = FALSE;
}

void dog_takeDmg(dog_t *self, int dmg)
{
    self->base.hp -= dmg;
    if(self->base.hp <= 0)
    {
        dog_dead(self);
    }
}

void DOG_init(dog_t *self, int8_t x, int8_t y)
{
    self->base.type = ENEMY;
    self->base.pos.x = x;
    self->base.pos.y = y;

    self->base.sign = 'D';
    self->base.hp = 30;
    self->attk_dmg = 40;


    self->isChasing = FALSE;
    self->isIdle = FALSE;
    self->target = NULL;
    self->base.alive = TRUE;
    self->base.moveable = TRUE;
    self->base.walkable = FALSE;

    self->base.isAttacking = FALSE;

    self->base.onColission = (void*) dogOnCollision;
    self->base.move = (void*) moveDog;
    self->base.takeDmg = (void*) dog_takeDmg;

}
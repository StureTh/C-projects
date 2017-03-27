/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "box.h"

int8_t OBJECT_validMove(int8_t x, int8_t y,object_t *self);

static void onCollision(box_t *self, object_t *object)
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

void BOX_init(box_t *self, int8_t x, int8_t y)
{
    self->base.type = ENVIROMENT;
    self->base.pos.x = x;
    self->base.pos.y = y;
    self->base.move_dir = NONE;
    self->base.sign = 'B';
    self->base.alive = FALSE;
    self->base.walkable = FALSE;
     
    self->base.hp = 10;
    self->desroyable = TRUE;
    
    self->base.move = NULL;
    self->base.takeDmg = NULL;
    self->base.onHit = NULL;
    self->base.onColission = (void*)onCollision;
}
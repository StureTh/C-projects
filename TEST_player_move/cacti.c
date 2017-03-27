/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "cacti.h"

static void imove(cacti_t *self)
{

}

void onColision(cacti_t *self, object_t *object)
{
    object->takeDmg(object, 5);
}

void CACTI_init(cacti_t *self, int8_t x, int8_t y)
{
    self->base.type = ENVIROMENT;
    self->base.pos.x = x;
    self->base.pos.y = y;

    self->base.sign = 'C';
    self->base.alive = FALSE;
    self->base.walkable = TRUE;
    self->base.moveable = FALSE;

    self->desroyable = TRUE;
    self->base.hp = 3;

    self->base.move = (void*) imove;
    self->base.takeDmg = NULL;
    self->base.onHit = NULL;
    self->base.onColission = (void*) onColision;


}
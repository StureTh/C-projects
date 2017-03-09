/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   enemy.h
 * Author: LIA2017
 *
 * Created on den 9 mars 2017, 10:38
 */

#ifndef ENEMY_H
#define ENEMY_H

#include "object.h"


typedef struct enemy 
{
    void (*move)(void);
}enemy_t;

#endif /* ENEMY_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   shop.h
 * Author: Sture
 *
 * Created on den 17 februari 2017, 13:52
 */

#ifndef SHOP_H
#define SHOP_H

#include "player.h"
#include "defense.h"
#include <stdbool.h>

 void populateShopeDefensives(void);
void SHOP_chooseDefenseItem(player_t *current_player);

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* SHOP_H */

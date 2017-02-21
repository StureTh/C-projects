#include "weapon.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>



void WEAPON_init(weapon_t *weapon, char *name, int16_t price, int8_t dmg)
{
  strcpy(weapon->name,name);
    weapon->price = price;
    weapon->dmg = dmg;
}
weapon_t createWeaponTypes(char *name, int16_t price, int8_t dmg)
{
    weapon_t weapon_type;

    

    return weapon_type;
}

int8_t WEAPON_useWeapon(weapon_t *attk_wpn, defense_t *opponent_deff)
{
    int8_t dmg_reduction;
    int8_t dmg_dealt;
   float_t total_dmg_dealt =0;
    
   
    dmg_dealt = attk_wpn->dmg;
    dmg_reduction = (100 - opponent_deff->defense);  

    
    total_dmg_dealt = dmg_dealt * dmg_reduction;
    total_dmg_dealt = total_dmg_dealt /100;
    
    if(total_dmg_dealt < 0)
      {
        total_dmg_dealt = 0;
      }
    
    
    return total_dmg_dealt;
       
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <stdint.h>
#include "player.h"

weapon_t createWeaponTypes(char *name, int16_t price, int8_t dmg)
{
    weapon_t weapon_type;

    strcpy(weapon_type.name,name);
    weapon_type.price = price;
    weapon_type.dmg = dmg;

    return weapon_type;
}

int8_t WEAPON_useWeapon(player_t *attacker, player_t *opponent, char *msg)
{
    int8_t dmg_reduction;
    int8_t dmg_dealt;
    int8_t total_dmg_dealt;
    
    dmg_dealt = attacker->weapon->dmg;
    dmg_reduction = opponent->defense->defense;  
    
    total_dmg_dealt = (dmg_dealt - dmg_reduction);
    
    char msg_output[] = "You hit %s with your %s, for %i dmg";
    strcpy(msg, msg_output);
    
    return total_dmg_dealt;
       
}
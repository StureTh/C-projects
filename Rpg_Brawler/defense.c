#include "defense.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


defense_t createDefenseTypes(char *name, int price, int defense)
{
    defense_t defense_types;


    strcpy(defense_types.name,name);
    defense_types.price = price;
    defense_types.defense = defense;

    return defense_types;


}

void DEFENSE_init(defense_t *defense, char *name, int price, int deff)
{
  strcpy(defense->name,name);
    defense->price = price;
    defense->defense = deff;
}


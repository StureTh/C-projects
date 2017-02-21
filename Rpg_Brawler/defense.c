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



#include "defense.h"
#include <string.h>



void DEFENSE_init(defense_t *defense, char *name, int price, int deff)
{
  strcpy(defense->name,name);
    defense->price = price;
    defense->defense = deff;
}


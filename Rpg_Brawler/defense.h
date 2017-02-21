
#ifndef DEFENSE_H
#define DEFENSE_H


#include <stdint.h>


typedef struct defense{
    char name[20];
    uint16_t price;
    uint8_t defense;

}defense_t;

void DEFENSE_init(defense_t *defense, char *name, int price, int deff);
defense_t createDefenseTypes(char *name,int price,int defense);




#endif /* DEFENSE_H */


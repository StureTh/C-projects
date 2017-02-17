
#ifndef DEFENSE_H
#define DEFENSE_H

#include <stdbool.h>
#include <stdint.h>


typedef struct defense{
    char name[20];
    uint16_t price;
    uint8_t defense;

}defense_t;

defense_t createDefenseTypes(char *name,int price,int defense);


#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* DEFENSE_H */


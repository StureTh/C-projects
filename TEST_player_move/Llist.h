#include <stdint.h>

#ifndef _LLIST_H_
#define _LLIST_H_


typedef struct node
{
    struct node *next;
    void *obj;

}node_t;

typedef struct linked_list
{
    struct node node_zero;
    struct node *node_search;
    int8_t nbr_nodes;

} llist_t;
node_t LLIST_searchStart(llist_t *list);
void *LLIST_searchNext(node_t *search_node);
void *LLIST_push(llist_t *list, uint8_t size);
void LLIST_pop(llist_t *list, void *obj);
/**
 * Init!
 * @args list as input
 */
void LLIST_init(llist_t *list);




#endif /* _LLIST_H_ */

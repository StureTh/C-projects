#include "llist.h"
#include <stdlib.h>

node_t LLIST_searchStart(llist_t *list)
{     
    return list->node_zero;        
}

void *LLIST_searchNext(node_t *search_node)
{
    void *object = NULL;

    if(search_node->next != NULL)
    {
        object = search_node->next->obj;
        search_node->next = search_node->next->next;       
    }

    return object;
}

static node_t *createNode(void)
{
    node_t *node;
    node = malloc(sizeof (node_t));
    node->next = NULL;
    

    return node;
}

static void removeNode(node_t *node)
{
    free(node);
}

void *LLIST_push(llist_t *list, uint8_t size)
{
    void *obj;
    node_t *node;
    node_t *curr_node;

    node = createNode();
    obj = malloc(size);
    node->obj = obj;

    for(curr_node = &list->node_zero; curr_node->next != NULL;
            curr_node = curr_node->next);

    curr_node->next = node;
    list->nbr_nodes++;

    return obj;
}

void LLIST_pop(llist_t *list, void *obj)
{
    node_t *node_curr;
    node_t *node_prev;

    node_curr = list->node_zero.next;
    node_prev = &list->node_zero;

    while(node_curr != NULL)
    {
        if(node_curr->obj == obj)
        {
            node_prev->next = node_curr->next;
            free(node_curr->obj);
            free(node_curr);
            list->nbr_nodes--;
            break;
        }
        
        node_prev = node_curr;
        node_curr = node_curr->next;
    }

}

void LLIST_init(llist_t *list)
{
    list->node_zero = *createNode();
    list->nbr_nodes = 0;
  
}
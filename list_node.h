//
// Created by tbess on 2/4/17.
//


#ifndef LINKEDLIST_LIST_NODE_H
#define LINKEDLIST_LIST_NODE_H
#include "linked_list.h"

typedef struct _list_node {
    void *data;
    struct _list_node *next;
} list_node;

#endif //LINKEDLIST_LIST_NODE_H

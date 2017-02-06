//
// Created by tbess on 2/4/17.
//

#ifndef LINKEDLIST_LINKED_LIST_H
#define LINKEDLIST_LINKED_LIST_H

#include "list_node.h"

typedef struct _linked_list {
    list_node *head;
    list_node *tail;
    int size;
} linked_list;

typedef void (*listIterator)(list_node *node);

linked_list *list_create();
list_node *list_append(linked_list *list, void *data, size_t data_size);
void list_append_node(linked_list *list, list_node *node);
void list_each(linked_list *list, listIterator iterator);
void list_destroy(linked_list *list);
void list_remove(linked_list *list, list_node *node);

#endif //LINKEDLIST_LINKED_LIST_H

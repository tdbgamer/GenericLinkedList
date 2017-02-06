//
// Created by tbess on 2/4/17.
//

#include <stdlib.h>
#include <assert.h>
#include "linked_list.h"

static void free_node(list_node *node) {
//    free(node->data);
    free(node);
}

linked_list *list_create() {
    linked_list *new_list = (linked_list *) malloc(sizeof(linked_list));
    new_list->head = NULL;
    new_list->tail = NULL;
    return new_list;
}

void list_append_node(linked_list *list, list_node *node) {
    if (list->size == 0) {
        list->head = list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

list_node *list_append(linked_list *list, void *data, size_t data_size) {
    list_node *newNode = (list_node *) malloc(sizeof(list_node));
    newNode->data = data;
    newNode->next = NULL;
    list_append_node(list, newNode);
    return newNode;
}

void list_each(linked_list *list, listIterator iterator) {
    assert(iterator != NULL);

    list_node *current = list->head;
    while (current != NULL) {
        iterator(current);
        current = current->next;
    }
}

void list_destroy(linked_list *list) {
    list_node *next = NULL;
    list_node *current = list->head;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

void list_remove(linked_list *list, list_node *node) {
    list_node **indirect = &list->head;

    while ((*indirect) != node) {
        indirect = &(*indirect)->next;
    }

    *indirect = node->next;
    free_node(node);
    list->size--;
}
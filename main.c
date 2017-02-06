#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "linked_list.h"
#include "list_node.h"

void print_nodes_int(list_node *node) {
    printf("%d\n", (int) node->data);
}

int main() {
    linked_list *my_list = list_create();

    list_node *first = list_append(my_list, 1, sizeof(int));
    list_node *second = list_append(my_list, 2, sizeof(int));
    list_each(my_list, print_nodes_int);

    puts("Removed item");

    list_remove(my_list, second);
    list_each(my_list, print_nodes_int);
    list_destroy(my_list);

    return 0;
}

#include "containerslib/linked_list.h"
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node* node_init(int value, Node *next) {
    Node *n = malloc(sizeof(Node));

    n->value = value;
    n->next = next;

    return n;
}

void node_free(Node *n) {
    free(n);
}

struct LinkedList {
    Node *head;
    int size;
};

LinkedList* linked_list_init() {
    LinkedList *l = malloc(sizeof(LinkedList));

    l->size = 0;
    l->head = NULL;

    return l;
}

void __linked_list_free_rec(Node *n) {
    if(n == NULL) return;

    __linked_list_free_rec(n->next);
    free(n);
}

void linked_list_free(LinkedList* l) {
    __linked_list_free_rec(l->head);
    free(l);
}

void linked_list_insert(LinkedList* l, int value) {
    Node *n = node_init(value, l->head);
    l->head = n;

    l->size++;
}

int linked_list_size(LinkedList* l) {
    return l->size;
}

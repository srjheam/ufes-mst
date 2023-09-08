#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

typedef struct LinkedList LinkedList;

/**
 * @brief Initializes a linked list
 *
 * @return A linked list
 */
LinkedList* linked_list_init();

/**
 * @brief Frees a linked list
 *
 * @param l The linked list to be freed
 *
 * @return
 */
void linked_list_free(LinkedList* l);

/**
 * @brief Returns the size of a linked list
 *
 * @param l The linked list
 *
 * @return The size of the linked list
 */
int linked_list_size(LinkedList* l);

/**
 * @brief Inserts the value at the front of the linked list
 *
 * @param l The linked list
 * @param value The value to be inserted
 *
 * @return
 */
void linked_list_insert(LinkedList* l, int value);

// int linked_list_pop_front(LinkedList* l);

#endif

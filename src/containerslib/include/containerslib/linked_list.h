#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <stdbool.h>

typedef struct LinkedList LinkedList;

typedef struct ListIterator ListIterator;

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
 */
void linked_list_insert(LinkedList* l, int value);

// int linked_list_pop_front(LinkedList* l);

/**
 * @brief Prints the linked list
 *
 * @param l The linked list
 */
void linked_list_print(LinkedList *l);

/**
 * @brief Initializes a list iterator
 *
 * @param l The linked list
 *
 * @return A list iterator
 */
ListIterator *list_iterator_init(LinkedList *l);

/**
 * @brief Frees a list iterator
 *
 * @param it The list iterator to be freed
 */
void list_iterator_free(ListIterator *it);

/**
 * @brief Returns the next value of the list iterator
 *
 * @param it The list iterator
 *
 * @return int The next value of the list iterator
 */
int list_iterator_next(ListIterator *it);

/**
 * @brief Returns true if the list iterator is over
 *
 * @param it The list iterator
 *
 * @return bool True if the list iterator is over, false otherwise
 */
bool list_iterator_is_over(ListIterator *it);

#endif

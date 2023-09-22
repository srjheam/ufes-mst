#ifndef _TOURLIB_TOUR_H_
#define _TOURLIB_TOUR_H_

#include "tourlib/mst.h"

typedef struct Tour Tour;

/**
 * @brief Initialize a Tour object.
 * 
 * @param name The name of the tour.
 * @param dimension The dimension of the tour.
 * @return Tour* The initialized Tour object.
 */
Tour *tourlib_tour_init(char *name, int dimension);

/**
 * @brief Makes a DFS on the MST and stores the path in the tour strcture.
 * 
 * @param tour The tour.
 * @param adjacency_list The edges of the MST.
 */
void tourlib_tour_path(Tour *tour, LinkedList **adjacency_list);

/**
 * @brief Get the name of the tour.
 * 
 * @param tour The tour.
 * @return char* The name of the tour.
 */
char *tourlib_tour_name(Tour *tour);

/**
 * @brief Get the dimension of the tour.
 * 
 * @param tour The tour.
 * @return int The dimension of the tour.
 */
int tourlib_tour_dimension(Tour *tour);

/**
 * @brief Get the vertexes of the tour.
 * 
 * @param tour The tour.
 * @return int* The vertexes of the tour.
 */
int *tourlib_tour_vertexes(Tour *tour);

/**
 * @brief Frees the tour.
 * 
 * @param tour The tour to be freed.
 */
void tourlib_tour_free(Tour *tour);

#endif

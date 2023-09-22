#ifndef _TOURLIB_MST_
#define _TOURLIB_MST_

#include "containerslib/linked_list.h"
#include "tourlib/edge.h"

typedef struct Mst Mst;

/**
 * @brief Initialize a new MST.
 * 
 * @param name The name of the MST.
 * @param dimension The dimension of the MST.
 * @return Mst* The new MST.
 */
Mst *tourlib_mst_init(char *name, int dimension);

/**
 * @brief Add an edge to the MST.
 * 
 * @param mst The MST.
 * @param id_u The id of the first vertex.
 * @param id_v The id of the second vertex.
 */
void tourlib_mst_add_edge(Mst *mst, int id_u, int id_v);

/**
 * @brief Get the name of the MST.
 * 
 * @param mst The MST.
 * @return char* The name of the MST.
 */
char *tourlib_mst_name(Mst *mst);

/**
 * @brief Get the dimension of the MST.
 * 
 * @param mst The MST.
 * @return int The dimension of the MST.
 */
int tourlib_mst_dimension(Mst *mst);

/**
 * @brief Get the edges of the MST.
 * 
 * @param mst The MST.
 * @return LinkedList** The edges of the MST.
 */
LinkedList **tourlib_mst_edges(Mst *mst);

/**
 * @brief Frees the MST.
 * 
 * @param mst The MST.
 */
void tourlib_mst_free(Mst *mst);

/**
 * @brief Print the MST.
 * 
 * @param mst The MST.
 */
void tourlib_mst_print(Mst *mst);

#endif

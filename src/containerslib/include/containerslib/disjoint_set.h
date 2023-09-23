#ifndef _CONTAINERSLIB_DISJOINT_SET_
#define _CONTAINERSLIB_DISJOINT_SET_

typedef struct DisjointSet DisjointSet;

/**
 * @brief Initializes a new disjoint set.
 *
 * @param n The number of vertices of the graph.
 * @return A pointer to the new disjoint set.
 */
DisjointSet *disjointset_init(int n);

/**
 * @brief Finds the root of the set that contains the vertex p.
 *
 * @param ds The disjoint set.
 * @param p The vertex.
 * @return The root of the set that contains the vertex p.
 */
int disjointset_find(DisjointSet *ds, int p);

/**
 * @brief Unites the sets that contain the vertices p and q.
 *
 * @param ds The disjoint set.
 * @param p The vertex p.
 * @param q The vertex q.
 */
void disjointset_union(DisjointSet *ds, int p, int q);

/**
 * @brief Frees the memory of the disjoint set.
 *
 * @param ds The disjoint set.
 */
void disjointset_free(DisjointSet *ds);

#endif

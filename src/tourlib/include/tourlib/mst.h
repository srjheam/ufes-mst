#ifndef _TOURLIB_MST_
#define _TOURLIB_MST_

#include "tourlib/edge.h"

typedef struct Mst Mst;

Mst *tourlib_mst_init(char *name, int dimension, Edge *edges);

char *tourlib_mst_name(Mst *mst);

int tourlib_mst_dimension(Mst *mst);

Edge *tourlib_mst_edges(Mst *mst);

void tourlib_mst_free(Mst *mst);

#endif

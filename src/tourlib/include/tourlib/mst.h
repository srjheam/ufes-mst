#ifndef _TOURLIB_MST_
#define _TOURLIB_MST_

#include "tourlib/edge.h"

typedef struct Mst Mst;

Mst *tourlib_mst_init(char *name, int dimension, Edge *edges);

void tourlib_mst_free(Mst *mst);

#endif

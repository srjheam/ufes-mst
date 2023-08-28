#include <stdlib.h>

#include "tourlib/mst.h"

#include "tsplib/tsp.h"

struct Mst {
    char *name;
    int dimension;
    Edge *edges;
};

Mst *tourlib_mst_init(char *name, int dimension, Edge *edges) {
    Mst *mst = malloc(sizeof *mst);

    mst->name = name;
    mst->dimension = dimension;
    mst->edges = edges;

    return mst;
}

char *tourlib_mst_name(Mst *mst) {
    return mst->name;
}

int tourlib_mst_dimension(Mst *mst) {
    return mst->dimension;
}

Edge *tourlib_mst_edges(Mst *mst) {
    return mst->edges;
}

void tourlib_mst_free(Mst *mst) {
    free(mst->name);

    free(mst->edges);

    free(mst);
}

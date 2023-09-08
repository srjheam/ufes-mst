#include <stdlib.h>
#include <stdio.h>

#include "tourlib/mst.h"

#include "tsplib/tsp.h"
#include "containerslib/linked_list.h"

struct Mst {
    char *name;
    int dimension;
    // Edge *edges;
    LinkedList **adjacency_list;
};


// Mst *tourlib_mst_init(char *name, int dimension, Edge *edges);

Mst *tourlib_mst_init(char *name, int dimension) {
    Mst *mst = malloc(sizeof *mst);

    mst->name = name;
    mst->dimension = dimension;
    // mst->edges = edges;
    
    mst->adjacency_list = malloc(sizeof(LinkedList *) * (dimension + 1));

    for(int i = 0; i < dimension + 1; i++) {
        mst->adjacency_list[i] = linked_list_init();
    }

    return mst;
}

void tourlib_mst_add_edge(Mst *mst, Edge edge) {
    printf("%d ", edge.id_u);
    printf("%d\n", edge.id_v);
    linked_list_insert(mst->adjacency_list[edge.id_u], edge.id_v);
    linked_list_insert(mst->adjacency_list[edge.id_v], edge.id_u);
}

char *tourlib_mst_name(Mst *mst) {
    return mst->name;
}

int tourlib_mst_dimension(Mst *mst) {
    return mst->dimension;
}

Edge *tourlib_mst_edges(Mst *mst) {
    // return mst->edges;
}

void tourlib_mst_free(Mst *mst) {
    free(mst->name);

    // free(mst->edges);

    for(int i = 0; i < mst->dimension + 1; i++) {
        linked_list_free(mst->adjacency_list[i]);
    }

    free(mst->adjacency_list);

    free(mst);
}

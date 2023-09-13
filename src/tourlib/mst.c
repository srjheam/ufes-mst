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
    
    mst->adjacency_list = malloc(sizeof(LinkedList *) * dimension);

    for(int i = 0; i < dimension; i++)
        mst->adjacency_list[i] = linked_list_init();

    return mst;
}

void tourlib_mst_add_edge(Mst *mst, int id_u, int id_v) {
    linked_list_insert(mst->adjacency_list[id_u - 1], id_v);
    linked_list_insert(mst->adjacency_list[id_v - 1], id_u);
}

char *tourlib_mst_name(Mst *mst) {
    return mst->name;
}

int tourlib_mst_dimension(Mst *mst) {
    return mst->dimension;
}

LinkedList **tourlib_mst_edges(Mst *mst) {
    // return mst->edges;
    return mst->adjacency_list;
}

void tourlib_mst_free(Mst *mst) {
    free(mst->name);

    // free(mst->edges);

    for(int i = 0; i < mst->dimension; i++) {
        linked_list_free(mst->adjacency_list[i]);
    }

    free(mst->adjacency_list);

    free(mst);
}

void tourlib_mst_print(Mst *mst) {
    for(int i = 1; i < mst->dimension + 1; i++) {
        printf("%d: ", i);
        linked_list_print(mst->adjacency_list[i]);
    }
}

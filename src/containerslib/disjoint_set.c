#include <stdlib.h>

#include "containerslib/disjoint_set.h"

struct DisjointSet
{
    int n;
    int *id;
    int *sz;
};

DisjointSet *disjointset_init(int n) {
    DisjointSet *ds = malloc(sizeof *ds);

    ds->n = n;
    ds->id = malloc(n * sizeof *ds->id);
    ds->sz = malloc(n * sizeof *ds->sz);
    for (int i = 0; i < n; i++) {
        ds->id[i] = i;
        ds->sz[i] = 1;
    }

    return ds;
}

int disjointset_find(DisjointSet *ds, int p) {
    while (p != ds->id[p]) {
        ds->id[p] = ds->id[ds->id[p]];
        p = ds->id[p];
    }
    return p;
}

void disjointset_union(DisjointSet *ds, int p, int q) {
    int i = disjointset_find(ds, p);
    int j = disjointset_find(ds, q);

    if (i == j) return;
    if (ds->sz[i] < ds->sz[j]) { ds->id[i] = j; ds->sz[j] += ds->sz[i]; }
    else { ds->id[j] = i; ds->sz[i] += ds->sz[j]; }
}

void disjointset_free(DisjointSet *ds) {
    free(ds->id);
    free(ds->sz);

    free(ds);
}

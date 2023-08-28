#ifndef _CONTAINERSLIB_DISJOINT_SET_
#define _CONTAINERSLIB_DISJOINT_SET_

typedef struct DisjointSet DisjointSet;

DisjointSet *disjointset_init(int n);

int disjointset_find(DisjointSet *ds, int p);

void disjointset_union(DisjointSet *ds, int p, int q);

void disjointset_free(DisjointSet *ds);

#endif

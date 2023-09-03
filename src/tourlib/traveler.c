#include <string.h>
#include <math.h>
#include <float.h>

#include "tourlib/traveler.h"

#include "containerslib/heap.h"
#include "containerslib/disjoint_set.h"

float __tourlib_traveler_distance(NodeCoord u, NodeCoord v) {
    // euclidean distance
    return sqrt(pow(u.x - v.x, 2) + pow(u.y - v.y, 2));
}

int __cmp_edges(const Edge *u, const Edge *v) {
    // https://stackoverflow.com/a/17341
    // https://stackoverflow.com/a/65015333
    return fabs(u->distance - v->distance) < FLT_EPSILON
        ? 0
        : u->distance > v->distance + FLT_EPSILON
            ? 1
            : -1;
}

void tourlib_generate_travel(Tsp* tsp, Mst **out_mst, Tour **out_tour) {
    // algorithm Kruskal(G) is
    // F:= ∅
    #ifdef EX_HEAP
    Heap *heap = heap_init(MIN_HEAP, tsplib_tsp_dimension(tsp) * (tsplib_tsp_dimension(tsp) - 1) / 2, sizeof(Edge), NULL);
    #else
    int ledges = 0;
    Edge *edges = malloc(sizeof(Edge) * tsplib_tsp_dimension(tsp) * (tsplib_tsp_dimension(tsp) - 1) / 2);
    #endif

    // for each v ∈ G.V do
    NodeCoord *node_coords = tsplib_tsp_node_coords(tsp);
    for (int i = 0; i < tsplib_tsp_dimension(tsp); i++) {
        for (int j = i + 1; j < tsplib_tsp_dimension(tsp); j++) {
            Edge edge = {
                .id_u = node_coords[i].id,
                .id_v = node_coords[j].id,
                .distance = __tourlib_traveler_distance(node_coords[i], node_coords[j])
            };

            // MAKE-SET(v)
            #ifdef EX_HEAP
            heap_push(heap, &edge, edge.distance);
            #else
            // substituir ledges por super conta algebrica
            edges[ledges++] = edge;
            #endif
        }
    }

    #ifndef EX_HEAP
    qsort(edges, tsplib_tsp_dimension(tsp) * (tsplib_tsp_dimension(tsp) - 1) / 2, sizeof(Edge), (cmp_fn)__cmp_edges);
    #endif

    int lmst_edges = 0;
    Edge *mst_edges = malloc(sizeof(Edge) * (tsplib_tsp_dimension(tsp) - 1));

    // for each (u, v) in G.E ordered by weight(u, v), increasing do
    DisjointSet *ds = disjointset_init(tsplib_tsp_dimension(tsp));
    for (int i = 0; i < tsplib_tsp_dimension(tsp) * (tsplib_tsp_dimension(tsp) - 1) / 2 && lmst_edges < tsplib_tsp_dimension(tsp) - 1; i++)
    {
        Edge curr = edges[i];
        if (disjointset_find(ds, curr.id_u - 1) != disjointset_find(ds, curr.id_v - 1)) {
            // if FIND-SET(u) ≠ FIND-SET(v)
            // F:= F ∪ {(u, v)}
            // UNION(u, v)
            disjointset_union(ds, curr.id_u - 1, curr.id_v - 1);

            mst_edges[lmst_edges++] = curr;
        }
    }
    disjointset_free(ds);
    free(edges);


    *out_mst = tourlib_mst_init(strdup(tsplib_tsp_name(tsp)), tsplib_tsp_dimension(tsp), mst_edges);
    *out_tour = tourlib_tour_init(strdup(tsplib_tsp_name(tsp)), tsplib_tsp_dimension(tsp), 0);
}

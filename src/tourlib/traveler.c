#include <math.h>

#include "tourlib/traveler.h"

#include "containerslib/heap.h"

double __tourlib_traveler_distance(NodeCoord u, NodeCoord v) {
    // euclidean distance
    return sqrt(pow(u.x - v.x, 2) + pow(u.y - v.y, 2));
}

void tourlib_generate_travel(Tsp* tsp, Mst **out_mst, Tour **out_tour) {
    // algorithm Kruskal(G) is
    // F:= ∅
    Heap *heap = heap_init(MIN_HEAP, tsplib_tsp_dimension(tsp) * (tsplib_tsp_dimension(tsp) - 1) / 2, sizeof(Edge), NULL);

    // for each v ∈ G.V do
    NodeCoord *node_coords = tsplib_tsp_node_coords(tsp);
    for (int i = 0; i < tsplib_tsp_dimension(tsp); i++) {
        for (int j = i + 1; j < tsplib_tsp_dimension(tsp); j++) {
            Edge edge = {
                .id_u = node_coords[i].id,
                .id_v = node_coords[j].id,
            };

            // MAKE-SET(v)
            heap_push(heap, &edge, __tourlib_traveler_distance(node_coords[i], node_coords[j]));
        }
    }

    // for each (u, v) in G.E ordered by weight(u, v), increasing do

}

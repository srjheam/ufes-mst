#include "tourlib/mst_serdes.h"

void tourlib_mst_serialize(Mst *mst, FILE *f) {
    fprintf(f, "NAME: %s\n", tourlib_mst_name(mst));
    fprintf(f, "TYPE: MST\n");
    fprintf(f, "DIMENSION: %d\n", tourlib_mst_dimension(mst));
    fprintf(f, "MST_SECTION\n");
    Edge *edges = tourlib_mst_edges(mst);
    for (int i = 0; i < tourlib_mst_dimension(mst) - 1; i++) {
        fprintf(f, "%d %d\n", edges[i].id_u, edges[i].id_v);
    }
    fprintf(f, "EOF\n");
}

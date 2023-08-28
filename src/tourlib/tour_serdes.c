#include "tourlib/tour_serdes.h"

void tourlib_tour_serialize(Tour *mst, FILE *f) {
    fprintf(f, "NAME: %s\n", tourlib_tour_name(mst));
    fprintf(f, "TYPE: TOUR\n");
    fprintf(f, "DIMENSION: %d\n", tourlib_tour_dimension(mst));
    fprintf(f, "TOUR_SECTION\n");
    int *vertexes = tourlib_tour_vertexes(mst);
    for (int i = 0; i < tourlib_tour_dimension(mst); i++) {
        fprintf(f, "%d\n", vertexes[i]);
    }
    fprintf(f, "EOF\n");
}

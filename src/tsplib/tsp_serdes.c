#include <stdlib.h>

#include "tsplib/tsp_serdes.h"

Tsp *tsplib_tsp_deserialize(FILE *f) {
    // the current implementation assumes
    // that the file is valid and well-formed;
    // the type is always TSP;
    // the edge weight type is always EUC_2D;
    // the node coord section has the same number of lines as the dimension;

    // jump straight to the name
    fseek(f, 6, SEEK_CUR);

    char *name = NULL;
    size_t len = 0;
    if (getline(&name, &len, f) == -1) {
        free(name);
        return NULL;
    }

    // jump COMMENT line
    if(fscanf(f, "%*[^\n]\n")){};

    // jump TYPE line
    if(fscanf(f, "%*[^\n]\n")){};

    enum TspType type = TSP;

    // jump straight to the dimension
    fseek(f, 11, SEEK_CUR);

    int dimension;
    if(fscanf(f, "%d", &dimension)){};

    enum EdgeWeightType edge_weight_type = EUC_2D;

    // jump EDGE_WEIGHT_TYPE, NODE_COORD_SECTION line
    fseek(f, 44, SEEK_CUR);

    NodeCoord *node_coords = malloc((sizeof *node_coords) * dimension);
    for (int i = 0; i < dimension; i++) {
        int id;
        double x, y;
        if(fscanf(f, "%d %lf %lf", &id, &x, &y)){};
        

        node_coords[i].id = id;
        node_coords[i].x = x;
        node_coords[i].y = y;
    }

    Tsp *tsp = tsplib_tsp_init(name, type, dimension, edge_weight_type, node_coords);
    return tsp;
}

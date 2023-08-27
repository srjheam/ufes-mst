#include <stdlib.h>

#include "tsplib/tsp.h"
#include "tsplib/node_coord.h"

struct Tsp
{
    char *name; ///< Identifies the data file.
    enum TspType type; ///< Specifies the type of the data.
    int dimension; ///< For a TSP or ATSP, the dimension is the number of its nodes. For a CVRP, it is the total number of nodes and depots. For a TOUR file it is the dimension of the corresponding problem.
    enum EdgeWeightType edge_weight_type; ///< Specifies how the edge weights (or distances) are given.
    NodeCoord *node_coords; ///< The coordinates of the nodes of the graph.
};

Tsp *tsplib_tsp_init(char *name, enum TspType type, int dimension, enum EdgeWeightType edge_weight_type, NodeCoord *node_coords) {
    Tsp *tsp = malloc(sizeof *tsp);

    tsp->name = name;
    tsp->type = type;
    tsp->dimension = dimension;
    tsp->edge_weight_type = edge_weight_type;
    tsp->node_coords = node_coords;

    return tsp;
}

void tsplib_tsp_free(Tsp *tsp) {
    free(tsp->name);
    
    free(tsp->node_coords);

    free(tsp);
}

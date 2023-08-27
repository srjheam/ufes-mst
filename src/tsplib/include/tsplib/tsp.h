#ifndef _TSPLIB_TSP_
#define _TSPLIB_TSP_

#include "tsplib/node_coord.h"

/// @brief Represents a TSP file.
typedef struct Tsp Tsp;

/// @brief Represents a TSP file type.
enum TspType {
    TSP
};

/// @brief Represents a TSP file edge weight type.
enum EdgeWeightType {
    EUC_2D
};

/// @brief Instantiates a new instance of the Tsp structure.
/// @param name Identifies the data file.
/// @param type Specifies the type of the data.
/// @param dimension For a TSP or ATSP, the dimension is the number of its nodes. For a CVRP, it is the total number of nodes and depots. For a TOUR file it is the dimension of the corresponding problem.
/// @param edge_weight_type Specifies how the edge weights (or distances) are given.
/// @param node_coords The coordinates of the nodes of the graph.
/// @return 
Tsp *tsplib_tsp_init(char *name, enum TspType type, int dimension, enum EdgeWeightType edge_weight_type, NodeCoord *node_coords);

void tsplib_tsp_free(Tsp *tsp);

#endif

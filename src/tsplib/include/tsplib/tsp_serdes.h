#ifndef _TSPLIB_TSP_SERDES_
#define _TSPLIB_TSP_SERDES_

#include <stdio.h>

#include "tsplib/tsp.h"

/// @brief Parses the TSP file into a Tsp structure.
/// @param f The TSP file to parse.
/// @return A Tsp structure representing the TSP file.
Tsp *tsplib_tsp_deserialize(FILE *f);

#endif

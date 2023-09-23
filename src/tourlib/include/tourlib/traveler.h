#ifndef _TOURLIB_TRAVELER_H_
#define _TOURLIB_TRAVELER_H_

#include "tourlib/mst.h"
#include "tourlib/tour.h"

#include "tsplib/tsp.h"

/**
 * @brief Generate a minimum spanning tree and tour from the given TSP.
 *
 * @param tsp The TSP to generate the MST and tour from.
 * @param out_mst The MST to generate.
 * @param out_tour The tour to generate.
 */
void tourlib_generate_travel(Tsp* tsp, Mst **out_mst, Tour **out_tour);

#endif

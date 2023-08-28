#ifndef _TOURLIB_TRAVELER_H_
#define _TOURLIB_TRAVELER_H_

#include "tourlib/mst.h"
#include "tourlib/tour.h"

#include "tsplib/tsp.h"

void tourlib_generate_travel(Tsp* tsp, Mst **out_mst, Tour **out_tour);

#endif

#ifndef _TOURLIB_TOUR_SERDES_H_
#define _TOURLIB_TOUR_SERDES_H_

#include <stdio.h>

#include "tourlib/tour.h"

void tourlib_tour_serialize(Tour *tour, FILE *f);

#endif

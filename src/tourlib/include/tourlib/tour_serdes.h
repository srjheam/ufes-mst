#ifndef _TOURLIB_TOUR_SERDES_H_
#define _TOURLIB_TOUR_SERDES_H_

#include <stdio.h>

#include "tourlib/tour.h"

/**
 * @brief Print the tour to the given file.
 *
 * @param tour The tour to serialize.
 * @param f The file to print to.
 */
void tourlib_tour_serialize(Tour *tour, FILE *f);

#endif

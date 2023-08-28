#ifndef _TOURLIB_TOUR_H_
#define _TOURLIB_TOUR_H_

typedef struct Tour Tour;

Tour *tourlib_tour_init(char *name, int dimension, int *vertexes);

char *tourlib_tour_name(Tour *tour);

int tourlib_tour_dimension(Tour *tour);

int *tourlib_tour_vertexes(Tour *tour);

void tourlib_tour_free(Tour *tour);

#endif

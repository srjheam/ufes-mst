#include "tourlib/tour.h"

struct Tour
{
    char *name;
    int dimension;
    int *vertexes;
};


Tour *tourlib_tour_init(char *name, int dimension, int *vertexes) {
    Tour *tour = malloc(sizeof *tour);

    tour->name = name;
    tour->dimension = dimension;
    tour->vertexes = vertexes;

    return tour;
}

char *tourlib_tour_name(Tour *tour) {
    return tour->name;
}

int tourlib_tour_dimension(Tour *tour) {
    return tour->dimension;
}

int *tourlib_tour_vertexes(Tour *tour) {
    return tour->vertexes;
}

void tourlib_tour_free(Tour *tour) {
    free(tour->name);
    free(tour->vertexes);

    free(tour);
}

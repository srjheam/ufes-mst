#include <stdlib.h>

#include "containerslib/linked_list.h"
#include "tourlib/tour.h"

struct Tour
{
    char *name;
    int dimension;
    int *vertexes;
};


// Tour *tourlib_tour_init(char *name, int dimension, int *vertexes);

Tour *tourlib_tour_init(char *name, int dimension) {
    Tour *tour = malloc(sizeof *tour);

    tour->name = name;
    tour->dimension = dimension;
    tour->vertexes = malloc(sizeof(int) * tour->dimension);

    return tour;
}

void __tourlib_tour_dfs(Tour *tour, int *visited, LinkedList **adjacency_list, int vertex, int *find_count) {
    //setting the bit [vertex - 1] on the visited array as 1
    visited[(vertex - 1)/32] |= 1 << ((vertex - 1)%32);

    tour->vertexes[(*find_count)++] = vertex;
    
    ListIterator *it = list_iterator_init(adjacency_list[vertex - 1]);
    while (!list_iterator_is_over(it)) {
        int next = list_iterator_next(it);

        //only returns 1 if the next-1 bit is not visited (equal to 0)
        if (!(visited[(next - 1)/32] & (1 << ((next - 1)%32)))) {
            __tourlib_tour_dfs(tour, visited, adjacency_list, next, find_count);
        }
    }

    list_iterator_free(it);
}

void tourlib_tour_path(Tour *tour, LinkedList **adjacency_list) {
    // use bit array instead of int array
    int *visited = calloc((tour->dimension/32) + 1, sizeof(int));

    int *find_count = malloc(sizeof(int));
    *find_count = 0;
    __tourlib_tour_dfs(tour, visited, adjacency_list, 1, find_count);

    free(find_count);
    free(visited);
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

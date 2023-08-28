#include <stdio.h>
#include <stdlib.h>

#include "tsplib/tsp_serdes.h"
#include "tourlib/traveler.h"

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <tsp_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *f = fopen(argv[1], "r");
    Tsp *tsp = tsplib_tsp_deserialize(f);

    tsplib_tsp_free(tsp);

    return EXIT_SUCCESS;
}

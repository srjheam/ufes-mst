#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tourlib/mst_serdes.h"
#include "tourlib/tour_serdes.h"
#include "tourlib/traveler.h"
#include "tsplib/tsp_serdes.h"

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <tsp_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    #ifdef BENCHMARK
    #include <time.h>
    clock_t setup_time = clock();
    #endif

    FILE *f = fopen(argv[1], "r");
    Tsp *tsp = tsplib_tsp_deserialize(f);
    fclose(f);

    #ifdef BENCHMARK
    printf("%lf\n", (double)(clock() - setup_time) / CLOCKS_PER_SEC);
    #endif

    Mst *mst;
    Tour *tour;

    #ifdef BENCHMARK
    #include <time.h>
    clock_t start_time = clock();
    #endif

    tourlib_generate_travel(tsp, &mst, &tour);
  
    #ifdef BENCHMARK
    printf("%lf\n", (double)(clock() - start_time) / CLOCKS_PER_SEC);
    #endif

    #ifdef BENCHMARK
    #include <time.h>
    clock_t mstfile_time = clock();
    #endif

    char *mst_file = malloc(strlen(tsplib_tsp_name(tsp)) + 5);
    strcpy(mst_file, tsplib_tsp_name(tsp));
    strcat(mst_file, ".mst");

    FILE *f_mst = fopen(mst_file, "w");
    tourlib_mst_serialize(mst, f_mst);
    fclose(f_mst);

    free(mst_file);

    #ifdef BENCHMARK
    printf("%lf\n", (double)(clock() - mstfile_time) / CLOCKS_PER_SEC);
    #endif

    #ifdef BENCHMARK
    #include <time.h>
    clock_t tourfile_time = clock();
    #endif

    char *tour_file = malloc(strlen(tsplib_tsp_name(tsp)) + 6);
    strcpy(tour_file, tsplib_tsp_name(tsp));
    strcat(tour_file, ".tour");

    FILE *f_tour = fopen(tour_file, "w");
    tourlib_tour_serialize(tour, f_tour);
    fclose(f_tour);

    free(tour_file);

    #ifdef BENCHMARK
    printf("%lf\n", (double)(clock() - tourfile_time) / CLOCKS_PER_SEC);
    #endif

    tsplib_tsp_free(tsp);
    tourlib_mst_free(mst);
    tourlib_tour_free(tour);

    return EXIT_SUCCESS;
}

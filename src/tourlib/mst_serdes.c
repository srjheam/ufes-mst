#include "tourlib/mst_serdes.h"
#include "containerslib/linked_list.h"

void tourlib_mst_serialize(Mst *mst, FILE *f) {
    fprintf(f, "NAME: %s\n", tourlib_mst_name(mst));
    fprintf(f, "TYPE: MST\n");
    fprintf(f, "DIMENSION: %d\n", tourlib_mst_dimension(mst));
    fprintf(f, "MST_SECTION\n");

    LinkedList **edges = tourlib_mst_edges(mst);
    for (int i = 1; i < tourlib_mst_dimension(mst) + 1; i++) {
        // fprintf(f, "%d %d\n", edges[i].id_u, edges[i].id_v);
        ListIterator *it = list_iterator_init(edges[i]);
        while(!list_iterator_is_over(it)) {
            int value = list_iterator_next(it);
            if(i < value)
                fprintf(f, "%d %d\n", i, value);
        }

        list_iterator_free(it);
        
    }
    fprintf(f, "EOF\n");
}

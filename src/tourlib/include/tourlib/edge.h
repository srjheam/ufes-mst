#ifndef _TOURLIB_EDGE_H_
#define _TOURLIB_EDGE_H_

typedef struct {
    int id_u;
    int id_v;
    #ifndef EX_HEAP
    float distance;
    #endif
} Edge;

#endif

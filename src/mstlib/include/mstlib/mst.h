#ifndef _MSTLIB_MST_
#define _MSTLIB_MST_

typedef struct Mst Mst;

Mst *mstlib_mst_init(int n);

void mstlib_mst_free(Mst *mst);

#endif

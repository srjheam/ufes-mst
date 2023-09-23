#ifndef _TOURLIB_MST_SERDES_
#define _TOURLIB_MST_SERDES_

#include <stdio.h>

#include "tourlib/mst.h"

/**
 * @brief Print the MST to the given file.
 *
 * @param mst The MST to serialize.
 * @param f The file to print to.
 */
void tourlib_mst_serialize(Mst *mst, FILE *f);

#endif

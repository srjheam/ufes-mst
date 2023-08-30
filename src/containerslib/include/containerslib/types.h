#ifndef _CONTAINERSLIB_TYPES_H_
#define _CONTAINERSLIB_TYPES_H_

#include <stdbool.h>

typedef void (*free_fn)(void *);
typedef void *(*cpy_fn)(void *);
typedef int (*cmp_fn)(const void *, const void *);

typedef unsigned char byte;

#endif

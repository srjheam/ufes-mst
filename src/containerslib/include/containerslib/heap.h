#ifndef _CONTAINERSLIB_HEAP_H_
#define _CONTAINERSLIB_HEAP_H_

#include <stdlib.h>
#include <stdbool.h>

#include "containerslib/types.h"

typedef struct Heap Heap;

enum HeapType {
    MIN_HEAP,
    MAX_HEAP
};

Heap *heap_init(enum HeapType type, size_t initialCapacity, size_t smemb, free_fn freer);

void heap_push(Heap *self, void *data, float priority);

float heap_pop(Heap *self, void *out);

float heap_peek(Heap *self, void *out);

size_t heap_len(Heap *self);

void heap_free(Heap *self);

#endif

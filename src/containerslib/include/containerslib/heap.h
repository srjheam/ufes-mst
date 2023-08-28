#ifndef _CONTAINERSLIB_HEAP_H_
#define _CONTAINERSLIB_HEAP_H_

#include <stdlib.h>
#include <stdbool.h>

#include "containerslib/types.h"
#include "containerslib/kvp.h"

typedef struct Heap Heap;

enum HeapType {
    MIN_HEAP,
    MAX_HEAP
};

Heap *heap_init(enum HeapType type, size_t initialCapacity, size_t smemb, free_fn freer);

void heap_push(Heap *self, void *data, double priority);

Kvp *heap_pop(Heap *self);

Kvp *heap_peek(Heap *self);

size_t heap_len(Heap *self);

void heap_free(Heap *self);

#endif

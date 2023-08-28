#include <string.h>

#include "containerslib/exceptions.h"
#include "containerslib/heap.h"

struct Heap {
    byte *data;
    double *priorities;
    size_t capacity;
    size_t len;
    size_t smemb;
    free_fn freer;
    enum HeapType type;
};

void __heap_grow(Heap *heap) {
    if (heap->len == heap->capacity) {
        heap->capacity <<= 1;
        heap->data = realloc(heap->data, heap->smemb * heap->capacity);
        heap->priorities =
            realloc(heap->priorities, sizeof(double) * heap->capacity);
    }
}

double __heap_cmp(Heap *heap, double a, double b) { return heap->type == MAX_HEAP ? a - b : b - a; }

void __heap_swap(Heap *map, size_t i, size_t j) {
    if (i >= map->len || j >= map->len)
        exception_throw_index("heap_swap - Index out of bounds");

    byte *tmp = malloc(map->smemb);
    memcpy(tmp, map->data + i * map->smemb, map->smemb);
    memcpy(map->data + i * map->smemb, map->data + j * map->smemb, map->smemb);
    memcpy(map->data + j * map->smemb, tmp, map->smemb);
    free(tmp);

    double tmp2 = map->priorities[i];
    map->priorities[i] = map->priorities[j];
    map->priorities[j] = tmp2;
}

/**
 * @brief Returns the diff priority of the child with the highest priority; if
 * the result is negative, the left child has the highest priority; if the
 * result is positive, the right child has the highest priority; if the result
 * is zero, the children have less priority than the parent.
 *
 * @param heap The heap.
 * @param i The index of the parent.
 * @return double
 */
double __heap_heapify_high(Heap *heap, size_t i) {
    size_t lindx = 2 * i + 1;
    size_t rindx = 2 * i + 2;

    // I love Linux file permissions.
    int bits = 0b01 * (lindx >= heap->len) + 0b10 * (rindx >= heap->len);
    switch (bits) {
    case 0b01:;
        double rdiff =
            __heap_cmp(heap, heap->priorities[rindx], heap->priorities[i]);
        return rdiff > 0 ? rdiff : 0;

    case 0b10:;
        double ldiff =
            __heap_cmp(heap, heap->priorities[lindx], heap->priorities[i]);
        return ldiff > 0 ? ldiff * -1 : 0;

    case 0b11:
        return 0;
    }

    double pp = heap->priorities[i];
    double pl = heap->priorities[lindx];
    double pr = heap->priorities[rindx];

    double ldiff = __heap_cmp(heap, pl, pp);
    double rdiff = __heap_cmp(heap, pr, pp);

    int bits2 = 0b01 * (ldiff <= 0) + 0b10 * (rdiff <= 0);
    switch (bits2) {
    case 0b01:
        return rdiff;

    case 0b10:
        return ldiff * -1;

    case 0b11:
        return 0;
    }

    return ldiff < rdiff ? rdiff : ldiff * -1;
}

void __heap_heapify_up(Heap *heap, size_t i) {
    if (heap->len == 1 || i == 0)
        return;

    size_t icurr = ((i + 1) >> 1) - 1;
    while (__heap_heapify_high(heap, icurr)) {
        size_t ichild =
            2 * icurr + (__heap_heapify_high(heap, icurr) < 0 ? 1 : 2);

        __heap_swap(heap, icurr, ichild);

        if (icurr == 0)
            break;
        icurr = ((icurr + 1) >> 1) - 1;
    }
}

void __heap_heapify_down(Heap *heap) {
    size_t icurr = 0;
    while (__heap_heapify_high(heap, icurr)) {
        size_t ichild =
            2 * icurr + (__heap_heapify_high(heap, icurr) < 0 ? 1 : 2);

        __heap_swap(heap, icurr, ichild);

        icurr = ichild;
    }
}

void __heap_push(Heap *heap, byte *data, double priority) {
    __heap_grow(heap);

    heap->priorities[heap->len] = priority;
    memcpy(heap->data + heap->len * heap->smemb, data, heap->smemb);
    heap->len++;

    __heap_heapify_up(heap, heap->len - 1);
}

Kvp *__heap_peek(Heap *heap) {
    if (heap->len == 0)
        return NULL;

    byte *data = malloc(heap->smemb);
    memcpy(data, heap->data, heap->smemb);

    Kvp *kvp = kvp_init(heap->priorities, data);

    return kvp;
}

Kvp *__heap_pop(Heap *heap) {
    if (heap->len == 0)
        return NULL;

    double *priority = malloc(sizeof(double));
    *priority = heap->priorities[0];

    byte *data = malloc(heap->smemb);
    memcpy(data, heap->data, heap->smemb);

    Kvp *kvp = kvp_init(priority, data);

    if (heap->len == 1) {
        heap->len--;
        return kvp;
    }

    // place the last element in the root
    __heap_swap(heap, 0, heap->len - 1);
    heap->len--;

    __heap_heapify_down(heap);

    return kvp;
}

Heap *heap_init(enum HeapType type, size_t initialCapacity, size_t smemb, free_fn freer) {
    Heap *heap = malloc(sizeof *heap);

    heap->smemb = smemb;
    heap->freer = freer;
    heap->type = type;

    heap->capacity = initialCapacity;
    heap->len = 0;
    heap->data = malloc(heap->smemb * heap->capacity);
    heap->priorities = malloc(sizeof(double) * heap->capacity);

    return heap;
}

void heap_push(Heap *self, void *data, double priority) {
    __heap_push(self, data, priority);
}

Kvp *heap_pop(Heap *self) {
    return __heap_pop(self);
}

Kvp *heap_peek(Heap *self) {
    return __heap_peek(self);
}

size_t heap_len(Heap *self) {
    return self->len;
}

void heap_free(Heap *self) {
    if (self->freer)
        for (size_t i = 0; i < self->len; i++)
            self->freer(((byte **)self->data)[i * self->smemb]);

    free(self->data);
    free(self->priorities);
    free(self);
}

#include <stdlib.h>

#include "containerslib/exceptions.h"
#include "containerslib/kvp.h"

Kvp *kvp_init(void *key, void *value) {
    Kvp *kvp = malloc(sizeof(Kvp));
    if (kvp == NULL)
        exception_throw_oom("kvp_init - Out of memory");

    kvp->key = key;
    kvp->value = value;

    return kvp;
}

void *kvp_key(Kvp *kvp) { return kvp->key; }

void *kvp_value(Kvp *kvp) { return kvp->value; }

void kvp_set_key(Kvp *kvp, void *key) { kvp->key = key; }

void kvp_set_value(Kvp *kvp, void *value) { kvp->value = value; }

void kvp_free(Kvp *kvp) { free(kvp); }

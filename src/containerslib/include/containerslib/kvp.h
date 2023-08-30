#ifndef _CONTAINERSLIB_KVP_H_
#define _CONTAINERSLIB_KVP_H_

typedef struct Kvp Kvp;

struct Kvp {
    void *key;
    void *value;
};

Kvp *kvp_init(void *key, void *value);

void *kvp_key(Kvp *kvp);

void *kvp_value(Kvp *kvp);

void kvp_set_key(Kvp *kvp, void *key);

void kvp_set_value(Kvp *kvp, void *value);

void kvp_free(Kvp *kvp);

#endif

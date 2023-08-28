#include <stdio.h>
#include <stdlib.h>

#include "containerslib/exceptions.h"

void exception_throw(char *name, char *msg, int code) {
    fprintf(stderr, "%s\n\n%s\n", name, msg);
    exit(code);
}

void exception_throw_argument(char *msg) {
    exception_throw("ArgumentException", msg, EXIT_FAILURE);
}

void exception_throw_index(char *msg) {
    exception_throw("IndexException", msg, EXIT_FAILURE);
}

void exception_throw_oom(char *msg) { exception_throw("OOM", msg, EXIT_OOM); }

void exception_throw_failure(char *msg) {
    exception_throw("FAILURE", msg, EXIT_FAILURE);
}

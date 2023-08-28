#ifndef _CONTAINERSLIB_EXCEPTIONS_H_
#define _CONTAINERSLIB_EXCEPTIONS_H_

#define EXIT_OOM 137

void exception_throw(char *name, char *msg, int code);

void exception_throw_argument(char *msg);

void exception_throw_index(char *msg);

void exception_throw_oom(char *msg);

void exception_throw_failure(char *msg);

#endif

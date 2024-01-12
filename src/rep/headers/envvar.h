// #define _GNU_SOURCE
#ifndef ENVVAR_H_INCLUDED
#define ENVVAR_H_INCLUDED

#include "globals.h"
char *readVar(char *var);
UI32 readEnv(OPTS *envv);
#endif // ENVVAR_H_INCLUDED

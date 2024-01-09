// #define _GNU_SOURCE
#ifndef ENVVAR_H_INCLUDED
#define ENVVAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "globals.h"
UI32 read_stdin(UI32 STATUS[32]);
char *readenv();

#endif // ENVVAR_H_INCLUDED

#pragma once
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "structstypes.h"

#define DEBUG   1
#define Z0      '\0'

extern OPTS opts;
extern ARGS args;
extern PIPE stdn;
extern REP rep;
extern NUM num;

extern UI32 STATUS[32];
extern UI32 pOpts[8];
extern UI32 pArgs[2];


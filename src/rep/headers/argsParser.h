#pragma once
#include "globals.h"
#include "escape.h"

UI32 readPipe(ARGS *args);
UI32 isOption(UI32 optn, char *arg);
// UI32 parseArgs(UI32 argc, char **argv,ARGS *args,UI32 rcode);
UI32 parseOpts(UI32 argc, char **pArgv, OPTS *opts);


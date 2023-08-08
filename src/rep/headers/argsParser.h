#pragma once
#include "globals.h"
#include "escape.h"

UI32 *readPipe(char *rep,UI32 *r);
UI32 isOption(char *opt[3], char *arg);
UI32 parseArgs(UI32 argc, char **argv,ARGS *args,UI32 *nwbprsce[8]);




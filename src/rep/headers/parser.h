#pragma once
#define _GNU_SOURCE
#include "globals.h"
#include "pipe.h"

UI32 check_flags(UI32 argc, char **argv,UI32 STATUS[32]);
UI32 parse(UI32 argc, char **argv);


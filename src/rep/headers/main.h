#pragma once
#define _GNU_SOURCE
#include "globals.h"

// Function declarations
UI32 repeat();
UI32 escape_opts();
UI32 show_info();


OPTS opts;
ARGS args;
PIPE stdn;
REP rep;
NUM num;
ERR err;
UI32 STATUS[32]={[0 ... 31]=0};
UI32 debug=DEBUG;





#pragma once
#define _GNU_SOURCE
#include "globals.h"

// Function declarations
UI32 repeat();
UI32 escape_opts();
UI32 show_info();
void debug_print(const char *tpl,...);
void runInfo(int select,int argc,char **argv);

OPTS opts;
ARGS args;
PIPE stdn;
REP rep;
NUM num;
ERR err;
UI32 STATUS[32]={[0 ... 31]=0};
UI32 MANDATORY=0;
UI32 debug=DEBUG;





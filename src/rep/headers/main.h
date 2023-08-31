#pragma once
#define _GNU_SOURCE
#include "globals.h"


// Function declarations
static void repeat();
void print(char *str);
void debug(char *fmt,char *str);



OPTS opts;
ARGS args;
PIPE stdn;
UI32 STATUS[32]={[0 ... 31]=0};
UI32 pOpts[10]={[0 ... 9]=0};
#include "parser.h"
#include "escape.h"
// #include "help.h"

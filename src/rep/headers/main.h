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
char **pOpts[10]={ &opts.b,	&opts.p,	&opts.s,	&opts.j,	&opts.f,	&opts.c,	&opts.r,	&opts.n,	&opts.h,	&opts.v};
#include "parser.h"
#include "escape.h"

#pragma once
#define _GNU_SOURCE
#include "globals.h"
// Function declarations
void repeat();
void print(char *str);
void debug(char *fmt,char *str);
void info(char exeName);
void esc();

OPTS opts;
ARGS args;
PIPE stdn;
UI32 STATUS[32]={[0 ... 31]=0};
UI32 pOpts[10]={[0 ... 9]=0};


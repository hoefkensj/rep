#pragma once
#include "globals.h"
#include "argsParser.h"
// #include "help.h"

extern char *strUsage;
extern char *strAbout;
extern char *strHelp;
int main(int argc, char *argv[]);
void repeat(ARGS args);
void print(char *str);

ARGS args;
UI32 *nwbprsce[8] = {[0 ... 7] = 0};



#pragma once
#include "globals.h"
#include "argsParser.h"
// #include "help.h"

extern char *strUsage;
extern char *strAbout;
extern char *strHelp;
int main(int argc, char *argv[]);
void repeat();
void print(char *str);

OPTS opts;
ARGS args;
UI32 optStat[5]={[0 ... 4]=0};
UI32 STATUS[32]={[0 ... 31]=0};




#pragma once
#include "globals.h"
#include "help.h"
#include "escape.h"

extern char *strUsage;
extern char *strAbout;
extern char *strHelp;
int main(int argc, char *argv[]);
UI32 parseArgs(UI32 argc, char **argv,ARGS *args);
void repeat(ARGS args);
void print(char *str);
void returnCode(UI32 return_code,char *exeName);

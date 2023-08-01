#pragma once
#include "globals.h"
#include "help.h"
#include "escape.h"

extern char *strUsage;
extern char *strAbout;
extern char *strHelp;
int main(int argc, char *argv[]);
UI32 readPipe(ARGS *args);
UI32 Option(char *sopt,char *lopt ,char *arg );

UI32 parseArgs(UI32 argc, char **argv,ARGS *args);


void repeat(ARGS args);
void print(char *str);
UI32 returnCode(UI32 ret_code,char *exeName);


#pragma once
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include "structstypes.h"
#include "tools.h"

#define DEBUG   0
#define Z0      '\0'

extern OPTS opts;
extern OPTS envv;
extern ARGS args;
extern PIPE stdn;
extern REP rep;

extern UI32 STATUS;
extern UI32 MANDATORY;
extern UI32 debug;
// extern UI32 Flag(UI32 action,UI32 flag);

enum flagops{zero,set,get};
enum STATUS_SETS{O=0,A=11,I=14,E=16,F=25};
enum STATUS_VARS{Repeat,Number,Begin,Prefix,Suffix,Join,Final,Columns};
enum STATIS_FLAGS{NoEscape,Debug,Help,Version};


// enum STATUS_OPTS{oBegin=0,oPrefix,oSuffix,oJoin,oFinal,oColumns,oRepeat,oNumber};
// enum STATUS_ENVV{eBegin=16,ePrefix,eSuffix,eJoin,eFinal,eColumns,eRepeat,eNumber};
// enum STATUS_ARGS{aRepeat=11,aNumber=12};
// enum STATUS_STIN{iRepeat=14};


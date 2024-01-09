#pragma once
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include "structstypes.h"

#define DEBUG   0
#define Z0      '\0'

extern OPTS opts;
extern ARGS args;
extern PIPE stdn;
extern REP rep;

extern UI32 STATUS;
extern UI32 MANDATORY;
extern UI32 debug;
extern UI32 Flag(UI32 action,UI32 flag);

enum flagops{zero,set,get};
enum STATUS{
	oBegin=0,oPrefix,oSuffix,oJoin,oFinal,oCollums,oRepeat,oNumber,
	aRepeat=11,aNumber=12,
	iRepeat=14,
	eBegin=16,ePrefix,eSuffix,eJoin,eFinal,eCollums,eRepeat,eNumber};


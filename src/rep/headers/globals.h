#ifndef GLOBALS_H_INCLUDED
#define GLOBALS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include "structstypes.h"
#include "tools.h"


#define DEBUG   0
#define Z0      '\0'

extern PARTS *opts;
extern PARTS *envv;
extern PARTS *args;
extern PARTS *stdn;
extern REP rep;

extern char *ENVVAR[8];

extern UI32 STATUS;
extern UI32 MANDATORY;
extern UI32 debug;

// extern UI32 Flag(UI32 action,UI32 flag);

enum flagops{zero,set,get};
enum STATUS_SETS{O=0,A=11,I=14,E=16,F=25};
enum STATUS_VARS{Repeat,Number,Begin,Prefix,Suffix,Join,Final,Columns};
enum STATIS_FLAGS{NoEscape,Debug,Help,Version};

#endif // GLOBALS_H_INCLUDED

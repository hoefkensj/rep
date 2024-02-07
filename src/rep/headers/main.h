#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include "globals.h"


PARTS *opts;
PARTS *envv;
PARTS *args;
PARTS *stdn;
REP rep;
NUM num;
ERR err;
UI32 MANDATORY=0;
UI32 debug=DEBUG;


UI32 repeat(UI32 n,char *b,char *p,char *s,char *f,char *j, char *r);




#endif // MAIN_H_INCLUDED

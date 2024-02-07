#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "globals.h"


UI32 check_flags(UI32 argc, char **argv);
UI32 parse(UI32 argc,char **argv,PARTS *opts,PARTS *args );


#endif // PARSER_H_INCLUDED

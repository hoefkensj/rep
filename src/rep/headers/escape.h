#ifndef ESCAPE_H_INCLUDED
#define ESCAPE_H_INCLUDED

#define  Z0 '\0'
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "globals.h"
#include "pipe.h"
#include "parser.h"


unsigned int repl_unescape(char *str) ;
int esc_main(int argc,char **argv);


#endif // ESCAPE_H_INCLUDED

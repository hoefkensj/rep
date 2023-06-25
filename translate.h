
/*
** Public Domain by Jerry Coffin.
**
** Interprets a string in a manner similar to the way the compiler
** does string literals in a program.  All escape sequences are
** longer than their translated equivalent, so the string is
** translated in place and either remains the same length or
** becomes shorter.
*/

#pragma once

#include <string.h>
#include <stdio.h>
// #include "snip_str.h"


char *translate(char *string);

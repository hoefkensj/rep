#pragma once
#define _GNU_SOURCE
#include "globals.h"

UI32 debug_proc(UI32 select);
void debug_print(const char *tpl,...);
void main_debug(int argc, char *argv[]);

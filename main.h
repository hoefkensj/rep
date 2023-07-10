#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "help.h"
#include "escape.h"

typedef char B;
typedef unsigned int UI32;


typedef struct ARR{
	UI32 ln;
	char arr[];
	}ARR;


typedef struct ARGS{
	UI32 n;
	B *rep;
	B *pfx;
	B *sfx;
	B *cat;

	}ARGS;


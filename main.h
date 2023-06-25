#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "help.h"
#include "translate.h"

typedef struct ARGS{
	unsigned long int n ;
	char *string;
	char *pfx;
	char *sfx;
	char *cat;
	}ARGS;

#define DASH

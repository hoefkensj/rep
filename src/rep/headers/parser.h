#pragma once
#define _GNU_SOURCE

#include "globals.h"

// Function declarations



UI32 parse(UI32 argc, char **argv);



static char *FLAG[2][3] = {
	{"-v", "--ver", "--version" },
	{"-h", "-?", "--help",   }};

static char *opt[10][3]  = {
	{"-b", "--bgn", "--begin"   },
	{"-p", "--pfx", "--prefix"  },
	{"-s", "--sfx", "--suffix"  },
	{"-j", "--jnt", "--join"    },
	{"-f", "--fin", "--final"   },
	{"-c", "--col", "--colums"  },
	{"-n", "--num", "--number"  },
	{"-r", "--rep", "--repeat"  },
	{"-v", "--ver", "--version" },
	{"-h", "-?", "--help",   }};

#pragma once
#define _GNU_SOURCE

#define AUTHOR  "Hoefkens Jeroen      "
#define EMAIL   "Hoefkens.J@gmail.com "
#define GITHUB  "github.com/hoefkensj "
#define REPO    "rep                  "
#define VERSION "0.0.3                "
#define DATE    "2023.07.11           "
#define LICENSE "MIT                  "
#define DEBUG   1
#define Z0      '\0'

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


typedef unsigned int UI32;

typedef struct OPTS{
	char *b;
	char *p;
	char *s;
	char *j;
	char *f;
	char *c;
	char *r;
	char *n;
	char *h;
	char *v;
}OPTS;

typedef struct ARGS{
	UI32 n;
	char *r;
}ARGS;

typedef struct PIPE{
	UI32 n;
	char *r
	;
}PIPE;



void print_binary(unsigned int number);
void debug(char *fmt,char *str);
UI32 parse(UI32 argc, char **argv);


extern OPTS opts;
extern ARGS args;
extern PIPE stdn;
extern UI32 STATUS[32];
extern char **pOpts[10];

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





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

#include "parser.h"
#include "escape.h"
#include "help.h"
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
	char *r;
}PIPE;



void print_binary(unsigned int number);
void debug(char *fmt,char *str);
UI32 parse(UI32 argc, char **argv);


extern OPTS opts;
extern ARGS args;
extern PIPE stdn;

extern UI32 STATUS[32];
extern UI32 pOpts[10];


extern char *strHelp;
extern char *strUse;



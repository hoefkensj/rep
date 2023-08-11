#pragma once
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define AUTHOR  "Hoefkens Jeroen      "
#define EMAIL   "Hoefkens.J@gmail.com "
#define GITHUB  "github.com/hoefkensj "
#define REPO    "rep                  "
#define VERSION "0.0.3                "
#define DATE    "2023.07.11           "
#define LICENSE "MIT                  "
#define DEBUG   1

#define Z0 '\0'

typedef unsigned int UI32;

typedef struct OPTS{
	char *b;
	char *p;
	char *s;
	char *j;
	char *f;
	char *w;
}OPTS;
typedef struct ARGS{
	UI32 n;
	char *r;
}ARGS;

extern char *pArgv[];
extern UI32 optStat[5];
extern UI32 STATUS[32];
void debug(char *fmt,char *str);

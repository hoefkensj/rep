#pragma once
#define AUTHOR  "Hoefkens Jeroen     "
#define EMAIL   "Hoefkens.J@Gmail.com"
#define GITHUB  "github.com/hoefkensj"
#define REPO    "rep                 "
#define VERSION "0.0.1               "
#define DATE    "2023.07.11          "
#define LICENSE "MIT                 "

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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


#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AUTHOR  "Hoefkens Jeroen      "
#define EMAIL   "Hoefkens.J@gmail.com "
#define GITHUB  "github.com/hoefkensj "
#define REPO    "rep                  "
#define VERSION "0.0.3                "
#define DATE    "2023.07.11           "
#define LICENSE "MIT                  "


#define Z0 '\0'

typedef unsigned int UI32;
typedef struct ARGS{
	UI32 n;
	char *rep;
	char *pfx;
	char *sfx;
	char *cat;
}ARGS;


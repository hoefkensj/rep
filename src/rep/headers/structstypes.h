#pragma once
#define _GNU_SOURCE
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
}OPTS;

typedef struct ARGS{
	char *r;
	char *n;
}ARGS;

typedef struct PIPE{
	char *r;
}PIPE;

typedef struct REP{
	UI32 i;
	UI32 a;
	UI32 o;
}REP;

typedef struct NUM{
	UI32 a;
	UI32 o;
	UI32 c;
}NUM;

typedef struct ERR{
	UI32 parse;
	UI32 escape;
	UI32 repeat;
}ERR;

#pragma once
#define _GNU_SOURCE
typedef unsigned int UI32;

typedef struct OPTS{
	char *r;
	char *n;
	char *b;
	char *p;
	char *s;
	char *j;
	char *f;
	char *c;
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
	UI32 e;
}REP;

typedef struct NUM{
	UI32 a;
	UI32 o;
	UI32 e;
	UI32 c;
}NUM;

typedef struct ERR{
	UI32 flags;
	UI32 pipe;
	UI32 envv;
	UI32 parse;
	UI32 escape;
	UI32 repeat;
}ERR;


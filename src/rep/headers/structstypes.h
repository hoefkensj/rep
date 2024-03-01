#ifndef STRUCTSTYPES_H_INCLUDED
#define STRUCTSTYPES_H_INCLUDED

typedef unsigned int UI32;

typedef struct PARTS {
	char *r;
	char *n;
	char *b;
	char *p;
	char *s;
	char *j;
	char *f;
	char *c;
} PARTS;

typedef struct NUM{
	UI32 a;
	UI32 o;
	UI32 e;
	UI32 c;
}NUM;

typedef struct USRIN {
	PARTS *popts;
	PARTS *pargs;
	PARTS *penvv;
	PARTS *pstdn;
	NUM   *pnum;
} USRIN;

typedef struct REP{
	UI32 i;
	UI32 a;
	UI32 o;
	UI32 e;
}REP;



typedef struct ERR{
	UI32 flags;
	UI32 pipe;
	UI32 envv;
	UI32 parse;
	UI32 escape;
	UI32 repeat;
}ERR;

#endif // STRUCTSTYPES_H_INCLUDED

#define _GNU_SOURCE
#include "headers/envvar.h"
char *readVar(char *var){
	unsigned int sA   = 8 ;
	char        *val =	malloc( sA );
	if ( val == NULL ) return NULL;

	if(!getenv(var)){
		return NULL;
	}else{
		while (snprintf(val, sA, "%s", getenv(var)) >= sA){
			char *pVal = realloc( val, sA+=sA );
			if ( pVal == NULL ) return NULL;
			val=pVal;
		}//while
	}//else

	char *str = ((char *)malloc( strlen(val) ));
	strcpy(str, val);
	return str;
}//readEnv

UI32 readEnv(OPTS *envv){
	char *vars[8]={"REP_REPEAT","REP_NUMBER","REP_BEGIN","REP_PREFIX","REP_SUFFIX","REP_FINAL","REP_JOIN","REP_COLUMNS"};
	char **aenv[8]={&(envv->r),&(envv->n),&(envv->b),&(envv->p),&(envv->s),&(envv->f),&(envv->j), &(envv->c)};
	char *val;
	for(int i=0;i<8;i++){
		val=readVar(vars[i]);
		if (val != NULL){
			*aenv[i] = val;
			printf("%s: %s\n", vars[i],*aenv[i]);
			Flag(set,E+i);
		}
	}
return 0;
}

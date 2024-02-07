#include "headers/envvar.h"

static char *readVar(char *var){
	unsigned int sA   = 8 ;
	char *val =	malloc( sA );
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

UI32 readEnv(PARTS *envv){
	char **aenv[8]={&(envv->r),&(envv->n),&(envv->b),&(envv->p),&(envv->s),&(envv->f),&(envv->j), &(envv->c)};
	char *val;
	char *ENVVAR[8]={
	"REP_REPEAT",
	"REP_NUMBER",
	"REP_BEGIN",
	"REP_PREFIX",
	"REP_SUFFIX",
	"REP_FINAL",
	"REP_JOIN",
	"REP_COLUMNS"
};
	for(int i=0;i<8;i++){
		val=readVar(ENVVAR[i]);
		if (val != NULL){
			*aenv[i] = val;
			Flag(set,E+i);
		}//if
	}//for
return 0;
}

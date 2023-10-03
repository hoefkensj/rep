#define _GNU_SOURCE
#include "headers/pipe.h"
/*
 * --98765432109876543210
 * hv-----r-nr---nrcfjspb
 */

char *readPipe(){
	unsigned int sR   = 0 ,
               sA   = 8 ;
	char         cI  = '\0';
	char        *pipe =	malloc( sA );

	// sPipe = getline(&pipe, &len, stdin);
	while ( (cI = getchar()) != EOF ){
		if ( !( sR%8 ) ){
			char *pPipe = realloc( pipe, sA+=8 );
			if ( pPipe == NULL ) return NULL;
			pipe = pPipe;
		}
		pipe[sR++] = cI;
	}//while
	char *str = ((char *)malloc( strlen(pipe) ));
	strcpy(str, pipe);
	return str;
}//readPipe

UI32 read_stdin(UI32 STATUS[32]){
	UI32 ret = 2;
	if (!isatty(fileno(stdin))){
		stdn.r=readPipe();
		if (stdn.r != NULL)	{
			STATUS[14] = 1;
			ret=0;
		}
	} else {
		stdn.r="";
		ret = 1;
	}
	return ret;
}

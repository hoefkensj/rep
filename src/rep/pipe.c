#define _GNU_SOURCE
#include "headers/pipe.h"
//--98765432109876543210
//hv-----r-nr---nrcfjspb
char *readPipe(UI32 STATUS[32]){
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
	STATUS[14]=1;
	return str;
}//readPipe
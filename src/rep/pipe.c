#include "headers/pipe.h"

static char *readPipe(){
	unsigned int sR   = 0 ,
               sA   = 8 ;
	char         cI  = '\0';
	char        *pipe =	malloc( sA );
	char        *str;
	char *pPipe;

	// sPipe = getline(&pipe, &len, stdin);
	while ( (cI = getchar()) != EOF ){
		//if char counter read == allocated counter(-1 for adding \0) -> rallocate double the size
		if (sR==(sA-1)){
			sA=2*sA
;			pPipe = realloc(pipe,sA);
			if ( pPipe == NULL ){
				str=NULL;
				goto END;
			}
			pipe = pPipe;
		}//if
		pipe[sR++] = cI;
	}//while
	pipe[sR]='\0';
	str = (char*)malloc( strlen(pipe)+1 );
	strcpy(str, pipe);
	free(pipe);
END:
	return str;
}//readPipe

UI32 read_stdin(PARTS *stdn){
	UI32 ret = 0;
	// if (!isatty(fileno(stdin))){ //no workey
	if (!isatty(STDIN_FILENO)){
		stdn->r = readPipe();
		ret = ((stdn->r==NULL)?2:1);
	} else {
		stdn->r=NULL;
		ret = 0;
	}
	return ret;
}

#include "headers/main.h"

int main(int argc, char *argv[]) {
	UI32 return_code;
	ARGS args;
	return_code=parseArgs( argc, argv,&args );

	repeat(args);


	returnCode(return_code,argv[0]);
	return return_code;
}//main

UI32 parseArgs(UI32 argc, char **argv,ARGS *args) {
	UI32 return_code;
	// init arguments
	return_code = 2;
	args->rep = NULL;
	args->pfx = "";
	args->sfx = "";
	args->cat = "";
	args->n   = 0;


	for (UI32 i=1 ; i < argc; i++) {
		if  ( !( strcmp(argv[i], "-h" ) && strcmp(argv[i], "--help" ))){
			return_code=3 ;
			break;
		}else if ( !( strcmp( argv[i], "-v") && strcmp( argv[i], "--version" ))) {
			return_code=4 ;
			break;
		}else if ( !( strcmp( argv[i], "-p") && strcmp( argv[i], "--pfx" ))) {
			args->pfx = escape( argv[++i], args->pfx );
		}else if ( !( strcmp( argv[i], "-s") && strcmp( argv[i], "--sfx" ))) {
			args->sfx = escape( argv[++i], args->sfx );
		}else if ( !( strcmp( argv[i], "-c") && strcmp( argv[i], "--cat" ))) {
			args->cat = escape( argv[++i], args->cat );
		}else {
			if ( args->rep == NULL) {
				args->rep = escape( argv[i], args->rep );
				return_code-=1;
			} else {
				args->n = atol( argv[i] );
				return_code-=1;
			} //fi
		} //fi
	} //for
	returnCode(return_code,argv[0]);
	return 0;
} //parseArgs

void returnCode(UI32 return_code,char *exeName){
	UI32 lnBHelp;
	UI32 lnBUse;
	lnBHelp=strlen(strHelp)+strlen(exeName)+1;
	char bufHelp[lnBHelp];
	lnBUse=strlen(strUsage)+strlen(exeName)+1;
	char bufUse[lnBUse];
	char bufAb[100];
	switch (return_code){
		case 4:
			print(about(bufAb));
			break;
		case 3:
			print(help(bufHelp,exeName));
			break;
		case 2:
		case 1:
			print(use(bufUse,exeName));
			break;
		case 0:
			break;
	}//switch
}
void repeat(ARGS args){
	UI32 n;
	print( args.pfx );
	for ( n= args.n ; n >  0 ; n--) {
		print( args.rep );
		if ( args.n > 1 ){
			print( args.cat );
		}//fi
	} // for
	print( args.sfx );
}//repeat

void print(char *str){	printf("%s",str);}

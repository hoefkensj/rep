#include "headers/main.h"

int main(int argc, char *argv[]) {

	UI32 ret_code = 0;
	UI32 return_code = 0;
	ARGS args;
	args.n = 0;
	args.w = 0;
	args.bgn = "";
	args.pfx = "";
	args.rep = NULL;
	args.sfx = "";
	args.cat = "";
	args.end = "";
	if (!isatty(fileno(stdin))){
		args.rep=readPipe(&args);
	}
	return return_code;
}//main

char *readPipe(ARGS *args){
	UI32 ret_code = 0;
  ssize_t sRead = 0;
	char *pipe =	malloc(0);
	char *pPipe;
	char cIn;
	cIn=' ';

  // sPipe = getline(&pipe, &len, stdin);
	while (cIn!=Z0){
		cIn = getchar();
		if (cIn=='\n') cIn = Z0;
		pPipe=realloc(pipe,sRead);
		pipe[sRead++]=cIn;
	}
	*args->rep=*pPipe;
	// free(pipe);
	return args->rep;
}

UI32 Option(char *sopt,char *lopt ,char *arg ){ return !( strcmp(arg, sopt ) && strcmp(arg, lopt ));}

UI32 parseArgs(UI32 argc, char **argv,ARGS *args) {
	UI32 ret_code = 0b0;
	for (UI32 i=1 ; i < argc; i++) {
		if  ( Option( "-h" , "--help", argv[i] )){
			ret_code += (1<<31) ;
		}else if ( Option( "-v", "--version", argv[i])) {
			ret_code += (1<<30) ;
		}else if ( Option( "-r", "--rep", argv[i])) {
			args->rep = escape( argv[++i]);
			ret_code += (1<<0);
		}else if ( Option( "-n", "--num", argv[i])) {
			args->n = atol( argv[i] );
			ret_code += (1<<1);
		}else if ( Option( "-b", "--bgn", argv[i])) {
			args->bgn = escape( argv[++i]);
			ret_code += (1<<2);
		}else if ( Option( "-p", "--pfx", argv[i])) {
			args->pfx = escape( argv[++i]);
			ret_code += (1<<3);
		}else if ( Option( "-s", "--sfx", argv[i])) {
			args->sfx = escape( argv[++i]);
			ret_code += (1<<4);
		}else if ( Option( "-c", "--cat", argv[i])) {
			args->cat = escape( argv[++i]);
			ret_code += (1<<5);
		}else if ( Option( "-e", "--end", argv[i])) {
			args->end = escape( argv[++i]);
			ret_code += (1<<6);
		}else if ( Option( "-w", "--wid", argv[i])) {
			ret_code += (1<<7);
		}else {
			if ( args->rep == NULL) {
				args->rep = escape( argv[i]);
				ret_code += (1<<0);
			} else {
				args->n = atol( argv[i] );
				ret_code += (1<<1);
			} //fi
		} //fi
	} //for
	return ret_code;
} //parseArgs

UI32 returnCode(UI32 ret_code, char *exeName){
	UI32 lnBHelp;
	UI32 lnBUse;
	lnBHelp=strlen(strHelp)+strlen(exeName)+1;
	char bufHelp[lnBHelp];
	lnBUse=strlen(strUsage)+strlen(exeName)+1;
	char bufUse[lnBUse];
	char bufAb[100];
	switch (ret_code){
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
	return 0;
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


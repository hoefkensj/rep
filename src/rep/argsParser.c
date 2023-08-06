#include "headers/argsParser.h"

char *flags[][3] = {
	{"-h", "--???", "--help",   },
	{"-v", "--ver", "--version" }};

char *opts[][3]  = {
	{"-n", "--num", "--number"  },
	{"-w", "--col", "--colums"  },
	{"-b", "--bgn", "--begin"   },
	{"-p", "--pfx", "--prefix"  },
	{"-r", "--rep", "--repeat"  },
	{"-s", "--sfx", "--suffix"  },
	{"-c", "--cat", "--concat"  },
	{"-e", "--end", "--last"    }};

UI32 readPipe(ARGS *args,UI32 rcode){
  UI32 sRead = 0;
	UI32 sAlloc = 1;
	char *pipe =	malloc(sAlloc);
	char cIn = Z0;
  // sPipe = getline(&pipe, &len, stdin);
	while ((cIn=getchar())!=EOF){
		char *pPipe = realloc(pipe,sAlloc);
		if (pPipe==NULL){
			rcode=(rcode & (1<<31));
			break;
		}//fi
		pipe=pPipe;
		pipe[sRead]=cIn;
		sRead++;
	}//while
	args->rep=pipe;
	rcode += (1<<4);
	rcode += (1<<29);
	return rcode;
}//readPipe

UI32 isOption(char *opt[3] ,char *arg ){
	return !(
		strcmp(arg, opt[0] ) &&
		strcmp(arg, opt[1] ) &&
		strcmp(arg, opt[2] )
	);
} //isOption

UI32 parseArgs(UI32 argc, char **argv, ARGS *args,UI32 rcode) {

	for (UI32 i=1 ; i < argc; i++) {
		if ( isOption( flags[0] , argv[i])){
			rcode += (1<<30);
		}else if  (isOption( flags[1] , argv[i])){
			rcode += (1<<29);
		}else if ( isOption( opts[0], argv[i])) {
			if ( !(rcode & (1<<0)) ) {
				args->num = atol( argv[++i]);
				rcode += (1<<0) ;
			}//fi
		}else if ( isOption( opts[1], argv[i])) {
			if ( !(rcode & (1<<1)) ) {
				args->col = atol( argv[++i]);
				rcode += (1<<1);
			}//fi
		}else if ( isOption( opts[2], argv[i])) {
			args->bgn = escape(argv[++i]);
			rcode += (1<<2);
		}else if ( isOption( opts[3], argv[i])) {
			args->pfx = escape(argv[++i]);
			rcode += (1<<3);
		}else if ( isOption( opts[4], argv[i])) {
			if ( !(rcode & (1<<4)) ) {
				args->rep =  escape( argv[++i]);
				rcode += (1<<4);
			}//fi
		}else if ( isOption( opts[5], argv[i])) {
			args->sfx = escape( argv[++i]);
			rcode += (1<<5);
		}else if ( isOption( opts[6], argv[i])) {
			args->cat = escape( argv[++i]);
			rcode += (1<<6);
		}else if ( isOption( opts[7], argv[i])) {
			args->end = escape( argv[++i]);
			rcode += (1<<7);
		}else {
			if (!(rcode &(1<<4))) {
				args->rep = escape(argv[i]);
				rcode += (1<<4);
			} else if ( !( rcode&(1<<0) )) {
				args->num = atol( argv[i] );
				rcode += (1<<0);
			} //fi
		}//fi
	}//done
	return rcode;
} //parseArgs

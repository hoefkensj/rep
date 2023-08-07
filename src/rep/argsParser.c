#include "headers/argsParser.h"

char *flags[][3] = {
	{"-v", "--ver", "--version" },
	{"-h", "--???", "--help",   }};

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

	//flags
	for (UI32 f=0 ; f < 2 ; f++){
		for (UI32 i=1 ; i < argc; i++) {
			if ( isOption( flags[0] , argv[i])){
				rcode += (1<< (30+f));
				break;
			}//fi
		}//done
	}//done

	if ( ( !(rcode & (1<<30)) )|( !(rcode & (1<<31)) ) ){
		for (UI32 i=1 ; i < argc; i++) {
			if ( !( rcode & (1<<0) ) ) {
				if ( isOption( opts[0], argv[i])) {
					args->num = atol( argv[++i]);
					rcode += (1<<0) ;
				}//fi
			}//fi
			if ( !( rcode & (1<<1)) ) {
				if ( isOption( opts[1], argv[i])) {
					args->col = atol( argv[++i]);
					rcode += (1<<1);
				}//fi
			}//fi
			if ( !( rcode & (1<<2)) ) {
				if ( isOption( opts[2], argv[i])) {
					args->bgn = escape(argv[++i]);
					rcode += (1<<2);
				}//fi
			}//fi
			if ( !( rcode & (1<<3)) ) {
				if ( isOption( opts[3], argv[i])) {
					args->pfx = escape(argv[++i]);
					rcode += (1<<3);
				}//fi
			}//fi
			if ( !( rcode & (1<<4)) ) {
				if ( isOption( opts[4], argv[i])) {
					args->rep = escape(argv[++i]);
					rcode += (1<<4);
				}//fi
			}//fi
			if ( !( rcode & (1<<5)) ) {
				if ( isOption( opts[5], argv[i])) {
					args->sfx = escape(argv[++i]);
					rcode += (1<<5);
				}//fi
			}//fi
			if ( !( rcode & (1<<6)) ) {
				if ( isOption( opts[6], argv[i])) {
					args->cat = escape(argv[++i]);
					rcode += (1<<6);
				}//fi
			}//fi
			if ( !( rcode & (1<<7)) ) {
				if ( isOption( opts[7], argv[i])) {
					args->end = escape(argv[++i]);
					rcode += (1<<7);
				}//fi
			}//fi


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

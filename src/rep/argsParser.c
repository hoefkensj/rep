#include "headers/argsParser.h"
char *flags[][3] = {
	{"-h", "--???", "--help",   },
	{"-v", "--ver", "--version" }};

char *opts[8][3]  = {
	{"-n", "--num", "--number"  },
	{"-w", "--col", "--colums"  },
	{"-b", "--bgn", "--begin"   },
	{"-p", "--pfx", "--prefix"  },
	{"-r", "--rep", "--repeat"  },
	{"-s", "--sfx", "--suffix"  },
	{"-c", "--cat", "--concat"  },
	{"-e", "--end", "--last"    }};



UI32 *readPipe(char *rep,UI32 *r){
  UI32 sRead = 0;
	UI32 sAlloc = 1;
	char *pipe =	malloc(sAlloc);
	char cIn = Z0;
  // sPipe = getline(&pipe, &len, stdin);
	while ((cIn=getchar())!=EOF){
		char *pPipe = realloc(pipe,sAlloc);
		if (pPipe==NULL){
			*r=1;
			break;
		}//fi
		pipe=pPipe;
		pipe[sRead]=cIn;
		sRead++;
	}//while
	*rep=*pipe;
	*r=1;
	return r;
}//readPipe

UI32 isOption(char *opt[3] ,char *arg ){
	return !(
		strcmp(arg, opt[0] ) &&
		strcmp(arg, opt[1] ) &&
		strcmp(arg, opt[2] )
	);
} //isOption

UI32 parseArgs(UI32 argc, char **argv, ARGS *args,UI32 *nwbprsce[8]) {
	UI32 n =0 ;
	//options
	for (UI32 i=1,j=0 ; i < argc; i++) {
		char *opt = argv[i];
		if (opt[j++] == '-') {
			if (opt[j] == '-') {
				j++;
			}else{
				switch (opt[j]){
					case 'n':
						args->n=atol(argv[++i]);
						*nwbprsce[0]=1;
						break;
					case 'w':
						args->w=atol(argv[++i]);
						*nwbprsce[1]=1;
						break;
					case 'b':
						args->b=escape(argv[++i]);
						*nwbprsce[2]=1;
						break;
					case 'p':
						args->p=escape(argv[++i]);
						*nwbprsce[3]=1;
						break;
					case 'r':
						args->r=escape(argv[++i]);
						*nwbprsce[4]=1;	break;
					case 's':

<<<<<<< HEAD
						args->s=escape(argv[++i]);
						*nwbprsce[5]=1;
						break;
					case 'c':
						args->c=escape(argv[++i]);
						*nwbprsce[6]=1;
						break;
					case 'e':
						args->e=escape(argv[++i]);
						*nwbprsce[7]=1;
						break;
					default:
						if (!*nwbprsce[4]){
							args->r=escape(argv[i]);
							*nwbprsce[4]=1;
						}
						break;
				}//switch
			}//fi
		} else if (!*nwbprsce[4]){
			args->r=escape(argv[i]);
			*nwbprsce[4]=1;
		} else if (	sscanf(argv[i], "%i", &n)){
			args->n=atol(argv[i]);
			*nwbprsce[0]=1;
		} else{
			printf("invalid option or parameter : \"%s\"",argv[i]);
			break;
		}
	}//done
	return 1;
} //parseArgs



=======
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
>>>>>>> parent of 7da53c8... argsParser.c, argsParser.c~, escape.c, and escape.c~

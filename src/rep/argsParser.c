#include "headers/argsParser.h"
char *flags[][3] = {
	{"-v", "--ver", "--version" },
	{"-h", "--???", "--help",   }};

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




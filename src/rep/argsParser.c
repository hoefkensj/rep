#include "headers/argsParser.h"

char *flags[][4] = {
	{"-v", "--ver", "--version" },
	{"-h", "--???", "--help",   }};

char *opt[5][3]  = {
	{"-b", "--bgn", "--begin"   },
	{"-p", "--pfx", "--prefix"  },
	{"-s", "--sfx", "--suffix"  },
	{"-j", "--jnt", "--join"    },
	{"-f", "--fin", "--final"   },
};
char *arg[][4] ={
	{"-n", "--num", "--number"  },
	{"-c", "--col", "--colums"  },
	{"-r", "--rep", "--repeat"  }
};

UI32 readPipe(ARGS *args){
  UI32 sR = 0;
	UI32 sA = 1;
	char *pipe =	malloc(sA);
	char cIn = Z0;
  // sPipe = getline(&pipe, &len, stdin);
	while ((cIn=getchar())!=EOF){
		char *pPipe = realloc(pipe,++sA);
		if (pPipe==NULL){
			return 3;
			break;
		}//fi
		pipe=pPipe;
		rpipe[sR]=cIn;
		sR++;
		debug("read: %s\n",&cIn);
		debug("full: %s\n",pipe);
	}//while
	args->r=pipe;
	debug("full: %s\n",args->r);

	// *args.r[sR]=Z0;
	return 1;
}//readPipe

UI32 isOption(UI32 optn ,char *arg ){
	UI32 match=0;
	debug("testing:\t%s\n",arg);
	debug("testing option :\t%s\n",opt[optn][0]);
	debug("testing option :\t%s\n",opt[optn][1]);
	debug("testing option :\t%s\n",opt[optn][2]);

	match = !(
		strcmp(arg, opt[optn][0] ) &&
		strcmp(arg, opt[optn][1] ) &&
		strcmp(arg, opt[optn][2] )
	);
	if (match){
		debug("found :\t%s\n",arg);
	}
	return match;
} //isOption

UI32 parseOpts(UI32 argc, char **pArgv, OPTS *opts) {
	UI32 status=0,j=0;
	UI32 optStat[5]={[0 ... 4]=0};

	//options
	for (UI32 i=1 ; i < argc; i++) {
		if (!optStat[0]  && isOption( 0 ,&*pArgv[i]) ) {
				opts->b = pArgv[i+1];
				optStat[0] = 1 ;
				pArgv[i]=NULL;i++;pArgv[i]=NULL;

			}else	if ( !optStat[1] && isOption( 1,&*pArgv[i]) ) {
				debug("prefix detected:\t%s\n",pArgv[i+1]);
				opts->p = pArgv[i+1];
				optStat[0] = 1 ;
				pArgv[i]=NULL;
				pArgv[i]=NULL;i++;pArgv[i]=NULL;


			}else	if ( !optStat[j=2] && isOption( j,&*pArgv[i]) ) {
				opts->s = pArgv[i+1];
				optStat[j] = 1 ;
				pArgv[i]=NULL;i++;pArgv[i]=NULL;


			}else	if ( !optStat[j=3] && isOption( j,&*pArgv[i]) ) {
				opts->j = pArgv[i+1];
				optStat[j] = 1 ;
				pArgv[i]=NULL;i++;pArgv[i]=NULL;

			}else	if ( !optStat[j=4] && isOption( j,&*pArgv[i]) ) {
				opts->f = pArgv[i+1];
				optStat[j] = 1 ;
				pArgv[i]=NULL;i++;pArgv[i]=NULL;


			}else{
				debug("no match:\t%s\n",pArgv[i]);
			}//if
	}//done
	for (int i=0;i<5;i++){
		status|=optStat[i];
	}
	if (DEBUG){
		debug("begin:\t%s\n",opts->b);
		debug("prefix:\t%s\n",opts->p);
		debug("suffix:\t%s\n",opts->s);
		debug("join:\t%s\n",opts->j);
		debug("final:\t%s\n",opts->f);
	}
	return status;
} //parseArgs

#include "headers/argsParser.h"

char *pOpts[10];

static UI32 readPipe(){
  UI32 sR = 0;
	UI32 sA = 8;
	char *pipe =	malloc(sA);
	char cIn = Z0;
  // sPipe = getline(&pipe, &len, stdin);
	while ((cIn=getchar())!=EOF){

		if (!(sR%8)){
			sA+=8;
			char *pPipe = realloc(pipe,sA);
			if (pPipe==NULL) return 0;
			pipe=pPipe;
		}
		pipe[sR]=cIn;
		sR++;
		debug("read: %s\n",&cIn);
		debug("full: %s\n",pipe);
	}
	stdn.r=pipe;
	// *args.r[sR]=Z0;
	return 1;
}//readPipe

static UI32 isOption(UI32 optn ,char *arg ){
	UI32 match=0;
	debug("testing:\t%s",arg);
	debug("\tin\t%s",opt[optn][0]);
	debug(" %s ",opt[optn][1]);
	debug(" %s ",opt[optn][2]);

	match = !(
		strcmp(arg, opt[optn][0] ) &&
		strcmp(arg, opt[optn][1] ) &&
		strcmp(arg, opt[optn][2] )
	);
	if (match){
		debug("\x1b[60Gfound :\t%s\n",arg);
	}
	return match;
} //isOpti


static UI32 parseOpts(UI32 argc, char **argv) {
	UI32 status=0;
	UI32 optStat[10]={[0 ... 9]=0};

	pOpts[0] = &*opts.b;
	pOpts[1] = &*opts.p;
	pOpts[2] = &*opts.s;
	pOpts[3] = &*opts.j;
	pOpts[4] = &*opts.f;
	pOpts[5] = &*opts.c;
	pOpts[6] = &*opts.n;
	pOpts[7] = &*opts.r;
	pOpts[8] = &*opts.h;
	pOpts[9] = &*opts.v;


	//options
	for (UI32 i=1 ; i < argc; i++) {
		for(UI32 j= 0; j< 10;j++){
			if (!optStat[j]  && isOption( j ,&*argv[i]) ) {
				pOpts[j] = argv[i+1];
				optStat[j] = 1 ;
				debug("match: %s\t",argv[i]);
				debug("\t-> %s\n",argv[i+1]);
				break;

			}else{
				debug("\x1b[60Gno match: %s\n",argv[i]);
			}//if
		}//done
	}//done
	for (int i=0;i<10;i++){
		status|=(optStat[i]<<i);
	}

	return status;
} //parseArgs


UI32 parse(UI32 argc, char **argv){
	UI32 status=0;
	UI32 STATUS[32];
	if (!isatty(fileno(stdin))){
		STATUS[11]=readPipe();
		// if (! (status==1))return status;
		// STATUS[8]=status;
	}//fi
	status=parseOpts(argc,argv);\
	for (int i=0;i<10;i++){
		STATUS[i]=status&(1<<i);
	}
	if (DEBUG){
		for (int i = 0 ; i<10 ;i++){
			debug("%s\n",pOpts[i]);
		}
		for (int i = 0 ; i<10 ;i++){
			debug("%d",STATUS[i]);
		}



	}
	// for (int i=0;i<5;i++){
	// 	STATUS[i] = status & (1<<i) ? 0 :1;
	// }

return status;
}//parse

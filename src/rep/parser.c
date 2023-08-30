 #include "headers/argsParser.h"
//--98765432109876543210
//hv-----r-nr-vhnrcfjspb

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
	STATUS[14]=1; //got pipedata
	STATUS[12]=1; //skip arg rep
	return 1;
}//readPipe

static UI32 isOption(UI32 optn ,char *arg ){
	UI32 match=0;
	// debug("testing:\t%s",arg);
	// debug("\tin\t%s",opt[optn][0]);
	// debug(" %s ",opt[optn][1]);
	// debug(" %s ",opt[optn][2]);

	match = !(
		strcmp(arg, opt[optn][0] ) &&
		strcmp(arg, opt[optn][1] ) &&
		strcmp(arg, opt[optn][2] )
	);
				// printf("options if");
	return match;
} //isOption

static UI32 isFlag(UI32 flag ,char *arg ){
	UI32 match=0;
	// debug("testing:\t%s",arg);
	// debug("\tin\t%s",FLAG[flag][0]);
	// debug(" %s ",FLAG[flag][1]);
	// debug(" %s\n ",FLAG[flag][2]);

	match = !(
		strcmp(arg, FLAG[flag][0] ) &&
		strcmp(arg, FLAG[flag][1] ) &&
		strcmp(arg, FLAG[flag][2] )
	);
	if (match){
		debug("\x1b[60Gfound :\t%s\n",arg);
	}
	return match;
}//isFlag


static UI32 Flags(UI32 argc, char **argv){
	int gotflagged=	0;
	//flags
	for (UI32 i=1 ; i < argc; i++) {
		for(UI32 j= 0; j< 2;j++){
			if (isFlag( j ,argv[i]) ) {
				gotflagged=1;
				STATUS[30+j]=1;
				goto FLAGGED;
			}//fi
		}//done
	}//done
FLAGGED:
	return gotflagged;
}
static UI32 Opts(UI32 argc, char **argv) {
	UI32 status=0;
	UI32 optStat[12]={[0 ... 11]=0};
	UI32 dbreak=0;

	//options
	for (UI32 i=1 ; i < argc; i++) {
		for(UI32 j= 0; j< 10;j++){
			if (!STATUS[j]  && isOption( j ,argv[i]) ) {
				pOpts[j] = argv[++i];
				STATUS[j] = 1 ;
				dbreak=1;
				break;
			}
			dbreak=0;
		}//done
		if (!dbreak){
			if (!(STATUS[6] && STATUS[11])){
				args.r=argv[i];
				opts.r=argv[i];
				STATUS[6]=1;
				STATUS[11]=1;
				// optStat[6]=1;
				debug("\nrep-> %s\n",argv[i]);
			}	else if (!(STATUS[7] && STATUS[12])){
					args.n = atol(argv[i]);
					opts.n = argv[i];
					STATUS[7]=1;
					STATUS[12]=1;
					// optStat[7]=1;
					debug("\nn-> %s\n",argv[i]);
			}// else
		}//fi
	}//done
STOP:
	for (int i=0;i<32;i++){
		status+=(STATUS[i]*(1<<i));
	}
	print_binary(status);

	return status;
} //parseOpts


UI32 parse(UI32 argc, char **argv){
	UI32 status=0;
	status=Flags(argc,argv)

	if (!isatty(fileno(stdin))){
		status=readPipe();

	}//fi
	status=parseOpts(argc,argv);
	print_binary(status);
	return status;
}//parse

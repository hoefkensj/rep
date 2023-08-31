 #include "headers/parser.h"
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
			if (pPipe==NULL) return 1;
			pipe=pPipe;
		}
		pipe[sR]=cIn;
		sR++;
	}
	stdn.r=pipe;
	STATUS[14]=1; //got pipedata
	STATUS[12]=1; //skip arg rep
	return 0;
}//readPipe

static UI32 isOption(UI32 optn ,char *arg ){
	UI32 match=0;
	match = !(
		strcmp(arg, opt[optn][0] ) &&
		strcmp(arg, opt[optn][1] ) &&
		strcmp(arg, opt[optn][2] )
	);
	return match;
} //isOption

static UI32 isFlag(UI32 flagn ,char *arg ){
	UI32 match=0;
	match = !(
		strcmp(arg, FLAG[flagn][0] ) &&
		strcmp(arg, FLAG[flagn][1] ) &&
		strcmp(arg, FLAG[flagn][2] )
	);
	return match;
}//isFlag


static UI32 Flags(UI32 argc, char **argv){
	UI32 gotflagged=	0;
	//flags
	for (UI32 i=1 ; i < argc; i++) {
		for(UI32 j= 0; j< 2;j++){
			if (isFlag( j ,argv[i]) ) {
				gotflagged=-1;
				STATUS[30+j]=1;
				break;
			}//fi
			if (STATUS[29]|STATUS[30]|STATUS[31])	break;
		}//done
	}//done
	return gotflagged;
}//Flags

static UI32 Opts(UI32 argc, char **argv) {
	UI32 status=0;
	UI32 optStat[12]={[0 ... 11]=0};
	UI32 dbreak=0;

	//options
	for (UI32 i=1 ; i < argc; i++) {
		for(UI32 j= 0; j< 10;j++){
			if (!STATUS[j]  && isOption( j ,argv[i]) ) {
				pOpts[j] = ++i;
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
			}	else if (!(STATUS[7] && STATUS[12])){
					args.n = atol(argv[i]);
					opts.n = argv[i];
					STATUS[7]=1;
					STATUS[12]=1;
					// optStat[7]=1;
			}// else
		}//fi
	}//done

	for (int i=0;i<32;i++){
		status+=(STATUS[i]*(1<<i));
	}

	return status;
} //Opts


UI32 parse(UI32 argc, char **argv){
	UI32 status=0;
	printf("parsing...");

	status=Flags(argc,argv);
	if (status != 0){
		printf("FLAGGED...");
		goto END;
	}
	printf("NOT FLAGGED...");

	if (!isatty(fileno(stdin))){
		status=readPipe();
	}//fi
	printf("piped...");


	status=Opts(argc,argv);
	printf("ASSIGNING...");

	for (int i=0;i<10;i++){
		switch (i){
			case 0:	opts.b=argv[pOpts[i]];
			case 1:	opts.p=argv[pOpts[i]];
			case 2:	opts.s=argv[pOpts[i]];
			case 3:	opts.j=argv[pOpts[i]];
			case 4:	opts.f=argv[pOpts[i]];
		}
	}

END:
	return status;
}//parse

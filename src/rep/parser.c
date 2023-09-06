#define _GNU_SOURCE
#include "headers/parser.h"
//--98765432109876543210
//hv-----r-nr---nrcfjspb
static char *FLAG[2][3] = {
	{"-v", "--ver", "--version" },
	{"-h", "-?", "--help",   }};

static char *opt[10][3]  = {
	{"-b", "--bgn", "--begin"   },
	{"-p", "--pfx", "--prefix"  },
	{"-s", "--sfx", "--suffix"  },
	{"-j", "--jnt", "--join"    },
	{"-f", "--fin", "--final"   },
	{"-c", "--col", "--colums"  },
	{"-r", "--rep", "--repeat"  },
	{"-n", "--num", "--number"  },
	{"-v", "--ver", "--version" },
	{"-h", "-?", "--help",   }};

UI32 STATUS[32]={[0 ... 31]=0};
UI32 pOpts[8]={[0 ... 7]=0};
UI32 pArgs[2]={[0 ... 1]=0};

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
	}
	stdn.r=pipe;
	STATUS[14]=1; //got pipedata
	rep.i=1;
	return rep.i;
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
		for(UI32 j= 0; j< 8;j++){
			if ((!STATUS[j])  && isOption( j ,argv[i]) ) {
				pOpts[j] = ++i;
				printf("\narg: %i detected:%s in %s \tvalue=%s",i,argv[i-1],opt[j][0],argv[i]);
				STATUS[j] = 1 ;
				dbreak=1;
				break;
			}
			dbreak=0;
		}//DONE
		if (!dbreak){
			if (!(STATUS[14]||STATUS[11]||STATUS[6])){
				pArgs[0]=i;
				printf("\nargs:r arg: %i  value: %s\n",pArgs[0],argv[pArgs[0]]);
				STATUS[11]=1;
			}	else if (!(STATUS[12]||STATUS[7])){
				pArgs[1] = i;
				printf("\nargs:n arg: %i  value: %s\n",pArgs[0],argv[pArgs[1]]);

				STATUS[12]=1;
			}// else
		}//fi
	}//done

	return status;
} //Opts

UI32 parse(UI32 argc, char **argv){
	UI32 status=0;
	printf("\nPARSING...");

	status=Flags(argc,argv);
	if (status != 0){
		printf("\n\tFLAGGED...");
		goto END;
	}
	printf("\n\tNOT FLAGGED...");

	if (!isatty(fileno(stdin))){
		status=readPipe();
	}//fi
	if (status==0){
		stdn.r="";
	}
	printf("piped...");


	status=Opts(argc,argv);
	printf("\nASSIGNING...\n");

	for (int i=0;i<8;i++){
		printf("opt: %i: status:%i\t",i,STATUS[i]);
		if(STATUS[i]==1){
			switch(i){
				case 0:		opts.b=argv[pOpts[i]];printf("%i:b %s\n",i,argv[pOpts[i]]);	break;
				case 1:		opts.p=argv[pOpts[i]];printf("%i:p %s\n",i,argv[pOpts[i]]);break;
				case 2:		opts.s=argv[pOpts[i]];printf("%i:s %s\n",i,argv[pOpts[i]]);break;
				case 3:		opts.j=argv[pOpts[i]];printf("%i:j %s\n",i,argv[pOpts[i]]);break;
				case 4:		opts.f=argv[pOpts[i]];printf("%i:f %s\n",i,argv[pOpts[i]]);break;
				case 5:		opts.c=argv[pOpts[i]];printf("%i:c %s\n",i,argv[pOpts[i]]);break;
				case 6:		opts.r=argv[pOpts[i]];printf("%i:or %s\n",i,argv[pOpts[i]]);break;
				case 7:		opts.n=argv[pOpts[i]];printf("%i:on %s\n",i,argv[pOpts[i]]);break;

			}
		}	else	{
			printf("\n");
		}
	}
	for (int i=11;i<13;i++){
		printf("arg %i: status:%i\t",i,STATUS[i]);
		if(STATUS[i]==1){
			switch(i){
				case 11:		args.r=argv[pArgs[0]];printf("%i:or %s\t",i,argv[pArgs[0]]);break;
				case 12:		args.n=argv[pArgs[1]];printf("%i:on %s\t",i,argv[pArgs[1]]);break;
			}
		}
	}

END:
	return 0;
}//parse

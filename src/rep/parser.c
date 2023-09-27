#define _GNU_SOURCE
#include "headers/parser.h"
//--98765432109876543210
//hv-----r-nr---nrcfjspb
static char *FLAG[3][3] = {
	{"-d", "--deb", "--debug"   },
	{"-h", "-?", "--help",      },
	{"-v", "--ver", "--version" },
};

static char *OPT[8][3]  = {
	{"-b", "--bgn", "--begin"   },
	{"-p", "--pfx", "--prefix"  },
	{"-s", "--sfx", "--suffix"  },
	{"-j", "--jnt", "--join"    },
	{"-f", "--fin", "--final"   },
	{"-c", "--col", "--colums"  },
	{"-r", "--rep", "--repeat"  },
	{"-n", "--num", "--number"  }
};

static UI32 isOption(UI32 n ,char *arg ){
	UI32 match=0;
	match = !(
		strcmp(arg, OPT[n][0] ) &&
		strcmp(arg, OPT[n][1] ) &&
		strcmp(arg, OPT[n][2] )
	);
	return match;
} //isOption

static UI32 isFlag(UI32 n ,char *arg ){
	UI32 match=0;
	match = !(
		strcmp(arg, FLAG[n][0] ) &&
		strcmp(arg, FLAG[n][1] ) &&
		strcmp(arg, FLAG[n][2] )
	);
	return match;
}//isFlag


UI32 check_flags(UI32 argc, char **argv,UI32 STATUS[32]){
	UI32 ret=0;
	for (UI32 i=1 ; i < argc; i++) {
		for(UI32 j= 0; j< 3;j++){
			if (isFlag( j ,argv[i]) ){
				STATUS[31-j]=1;
				ret=ret+(1<<(j+1));
				printf("ret= %i\n",ret);
				argv[i]="";
			}
		}//done
	}//done
	return ret;
}//Flags

static UI32 Opts(UI32 argc, char **argv ,UI32 pOpts[8],UI32 pArgs[2],UI32 STATUS[32]) {
	UI32 status=0;
	UI32 dbreak=0;
	if (STATUS[14]){
		STATUS[11]=1;
		STATUS[6]=1;
	}
	//options
	for (UI32 i=1 ; i < argc; i++) {
		for(UI32 j= 0; j< 8;j++){
			if ((!STATUS[j])  && isOption( j ,argv[i]) ) {
				pOpts[j] = ++i; // option j is the next value of i
				// printf("\narg: %i detected:%s in %s \tvalue=%s",i,argv[i-1],opt[j][0],argv[i]);
				STATUS[j] = 1 ;// 	option found , dont find it again
				dbreak=1; // option found so this and the next are no argument
				break; // break out of the testing each option loop
			}
			dbreak=0; //didnt find a match so make sure we test for argument matches
		}//DONE
		if (!dbreak){
			if (STATUS[14]+STATUS[11]+STATUS[6]==0){
				pArgs[0]=i;
				// printf("\nargs:r arg: %i  value: %s\n",pArgs[0],argv[pArgs[0]]);
				STATUS[11]=1;
			}	else if (STATUS[12]+STATUS[7]==0){
				pArgs[1] = i;
				printf("\nargs:n arg: %i  value: %s\n",pArgs[1],argv[pArgs[1]]);

				STATUS[12]=1;
			}// else
		}//fi
	}//done
	if (STATUS[14]){
		STATUS[11]=0;
		STATUS[6]=0;
	}
	return status;
} //Opts

UI32 parse(UI32 argc, char **argv){
	UI32 status=0;
	char *strStdin;

	UI32 pOpts[8]={[0 ... 7]=0};
	UI32 pArgs[2]={[0 ... 1]=0};

	status=Opts(argc,argv,pOpts,pArgs,STATUS);
	// printf("\nASSIGNING...\n");

	for (int i=0;i<8;i++){
		// printf("opt: %i: status:%i\t",i,STATUS[i]);
		if(STATUS[i]==1){
			switch(i){
				case 0:		opts.b=argv[pOpts[i]];break;
				case 1:		opts.p=argv[pOpts[i]];break;
				case 2:		opts.s=argv[pOpts[i]];break;
				case 3:		opts.j=argv[pOpts[i]];break;
				case 4:		opts.f=argv[pOpts[i]];break;
				case 5:		opts.c=argv[pOpts[i]];break;
				case 6:		opts.r=argv[pOpts[i]];break;
				case 7:		opts.n=argv[pOpts[i]];break;
				case 11:	args.r=argv[pArgs[0]];break;
				case 12:	args.n=argv[pArgs[1]];break;
			}
		}
	}
END:
	return 0;
}//parse

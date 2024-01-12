#define _GNU_SOURCE
#include "headers/parser.h"


static char *FLAG[4][3] = {
	{"-v", "--ver", "--version"    },
	{"-h", "-?", "--help",         },
	{"-d", "--deb", "--debug"      },
	{"-e", "--esc", "--noescape"   },
};

static char *OPT[8][3]  = {
	{"-r", "--rep", "--repeat"  },
	{"-n", "--num", "--number"  },
	{"-b", "--bgn", "--begin"   },
	{"-p", "--pfx", "--prefix"  },
	{"-s", "--sfx", "--suffix"  },
	{"-j", "--jnt", "--join"    },
	{"-f", "--fin", "--final"   },
	{"-c", "--col", "--colums"  }
};

static UI32 isOption(UI32 n ,char *arg ){
	return !(
		strcmp(arg, OPT[n][0] ) &&
		strcmp(arg, OPT[n][1] ) &&
		strcmp(arg, OPT[n][2] )
	);
} //isOption

static UI32 isFlag(UI32 n ,char *arg ){
	return !(
		strcmp(arg, FLAG[n][0] ) &&
		strcmp(arg, FLAG[n][1] ) &&
		strcmp(arg, FLAG[n][2] )
	);
}//isFlag


UI32 check_flags(UI32 argc, char **argv){
	UI32 ret=0;
	for (UI32 i=1 ; i < argc; i++) {
		for(UI32 j= 0; j< 4;j++){
			if (isFlag( j ,argv[i]) ){
				Flag(set,F+j);
				ret=ret+(1<<(j+1));
				argv[i]="";
			}
		}//done
	}//done
	return ret;
}//Flags

UI32 check_Opts(UI32 argc, char **argv ,UI32 pOpts[8],UI32 pArgs[2]) {
	UI32 status=0;
	UI32 dbreak=0;
	UI32 startopt=0;
	if (Flag(get,I+Repeat)){
		startopt=1;
		// 	Flag(set,A+Repeat);
	// 	Flag(set,O+Repeat);
	}
	//options
	for (UI32 i=1 ; i < argc; i++) {
		for(UI32 j= startopt; j< 8;j++){
			if ((!Flag(get,j))  && isOption( j ,argv[i]) ) {
				pOpts[j] = ++i; // option j is the next value of i
				Flag(set,j);// 	option found , dont find it again
				dbreak=1; // option found so this and the next are no argument
				break; // break out of the testing each option loop
			}
			dbreak=0; //didnt find a match so make sure we test for argument matches
		}//DONE
		if (!dbreak){
			if (Flag(get,I+Repeat)+Flag(get,A+Repeat)+Flag(get,O+Repeat)+Flag(get,E+Repeat)==0){
				pArgs[0]=i;
				Flag(set,A+Repeat);
			}	else if (Flag(get,A+Number)+Flag(get,O+Number)==0){
				char first=argv[i][0];
				if ((first>48)&(first<57)){
					pArgs[1] = i;
					Flag(set,A+Number);
				}else{
					pArgs[0]=i;
					Flag(set,A+Repeat);
				}
			}// else
		}//fi
	}//done

		printbin(STATUS);

	return status;
} //Opts

UI32 parse(UI32 argc, char **argv){
	UI32 status=0;
	UI32 pOpts[8]={[0 ... 7]=0};
	UI32 pArgs[2]={[0 ... 1]=0};

	status=check_Opts(argc,argv,pOpts,pArgs);
	// printf("\nASSIGNING...\n");

	for (int i=0;i<15;i++){
		// printf("opt: %i: status:%i\t",i,STATUS[i]);
		if(Flag(get,i)==1){
			switch(i){
				case 0:		opts.r=argv[pOpts[i]];break;
				case 1:		opts.n=argv[pOpts[i]];break;
				case 2:		opts.b=argv[pOpts[i]];break;
				case 3:		opts.p=argv[pOpts[i]];break;
				case 4:		opts.s=argv[pOpts[i]];break;
				case 5:		opts.j=argv[pOpts[i]];break;
				case 6:		opts.f=argv[pOpts[i]];break;
				case 7:		opts.c=argv[pOpts[i]];break;
				case 11:	args.r=argv[pArgs[0]];break;
				case 12:	args.n=argv[pArgs[1]];break;
			}
		}
	}
	return status;
}//parse

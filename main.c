#include "main.h"
int return_code = 0;
ARGS args;
ARGS nargs;

void repeat(){
	unsigned long int n = args.n;
	for (int i = 0; i < n; i++) {
		printf("%s",args.rep);
		if (i < (n-1)) {
			printf("%s", args.cat);
		} // fi
	} // for
}

void printseq(ARGS args){

	printf("%s",escape(args.pfx,args.pfx));
	repeat();
	printf("%s",escape(args.sfx,args.sfx));
}


void parseArguments(int argc, char **argv) {
	// init arguments
	return_code = 2;
	args.rep = NULL;
	args.pfx = "";
	args.sfx = "";
	args.cat = "";
	args.n = 0;
	int i =  0;

	for (i=1 ; i < argc; i++) {
		if  ( (strcmp(argv[i], "--help") == 0) | (strcmp(argv[i], "-h") ==0) ) {
			return_code=3;
			break;
		} else if ( (strcmp(argv[i], "--pfx") == 0) | (strcmp(argv[i], "-p") ==0) ) {
			args.pfx = argv[++i];
				// args.a |=  ( 1 << 2 );

		} else if ( (strcmp(argv[i], "--sfx") == 0) | (strcmp(argv[i], "-s") ==0) ) {
			args.sfx = argv[++i];
				// args.a |=  ( 1 << 3 );
		} else if ( (strcmp(argv[i], "--cat") == 0) | (strcmp(argv[i], "-c") ==0) )  {
			args.cat = argv[++i];
				// args.a |=  ( 1 << 4 );
		} else {
			if (args.rep == NULL) {
				// args.a |=  ( 1 << 0 );
				args.rep = argv[i];
				return_code--;
			} else {
				args.n = atol(argv[i]);
				// args.a |=  ( 1 << 1 );
				return_code--;
			} //fi
		} //fi
	} //for
}// parseArguments


int main(int argc, char *argv[]) {
	parseArguments(argc, argv);
	args.rep=escape(args.rep,args.rep);
	printseq(args);
	if (return_code == 1)	print_usage(argv[0]);
	return return_code;
}

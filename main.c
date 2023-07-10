#include "main.h"
int return_code = 0;
ARGS args;

void repeat(){
	unsigned long int n = args.n;
	for (int i = 0; i < n; i++) {
		printf("%s",args.rep);
		if (i < (n-1)) {
			printf("%s", args.cat);
		} // fi
	} // for
}

void printseq(){
	printf("%s",args.pfx);
	repeat();
	printf("%s",args.sfx);
}


void parseArguments(int argc, char **argv) {
	// init arguments
	return_code = 2;
	args.rep = NULL;
	args.pfx = NULL;
	args.sfx = NULL;
	args.cat = NULL;
	args.n = 0;
	int i =  0;

	for (i=1 ; i < argc; i++) {
		if  ( (strcmp(argv[i], "--help") == 0) | (strcmp(argv[i], "-h") ==0) ) {
			return_code=3;
			break;
		} else if ( (strcmp(argv[i], "--pfx") == 0) | (strcmp(argv[i], "-p") ==0) ) {
			args.pfx = argv[++i];
				args.a |=  ( 1 << 2 );

		} else if ( (strcmp(argv[i], "--sfx") == 0) | (strcmp(argv[i], "-s") ==0) ) {
			args.sfx = argv[++i];
				args.a |=  ( 1 << 3 );
		} else if ( (strcmp(argv[i], "--cat") == 0) | (strcmp(argv[i], "-c") ==0) )  {
			args.cat = argv[++i];
				args.a |=  ( 1 << 4 );
		} else {
			if (args.rep == NULL) {
				args.a |=  ( 1 << 0 );
				args.rep = argv[i];
				return_code--;
			} else {
				args.n = atol(argv[i]);
				args.a |=  ( 1 << 1 );
				return_code--;
			} //fi
		} //fi
	} //for
}// parseArguments


int main(int argc, char *argv[]) {
	parseArguments(argc, argv);
	printf("%s\n",args.rep);
	char *prep[strlen(args.rep)];
	escape(args.rep, prep);
	printf("%s\n",*prep);

	// char slash[2]="\n";
	// printf("%s\n",escape(slash));
	// printf("%s\n",escape(argv[1]));
	// printf("%s\n",escape(argv[2]));
	// printf("%s\n",escape(argv[3]));
	// parseArguments(argc, argv);
	// int lenarg = strlen(argv[1]);
	// char transtext[lenarg];
	// sprintf(transtext,"%s",translate(argv[1]));
	// printf("\x1b[%smTEST%s","32","\n");
	// print();
	if (return_code == 1)	print_usage(argv[0]);
	return return_code;
}

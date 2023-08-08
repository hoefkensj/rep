#include "headers/main.h"
#define ARGSPRINT "\
num:\t%i\n\
col:\t%i\n\
bgn:\t%s\n\
pfx:\t%s\n\
rep:\t%s\n\
sfx:\t%s\n\
cat:\t%s\n\
end:\t%s\n\
"

int main(int argc, char *argv[]) {

	args.n = 0;
	args.w = 0;
	args.b = NULL;
	args.p = NULL;
	args.r = NULL;
	args.s = NULL;
	args.c = NULL;
	args.e = NULL;
	UI32 p=0,h=0;
	if (!isatty(fileno(stdin))){
		p = *readPipe(args.r,	nwbprsce[4]);
	}//fi

	h=parseArgs(argc,argv,&args,nwbprsce);
	repeat(args);

	if (p ){
		free(args.r);
	}
	printf("%i\n",h);
	return 0;
}//main

void repeat(ARGS args){
	UI32 n;
	print( args.b );
	for ( n= args.n ; n >  0 ; n--) {
		print( args.p );
		print( args.r );
		print( args.s );
		if ( args.n > 1 ){
			print( args.c );
		}//fi
	} // for
	print( args.e );
}//repeat

void print(char *str){	printf("%s",str);}


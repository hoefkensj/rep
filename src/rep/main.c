#include "headers/main.h"


OPTS opts;
ARGS args;
PIPE stdn;

int main(int argc, char *argv[]) {
	UI32 status = 1;

	status=parse(argc,argv);
	return status;
}//main

static void repeat(){

	UI32 n;
	// escapeStrs();
	printf("%s", opts.b );
	for ( n= args.n ; n >  0 ; n--) {
		print(opts.p);
		print(args.r );
		print(opts.s);
		if ( n > 1 ){
			print(opts.j);
		}//fi
	} // for
	// printf("%s",escape(opts.f));
}//repeat


void debug(char *fmt,char *str){
	if (DEBUG){
		printf(fmt,str);
	}//fi
}//debug

void print(char *str){	printf("%s",str);}


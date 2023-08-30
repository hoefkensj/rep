#include "headers/main.h"


OPTS opts;
ARGS args;
PIPE stdn;
UI32 STATUS[32]={[0 ... 31]=0};

// Declaration of the array of pointers
char *pOpts[] = {opts.b, opts.p, opts.s, opts.j, opts.f,opts.c, opts.r, opts.n, opts.h, opts.v};

void init() {
	opts.b = "";
	opts.p = "";
	opts.s = "";
	opts.j = "";
	opts.f = "";
	opts.c = "";
	opts.r = "";
	opts.n = "";
	opts.h = "";
	opts.v = "";

	pOpts[0] = opts.b;
	pOpts[1] = opts.p;
	pOpts[2] = opts.s;
	pOpts[3] = opts.j;
	pOpts[4] = opts.f;
	pOpts[5] = opts.c;
	pOpts[6] = opts.r;
	pOpts[7] = opts.n;
	pOpts[8] = opts.h;
	pOpts[9] = opts.v;

	args.n=0;
	args.r=NULL;
}

int main(int argc, char *argv[]) {
	UI32 status = 1;
	init();
	debug("init done\n", "");

	status=parse(argc,argv);
	debug("parse done\n", "");
	repeat();
	return 1;
}//main

static void repeat(){

	UI32 n;
	// escapeStrs();
	printf("%s", escape(opts.b) );
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

void print_binary(unsigned int number){
		if (DEBUG){
			for (int i = 32; i>=0;i--){
				putc((number & (1<<i)) ? '1' : '0', stdout);
			}
			printf("\n");
		}
}

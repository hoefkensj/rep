#include "headers/main.h"




// Declaration of the array of pointers


void init() {

	opts.b= "";
	opts.p= "";
	opts.s= "";
	opts.j= "";
	opts.c= "";
	opts.r= "";
	opts.n= "";
	opts.h= "";
	opts.v= "";
	// **pOpts[0] = *opts.b;
	// **pOpts[1] = *opts.p;
	// **pOpts[2] = *opts.s;
	// **pOpts[3] = *opts.j;
	// **pOpts[4] = *opts.c;
	// **pOpts[5] = *opts.r;
	// **pOpts[6] = *opts.n;
	// **pOpts[7] = *opts.h;
	// **pOpts[8] = *opts.v;
	pOpts[0] = &opts.b;
	pOpts[1] = &opts.p;
	pOpts[2] = &opts.s;
	pOpts[3] = &opts.j;
	pOpts[4] = &opts.c;
	pOpts[5] = &opts.r;
	pOpts[6] = &opts.n;
	pOpts[7] = &opts.h;
	pOpts[8] = &opts.v;

}

int main(int argc, char *argv[]) {
	UI32 status = 1;
	init();
	debug("init done\n", "");

	status=parse(argc,argv);
	debug("parse done\n","");

	debug("opts.p: %p\n",opts.p);
  printf("%s\n",opts.p);
printf("%s\n",pOpts[0]);
	debug("opts.s: %s\n",opts.p);
	debug("opts.j: %s\n",opts.j);
	debug("opts.f: %s\n",opts.f);

	repeat();
	return status;
}//main

static void repeat(){

	UI32 n;
	// escapeStrs();
	debug("escape? %s\n",opts.b);
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

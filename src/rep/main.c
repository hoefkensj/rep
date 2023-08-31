#include "headers/main.h"




// Declaration of the array of pointers
static void esc(){
	opts.b=escape(opts.b);
	opts.p=escape(opts.p);
	opts.s=escape(opts.s);
	opts.j=escape(opts.j);
	opts.f=escape(opts.f);
}


int main(int argc, char *argv[]) {
	UI32 status = 1;
	status=parse(argc,argv);
	// if (status!=0) goto LAST;
	esc();
	repeat();

LAST:
	if (STATUS[30]){

	}
	return status;
}//main

static void repeat(){
	UI32 n;
	printf("%s",opts.b);

	for ( n= args.n ; n >  0 ; n--) {
		printf("%s%s%s",opts.p,opts.r,opts.s);
		printf("%s%s%s",opts.p,args.r,opts.s);
		if ( n > 1 ){
			printf("%s",opts.j);
		}//fi
	} // for
	printf("%s",opts.f);
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

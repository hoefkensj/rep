#define _GNU_SOURCE
#include "headers/main.h"
#include "headers/parser.h"
#include "headers/escape.h"
#include "headers/info.h"
//--98765432109876543210
//hv-----r-nr---nrcfjspb
static void init(){
	opts.b="";
	opts.p="";
	opts.s="";
	opts.j="";
	opts.f="";
	opts.c="";
	opts.r="";
	opts.n="";

	args.n="";
	args.r="";
}

static UI32 compile_vars(){
	if (STATUS[5]) num.c=atol(opts.c);
	if (STATUS[7]) num.o=atol(opts.n);
	if (STATUS[12]) num.a=atol(args.n);
	for (int i=0;i<16;i++){
		if(STATUS[i]==1){
			switch(i){
				case 0:		opts.b=escape(opts.b);break;
				case 1:		opts.p=escape(opts.p);break;
				case 2:		opts.s=escape(opts.s);break;
				case 3:		opts.j=escape(opts.j);break;
				case 4:		opts.f=escape(opts.f);break;
				case 5:		num.c=atol(opts.c);break;
				case 6:		opts.r=escape(opts.r);break;
				case 7:		num.o=atol(opts.n);break;
				case 11:	args.r=escape(args.r);break;
				case 12:	num.a=atol(args.n);break;
				case 14:	stdn.r=escape(stdn.r);break;
			}
		}
	}
	return 0;
}
int main(int argc, char *argv[]) {
	init();
	err.parse = parse(argc,argv);
	err.escape =	compile_vars();
	err.repeat = repeat();
	return 0;
}//main

UI32 repeat(){
	UI32 n = 0;
	n= (STATUS[7]*num.o)+(STATUS[12]*num.a);
	//repeat sequence :
	printf("%s",opts.b);
	for ( n ; n >  0 ; n--) {
		printf("%s",opts.p);
		printf("%s",opts.r);
		printf("%s",args.r);
		printf("%s",stdn.r);
		printf("%s",opts.s);
		if ( n > 1 ){
			printf("%s",opts.j);
		}//fi
	} // for
	printf("%s",opts.f);
	return 0;
}//repeat


UI32 debug(){
	printf("\n-------STRINGS-------\n");
	printf("opts.b= %s\n",opts.b);
	printf("opts.p= %s\n",opts.p);
	printf("opts.s= %s\n",opts.s);
	printf("opts.j= %s\n",opts.j);
	printf("opts.f= %s\n",opts.f);
	printf("opts.r= %s\t",opts.r);
	printf("args.r= %s\t",args.r);
	printf("stdn.r= %s\n",stdn.r);
	printf("---------------------\n");
	printf("------INTEGERS-------\n");
	printf("opts.c= %s\t",opts.c);
	printf("num.c= %d\n",num.c);
	printf("opts.n= %s\t",opts.n);
	printf("num.o= %d\n",num.o);
	printf("args.n= %s\t",args.n);
	printf("num.a= %d\n",num.a);
	printf("------PROCESSED-------\n");
}
UI32 show_info(){
	return 0;
}

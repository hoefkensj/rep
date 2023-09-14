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
	num.a=0;
	num.o=0;
	num.c=0;

}
UI32 debug(UI32 select){
	if (select==1){
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
	} else if (select == 2){
		printf("------INTEGERS-------\n");
		printf("opts.c= %s\t",opts.c);
		printf("num.c= %d\n",num.c);
		printf("opts.n= %s\t",opts.n);
		printf("num.o= %d\n",num.o);
		printf("args.n= %s\t",args.n);
		printf("num.a= %d\n",num.a);
		printf("---------------------\n");
	} else if (select==3){
		printf("------PROCESSED-------\n");
		printf("opts.b= %s\x1b[m\n",opts.b);
		printf("opts.p= %s\x1b[m\n",opts.p);
		printf("opts.s= %s\x1b[m\n",opts.s);
		printf("opts.j= %s\x1b[m\n",opts.j);
		printf("opts.f= %s\x1b[m\n",opts.f);
		printf("opts.r= %s\x1b[m\t",opts.r);
		printf("args.r= %s\x1b[m\t",args.r);
		printf("stdn.r= %s\x1b[m\n",stdn.r);
		printf("---------------------\n");
	}
}

static UI32 compile_vars(){

	if (STATUS[5]) num.c=atol(opts.c);
	if (STATUS[7]) num.o=atol(opts.n);
	if (STATUS[12]) num.a=atol(args.n);

	for (int i=0;i<16;i++){
		if(STATUS[i]==1){
			switch(i){
				case 0:		escape(opts.b);break;
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
	debug(3);

	return 0;
}
int main(int argc, char *argv[]) {
	init();
	err.parse = parse(argc,argv);
	debug(1);
	for (int i =0 ; i<32;i++){
		printf("%i-",STATUS[i]);
	}
	err.escape =	compile_vars();
	debug(2);
	debug(3);

	err.repeat = repeat();
	return 0;
}//main

UI32 repeat(){
	UI32 n = 0;
	n= num.a+num.o;
	//repeat sequence :
	printf("%s",opts.b);
	for ( int i=n ; i >  0 ; i--) {
		printf("%s",opts.p);
		printf("%s",opts.r);
		printf("%s",args.r);
		printf("%s",stdn.r);
		printf("%s",opts.s);
		if ( i > 1 ){
			printf("%s",opts.j);
		}//fi
	} // for
	printf("%s",opts.f);
	return 0;
}//repeat



UI32 show_info(){
	return 0;
}

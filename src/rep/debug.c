#define _GNU_SOURCE
#include "headers/debug.h"

UI32 debug_proc(UI32 select){
SELECT:
	if (select&(1<0)){
		printf("-1-0-9-8-7-6-5-4-3-2-1-0-9-8-7-6-5-4-3-2-1-0-9-8-7-6-5-4-3-2-1-0\n");
		printf("-d-h-v-----------------------------r---n-r-------n-r-c-f-j-s-p-b\n");
		for (int i = 31 ; i>=0;i--){
			printf("-%i",STATUS[i]);
		}
		printf("\n");
		select-=(1<0);
	}
	if (select&(1<1)){
		printf("\n-------STRINGS-------\n");
		goto STRINGS;
	}
	if (select&(1<2)){
		printf("------INTEGERS-------\n");
		printf("opts.c= %s\t",opts.c);
		printf("num.c= %d\n",num.c);
		printf("opts.n= %s\t",opts.n);
		printf("num.o= %d\n",num.o);
		printf("args.n= %s\t",args.n);
		printf("num.a= %d\n",num.a);
		printf("---------------------\n");
	}
	if (select&(1<3)){
		printf("------PROCESSED-------\n");
				select-=(1<3);
		goto STRINGS;
	}
	goto END;
STRINGS:
		printf("opts.b= %s\n",opts.b);
		printf("opts.p= %s\n",opts.p);
		printf("opts.s= %s\n",opts.s);
		printf("opts.j= %s\n",opts.j);
		printf("opts.f= %s\n",opts.f);
		printf("opts.r= %s\t",opts.r);
		printf("args.r= %s\t",args.r);
		printf("stdn.r= %s\n",stdn.r);
		printf("---------------------\n");
		goto SELECT;
END:
	return 0;
}

void debug_print(const char *tpl,...){
	if (debug){
		va_list args;
    va_start(args, tpl);
    vprintf(tpl, args);
    va_end(args);
	}
}

void main_debug(int argc, char *argv[]){

	if (debug) debug_print("%s\n","DEBUG: ENABLED...");
	if (debug) debug_print("%s","DEBUG: INIT... ");
	// init();
	if (debug) debug_print("\x1b[50G\x1b[32m%s\x1b[m\n","DONE");
	debug_proc(1);
	if (debug) debug_print("\n%s","DEBUG: CHECKING FLAGS... ");
	// err.flags	=	check_flags(argc,argv,STATUS);
	if (debug) debug_print("\x1b[50G\x1b[32m%s\x1b[m\n","DONE");
	// if (err.flags!=0) runInfo(0,argc,argv);
	if (debug) debug_print("\n%s","DEBUG: CHECKING STDIN... ");
	// err.pipe= read_stdin(STATUS);
	if (debug) debug_print("\x1b[50G\x1b[32m%s\x1b[m\n","DONE");



}
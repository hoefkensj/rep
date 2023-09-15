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
	init();\
	if (debug) debug_print("\x1b[50G\x1b[32m%s\x1b[m\n","DONE");
	debug_proc(1);
	if (debug) debug_print("\n%s","DEBUG: CHECKING FLAGS... ");
	err.flags	=	check_flags(argc,argv,STATUS);
	if (debug) debug_print("\x1b[50G\x1b[32m%s\x1b[m\n","DONE");
	if (err.flags!=0) runInfo(0,argc,argv);
	if (debug) debug_print("\n%s","DEBUG: CHECKING STDIN... ");
	err.pipe= read_stdin(STATUS);
	if (debug) debug_print("\x1b[50G\x1b[32m%s\x1b[m\n","DONE");



}
static char *fmtInfo(char *strInfo ,char *exeName){
	char *bufUse=malloc(strlen(strInfo) + strlen(exeName) + 1);
	sprintf(bufUse,strInfo,exeName);
	return bufUse;
}
static UI32 compile_strings(){
	UI32 done = 0;
	for (int i=0;i<16;i++){
		if(STATUS[i]==1){
			done ++ ;
			switch(i){
				case 0:		opts.b = escape(opts.b);break;
				case 1:		opts.p = escape(opts.p);break;
				case 2:		opts.s = escape(opts.s);break;
				case 3:		opts.j = escape(opts.j);break;
				case 4:		opts.f = escape(opts.f);break;
				case 6:		opts.r = escape(opts.r);break;
				case 11:	args.r = escape(args.r);break;
				case 14:	stdn.r = escape(stdn.r);break;
			}
		}
	}
	return done;
}
int main(int argc, char *argv[]) {
	if (debug) main_debug(argc,argv);
	init();

	err.flags = check_flags(argc,argv,STATUS);
	if (err.flags!=0) runInfo(0,argc,argv);
	err.pipe= read_stdin(STATUS);
	if (err.pipe>1) runInfo(2,argc,argv);

	err.parse = parse(argc,argv);
	// err.escape =	compile_strings();
	if(MANDATORY==0){
		printf("MISSING: <STRING> and <NUM>\n");
		runInfo(3,argc,argv);
	}

	// err.repeat = repeat();
END:
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
void runInfo(int select,int argc,char **argv){
	if (!select){
		for (int i = 1 ; i < 4; i++ ){
			if ((err.flags & (1<<i))==1 ){
				select=i;
			}
		}
	}

	switch(select){
		case 1: // about
			printf("\n%s\n",fmtInfo("%s ABOUT",argv[0]));
			break;
		case 2: //help
			printf("\n%s\n",fmtInfo(HELP,argv[0]));
			break;
		case 3: //use
			printf("\n%s\n",fmtInfo(USE,argv[0]));
			break;
		case 4:
			debug=1;
			main_debug(argc,argv);
			break;
		default:
			break;
	}
}


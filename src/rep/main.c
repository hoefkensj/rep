#define _GNU_SOURCE
#include "headers/main.h"
#include "headers/parser.h"
#include "headers/escape.h"
#include "headers/info.h"
#include "headers/debug.h"
//--98765432109876543210
//hv-----r-nr---nrcfjspb
static void init(){
	opts.b="";	opts.p="";	opts.s="";	opts.j="";	opts.f="";	opts.c="";	opts.r="";	opts.n="";	args.n="";	args.r="";	num.a=0;	num.o=0;	num.c=0;
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
	if (err.flags!=0) runInfo(err.flags,argc,argv);
	err.pipe= read_stdin(STATUS);
	if (err.pipe>1) runInfo(0b100,argc,argv);

	err.parse = parse(argc,argv);
	// err.escape =	compile_strings();
	if(MANDATORY==0){
		printf("MISSING: <STRING> and <NUM>\n");
		runInfo(0b1000,argc,argv);
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
	printf("select: %i\n", select);
	for (int i=0;i<5;i++){
		if (select & (1<<i)) {
			switch(i){
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
	}
}


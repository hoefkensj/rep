#include "headers/main.h"




// Declaration of the array of pointers
static void esc(){
	opts.b=escape(opts.b);
	opts.p=escape(opts.p);
	opts.s=escape(opts.s);
	opts.j=escape(opts.j);
	opts.f=escape(opts.f);
	args.r=escape(args.r);
	opts.r=escape(opts.r);
	stdn.r=escape(stdn.r);
}
static void info(char exeName){
	UI32 lnBHelp;
	char bufHelp[lnBHelp];
	int lnBUse=strlen(strUse)+strlen(exeName)+1;
	char bufUse[lnBUse];
	char bufAb[100];
	lnBHelp=strlen(strHelp)+strlen(exeName)+1;
	if (STATUS[31]){
			print(about(bufAb));
	} else if(STATUS[30]){
			print(help(bufHelp,exeName));
	} else if (STATUS[29]) {
		print(use(bufUse,exeName));
	}
}


int main(int argc, char *argv[]) {
	UI32 status = 0;
	printf("starting...");

	status=parse(argc,argv);
	printf("parsed...");

	if (status+1 == 0) goto LAST;
	esc();
	printf("escaped...");
	repeat();
	printf("repeated...");


LAST:
	if (STATUS[29],STATUS[30]|STATUS[31]){
		info(*argv[0]);
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

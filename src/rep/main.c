#include "headers/main.h"

int main(int argc, char *argv[]) {
	// UI32 argStat[8]={[0 ... 7]=0};
	opts.b = "";
	opts.p = "";
	opts.s = "";
	opts.j = "";
	opts.f = "";
	args.n = 2;
	UI32 status=0;
	char *pArgv[argc];
	for (int i=0;i < argc ; i++){
		pArgv[i]=argv[i];
	}
	if (!isatty(fileno(stdin))){
		status=readPipe(&args);
		if (! (status==1))return status;
		STATUS[8]=status;
	}//fi
	status=parseOpts(argc,pArgv,&opts);
	for (int i=0;i<5;i++){
		STATUS[i] = status & (1<<i) ? 0 :1;
	}

	repeat();
	return 0;
}//main

void repeat(){

	UI32 n;
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


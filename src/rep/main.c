#include "headers/main.h"





void repeat(){
	UI32 n;
	print( escape(opts.b) );
	for ( n= args.n ; n >  0 ; n--) {
		print(opts.p);
		print(args.r );
		print(opts.s);
		if ( n > 1 ){
			print(opts.j);
		}//fi
	} // for
	print(opts.f);
	// void *dbgDat[8]={&args.n,&args.w,args.b,args.p,args.r,args.s,args.c,args.e};
	// debug(0,*dbgDat);

}//repeat






int main(int argc, char *argv[]) {
	// UI32 argStat[8]={[0 ... 7]=0};
	opts.b = NULL;
	opts.p = NULL;
	opts.s = NULL;
	opts.j = NULL;
	opts.f = NULL;
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

void debug(char *fmt,char *str){
	if (DEBUG){
		printf(fmt,str);
	}//fi
}//debug

void print(char *str){	printf("%s",str);}


#include "headers/main.h"





int main(int argc, char *argv[]) {
	printf("starting...");

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
	if (STATUS[29]|STATUS[30]|STATUS[31]){
		info(*argv[0]);
	}
	return status;
}//main

void repeat(){
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

void esc(){
	opts.b=escape(opts.b);
	opts.p=escape(opts.p);
	opts.s=escape(opts.s);
	opts.j=escape(opts.j);
	opts.f=escape(opts.f);
	args.r=escape(args.r);
	opts.r=escape(opts.r);
	stdn.r=escape(stdn.r);
}
void info(char exeName){
	UI32 lnBHelp;
	char bufHelp[lnBHelp];
	UI32 lnBUse=strlen(strUse)+strlen(&exeName)+1;
	char bufUse[lnBUse];
	char bufAb[100];
	lnBHelp=strlen(strHelp)+strlen(&exeName)+1;
	if (STATUS[31]){
		printf("\n%s\n",about(bufAb));
	} else if(STATUS[30]){
		printf("\n%s\n",help(bufHelp,&exeName));
	} else if (STATUS[29]) {
		printf("\n%s\n",use(bufUse,&exeName));
	}
}

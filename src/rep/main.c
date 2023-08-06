#include "headers/main.h"
#define ARGSPRINT "\
num:\t%i\n\
col:\t%i\n\
bgn:\t%s\n\
pfx:\t%s\n\
rep:\t%s\n\
sfx:\t%s\n\
cat:\t%s\n\
end:\t%s\n\
"

int main(int argc, char *argv[]) {

	UI32 return_code = 0;
	args.num = 0;
	args.col = 0;
	args.bgn = "";
	args.pfx = "";
	args.rep = NULL;
	args.sfx = "";
	args.cat = "";
	args.end = "";


	if (!isatty(fileno(stdin))){
		return_code=readPipe(&args,return_code);
		printf("b:%s\tp:%s\n",args.bgn,args.pfx) ;
	}
	return_code=parseArgs(argc,argv,&args,return_code);
	printf(ARGSPRINT, args.num,args.col,args.bgn,args.pfx,args.rep,args.sfx,args.cat,args.end);


	if (return_code & (1<<29)){
		free(args.rep);
	}
	return return_code;
}//main


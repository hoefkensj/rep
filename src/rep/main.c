#define _GNU_SOURCE
#include "headers/main.h"
#include "headers/parser.h"
#include "headers/escape.h"
#include "headers/info.h"
//--98765432109876543210
//hv-----r-nr---nrcfjspb
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
	num.o=atol(opts.n);
	num.a=atol(args.n);
	return done;
}

int main(int argc, char *argv[]) {
	opts.b="";	opts.p="";	opts.s="";	opts.j="";	opts.f="";	opts.c="";	opts.r="";	opts.n="";	args.n="";	args.r="";	num.a=0;	num.o=0;	num.c=0;

	err.flags = check_flags(argc,argv,STATUS);
	if (err.flags!=0) runInfo(err.flags,argc,argv);

	err.pipe= read_stdin(STATUS);
	if (err.pipe>1) runInfo(0b100,argc,argv);

	err.parse = parse(argc,argv);
	err.escape =	compile_strings();

	char *b, *p, *s, *f, *j, *r;
	UI32 n = num.a+num.o;
	b=opts.b;
	p=opts.p;
	s=opts.s;
	f=opts.f;
	j=opts.j;
	if (STATUS[6]) r = opts.r;
	else if (STATUS[11]) r= args.r ;
	else if (STATUS[14]) r= stdn.r ;
	err.repeat = repeat(n,b,p,s,f,j,r);
	return 0;
}//main

UI32 repeat(UI32 n,char *b,char *p,char *s,char *f,char *j, char *r){
	printf("%s",b);
	for ( int i=n ; i >  0 ; i--) {
		printf("%s",p);
		printf("%s",r);
		printf("%s",s);
		if ( i > 1 ){
			printf("%s",j);
		}//fi
	} // for
	printf("%s",f);
	return 0;
}//repeat



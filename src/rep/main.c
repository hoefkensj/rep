#define _GNU_SOURCE

#include "headers/parser.h"
#include "headers/escape.h"
#include "headers/pipe.h"
#include "headers/envvar.h"
#include "headers/main.h"
//--98765432109876543210
//hv-----r-nr---nrcfjspb
static UI32 compile_strings(PARTS *opts,PARTS *args,PARTS *stdn,PARTS *envv,NUM *num){
	UI32 done = 0;
	for (int i=0;i<32;i++){
		if(Flag(get,i)==1){
			done ++ ;
			switch(i){
				case 0:		repl_unescape(opts->r);break;
				case 2:		repl_unescape(opts->b);break;
				case 3:		repl_unescape(opts->p);break;
				case 4:		repl_unescape(opts->s);break;
				case 5:		repl_unescape(opts->j);break;
				case 6:		repl_unescape(opts->f);break;
				case 11:	repl_unescape(args->r);break;
				case 14:	repl_unescape(stdn->r);break;
				case 16:	repl_unescape(envv->r);break;
				case 17:	repl_unescape(envv->b);break;
				case 18:	repl_unescape(envv->p);break;
				case 19:	repl_unescape(envv->s);break;
				case 20:	repl_unescape(envv->j);break;
				case 21:	repl_unescape(envv->f);break;
			}
		}
	}
	num->o=atol(opts->n);
	num->a=atol(args->n);
	num->e=atol(envv->n);
	return done;
}

int main(int argc, char *argv[]) {
	PARTS *popts=malloc(sizeof(PARTS));
	PARTS *pargs=malloc(sizeof(PARTS));
	PARTS *penvv=malloc(sizeof(PARTS));
	PARTS *pstdn=malloc(sizeof(PARTS));
	NUM *pnum=malloc(sizeof(NUM));
	PARTS   opts=*popts;
	PARTS   args=*pargs;
	PARTS   envv=*penvv;
	PARTS   stdn=*pstdn;
	NUM     num=*pnum;
	// opts.b="";	opts.p="";	opts.s="";	opts.j="";	opts.f="";	opts.c="";	opts.r="";	opts.n="";	args.n="";	args.r="";	num.a=0;	num.o=0;	num.e=0; num.c=0;
	// envv.b="";	envv.p="";	envv.s="";	envv.j="";	envv.f="";	envv.c="";	envv.r="";	envv.n="";

	err.flags = check_flags(argc,argv);
	if (err.flags!=0) runInfo(err.flags,argc,argv);

	err.pipe= read_stdin(pstdn);
	if (err.pipe==1) Flag(set,I+Repeat);
	else if (err.pipe==2) runInfo(0b100,argc,argv);

	err.envv= readEnv(&envv);

	err.parse = parse(argc,argv,popts,pargs);
	if (!Flag(get,F+NoEscape)){
		err.escape =	compile_strings(popts,pargs,pstdn,penvv,pnum);
	}
	char *b = Flag(get, O + Begin) ? opts.b : (Flag(get, E + Begin) ? envv.b : "");
	char *p = Flag(get, O + Prefix) ? opts.p : (Flag(get, E + Prefix) ? envv.p : "");
	char *s = Flag(get, O + Suffix) ? opts.s : (Flag(get, E + Suffix) ? envv.s : "");
	char *f = Flag(get, O + Final) ? opts.f : (Flag(get, E + Final) ? envv.f : "");
	char *j = Flag(get, O + Join) ? opts.j : (Flag(get, E + Join) ? envv.j : "");
	UI32 n = Flag(get, A + Number) ? num.a : (Flag(get, O + Number) ? num.o : (Flag(get, E + Number) ? num.e : 1));
	char *r = Flag(get, I + Repeat) ? stdn.r : (Flag(get, A + Repeat) ? args.r : (Flag(get, O + Repeat) ? opts.r : (Flag(get, E + Repeat) ? envv.r : "")));


	err.repeat = repeat(n,b,p,s,f,j,r);
	free(stdn.r);
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



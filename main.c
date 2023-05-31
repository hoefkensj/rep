#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HELP (char *)"\
USAGE: %s <string> <int> [<start> <sep> <end>]\n\
       Prints <string> ,<int> times to stdout\n\
\n\
DOCS:  Strings are printed literally in order for the string to be interpreted\n\
       by the shell or the terminal eg for \\n=newline,\\t=tab,ANSI escapes)\n\
       run inside a subshell,and print using a native function like printf,...\n\
       SHELL variables however are expanded beforehand by the shell and are as\n\
       such passed to the program. SEE Examples for more info\n\
\n\
ARGS:\n\
    <STRING>          String to repeat.\n\
\n\
    <INT>             Number of times to repeat the <STRING>.\n\
\n\
    OPTIONAL:         If one is suplied all 3 are required !\n\
\n\
        <start>           String to print before the repeated series (will be printed only once).\n\
        <sep>             String to use as separator inbetween repeats.\n\
        <end>             String to print after the repeated series (will be printed only once).\n\
\n\
EXAMPLES:\n\
\n\
  <exe> <string>    <int>    <start>    <sep>    <end>    Result:\n\
%s     '#'         5                                      #####\n\
%s     '----'      2        '#'        '+'     '#\\n'   #----+----#\n\n\
%s     '-'         5        '|'        ''      '>'        |----->\n\
printf \"$(%s '\x1b[5A|' 2)\"                          |     |      \n\
"

void print_usage(char* name) {
	printf(HELP,name,name,name,name,name);
}

void rep( char* str,	char* strn ){
	unsigned long int n = atoll(strn);
	for (int i = 0; i < n; i++) {
		printf("%s", str);
  }
}
void wrapstr( char* argv[] ){
	char *string  = argv[1];
	char *sep     = argv[4];
	int sstring   = strlen(string);
	int ssep      = strlen(sep);
	int sstr      = sstring+ssep;
	char str[sstr];
	sprintf(str,"%s%s",string,sep);
	argv[1]= str;
	printf("%s",argv[3]);
	rep(str,argv[2]);
	printf("%s",string);
	printf("%s",argv[5]);
}

int main(int argc, char* argv[]) {
	int return_code = 0;
	if (!((argc == 3) | (argc == 6))){
		return_code= 1;
	} else if (argc == 3){
		rep(argv[1],argv[2]);
	} else if (argc == 6){
		wrapstr(argv);
	} else {
		printf("%s\n","something went terribly wrong, or faulty arguments supplied");
		return_code=1;
	}

	if (return_code == 1)	print_usage(argv[0]);
	return return_code;
}

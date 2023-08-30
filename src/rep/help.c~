		`	`	W`	W	 `21Q`12QW `1`2	EWQ	QASA#include "headers/help.h"

#define USAGE "\
USAGE:  %s  <string> <int> [-o,--option <string>] )\n\
        USE -h or --help for more info\n\
"

#define HELP "\
USAGE:  %s <rep> <int> [-o,--option <str>]\n\
        Prints <rep> <int> times to stdout.\n\
\n\
ARGS:\n\
\n\
    <rep>             String to repeat.\n\
    <int>             Number of times to repeat <rep>.\n\
\n\
OPTIONS:\n\
\n\
    -h, --help        Show this help message and exit.\n\
    -p, --pfx <str>   Prefix, this string will be printed before the first <rep>.\n\
    -s, --sfx <str>   Suffix, this string will be printed after the last <rep>\n\
    -c, --cat <str>   Concat, this string will be printed in between every two <rep> \n\
    -v, --version     Show Version,About\n\
\n\
DOCS:\n\
  Strings in arguments or options may contain the following escape codes:\n\
  \\                       Backslash\n\
  \\a                      Alarm,Terminal Bell\n\
  \\b                      Backspace\n\
  \\f                      FormFeed\n\
  \\n                      NewLine\n\
  \\t                      Horizontal TAB\n\
  \\v                      Vertical TAB\n\
  \\r                      Carriage Return\n\
  \\[0-7]{1,2,3}           Octal value (0-377)\n\
  \\x[0-F]{2}              Hexadecimal value (BYTE)\n\
  \\u                      Unicode (0000-FFFF)\n\
  \\U                      Unicode (00000000-FFFFFFFF)\n\
\n\
  This includes ANSI escape codes wich can be included using Octal(\\033) or Hexadecimal (\\x1b) escape codes.\n\
  All Arguments support output from a subshell and the program can be run in one.\n\
  This supports outputting to arguments of printf, or to the programs own arguments.\n\
  \n\
\n\
"
char *strUsage=USAGE;
// char *strAbout=ABOUT;
char *strHelp=HELP;

char *about(char *strAbout){
	// char *keyval[];
	char *mask="\x1b[%iG%s:\x1b[%iG%s%s";
	char *kv="                                 ";
	char *aAb[6]={kv,kv,kv,kv,kv,kv};

	printf(mask,0  ,"VERSION" ,12 ,VERSION,"");
	printf(mask,42 ,"DATE   " ,54 ,DATE   ,"\n");
	printf(mask,0  ,"GIT    " ,12 ,GITHUB,"");
	printf(mask,42 ,"REPO   " ,54 ,REPO   ,"\n");
	printf(mask,0  ,"AUTHORS" ,12 ,AUTHOR,"");
	printf(mask,42 ,"LICENSE" ,54 ,LICENSE   ,"\n");
	printf(strAbout,"%s%s%s%s%s%s",aAb[0],aAb[1],aAb[2],aAb[3],aAb[4],aAb[5]);
	// printf("%i",(int) strlen(strAbout));
	return strAbout;
}

char *help(char *strInfo,char *exeName){
	sprintf(strInfo,strHelp,exeName);
	return strInfo;
}
char *use(char *strInfo,char *exeName){
	sprintf(strInfo,strUsage,exeName);
	return strInfo;
}

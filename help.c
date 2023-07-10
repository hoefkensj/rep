#include "help.h"
#define USAGE (char *) "\
USAGE: %s <string> <int> (-[p|c|s] --[pfx|cat|sfx]] <string> )\n\
USE -h or --help for more info"


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
Result:                  Command: <exe> <string> <int> <start> <sep> <end>\n\
\n\
    ###########              %s '#' 11\n\
    #----+----#\\n           %s '----' 2 '#' '+' '#\\n'\n\
    |=========>              %s '=' 9 '|' '' '>'\n\
    |     |                  printf \"$( %s '\x1b[5C|' 2)\"\n\
"
void print_usage(char* name) {
	printf(USAGE,name);
}
void print_help(char* name) {
	printf(HELP,name,name,name,name,name);
}

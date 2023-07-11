#include "help.h"
#define USAGE (char *) "\
USAGE: %s  <string> <int> [-o,--option] <string> )\n\
USE -h or --help for more info"


#define HELP (char *)"\
USAGE: %s <string> <int> [-o,--option] <string>\n\
			 Prints <string> <int> times to stdout prefixed|suffixed|concatenated with <pfx>|<sfx>|<cat>\n\
\n\
DOCS:  The stings can contain escape's : \\[r|n|t|v|a|0-9|x[0-F][0-F]'\n\
       these will be converted to their respective byte values and printed as such\n\
       the string and int are mandatory but can be 0(int), ""(string):not printed,for\n\
       int=1 the --cat string will not be printed. should be compatible to use within\n\
			 bash  printf, and supports recursing or nesting subshells.\n\
\n\
ARGS:\n\
    <STRING>          String to repeat.\n\
\n\
    <INT>             Number of times to repeat the <STRING>.\n\
\n\
OPTIONS:\n\
\n\
    -h, --help        Show this help message and exit.\n\
    -p, --pfx         <pfx>:<str>    Prefix, this string will be printed first, before the repeated sequence.\n\
    -s, --sfx         <sfx>:<str>    Suffix, this string will be printed last, after the repeated sequence\n\
    -c, --cat         <cat>:<str>    Concat, this string will be printed in between the repeated sequence \n\
\n\
\n\
EXAMPLES:\n\
\n\
    COMMAND: <exe> <string> <int> [-o,--option] <string>   \n\
\n\
$%s '#' 11                                \n\
$%s '----' 2 -p 't1\t#' -c '+' -s '#'     \n\
\n\
\n\
AUTHOR:               %s                 MAIL:                %s\n\
VERSION:              %s                 DATE:                %s\n\
GITHUB:               %s                 REPO:                %s\n\
LICENSE:              %s\n\
\n\
\n\
"
void print_usage(char* name) {
	printf(USAGE,name);
}
void print_help(char* name) {
	printf(HELP,name,name,name,AUTHOR,EMAIL,VERSION,DATE,GITHUB,REPO,LICENSE);
}

#define _GNU_SOURCE
static char *HELP ="\
USAGE:  %s <rep> <int> [-[o],--[option] <str>]\n\
        prints <rep> , <int> times to output.\n\
        NOTE: See exaples for other uses.\n\
\n\
DESCRIPTION:\n\
        this program wil print a string n times to its output. the string that will be printed can be modified\n\
        with options, the format is : <begin>[[(<prefix<string><suffix>)+(<join>)]*n]<final>\n\
        all strings will be escaped before printing see ESCAPES for more info.\n\
\n\
ARGS:\n\
\n\
    <rep>             String to repeat.\n\
                        same as : \n\
                          - piped from stdin \n\
                          - passed with --repeat option \n\
                        NOTE: defaults to empty string : ''\n\
\n\
    <int>             Number of times to repeat <rep>.\n\
                        same as :\n\
                          - passed with --number option \n\
                        NOTE: defaults to '0' \n\
\n\
OPTIONS:\n\
\n\
    -h. -?, --help                   Show this help message and exit.\n\
\n\
    -b, --bgn,  --begin  <str>       Prefix, this string will be printed before the repeated sequence.\n\
    -f, --fin,  --final  <str>       Suffix, this string will be printed after the repeated sequence.\n\
\n\
    -p, --pre,  --prefix <str>       Concat, this string will be printed in between every two <rep> \n\
    -s, --suf,  --suffix <str>       Concat, this string will be printed in between every two <rep> \n\
\n\
    -j, --cat,  --join   <str>       Concat, this string will be printed in between every two <rep> \n\
    -r, --rep,  --repeat <str>       Concat, this string will be printed in between every two <rep> \n\
\n\
    -v, --version                    Show Version,About\n\
\n\
ESCAPES:\n\
  Strings in arguments or options may contain the following escape codes:\n\
  \\                       Backslash\n\
  \\a                      Alarm,Terminal Bell\n\
  \\b                      Backspace\n\
  \\f                      FormFeed\n\
  \\n                      NewLine\n\
  \\t                      Horizontal TAB\n\
  \\v                      Vertical TAB\n\
  \\r                      Carriage Return\n\
  \\o[0-7]{1,2,3}          Octal value (0-377)\n\
  \\O[0-7]{1,2,3}          Octal value (0-377)\n\
  \\[0-7]{1,2,3}           Octal value (0-377)\n\
  \\x[0-F]{2}              Hexadecimal value (BYTE)\n\
  \\X[0-F]{2}              Hexadecimal value (BYTE)\n\
  \\u                      Unicode (0000-FFFF)\n\
  \\U                      Unicode (00000000-FFFFFFFF)\n\
\n\
  This includes ANSI escape codes wich can be included using Octal(\\033) or Hexadecimal (\\x1b) escape codes.\n\
  All Arguments support output from a subshell and the program can be run in one.\n\
  This supports outputting to arguments of printf, or to the programs own arguments.\n\
  \n\
\n\
";

static char *USE ="\
USAGE:  %s  <string> <int> [-o,--option <string>] )\n\
        USE -h or --help for more info\n\
";

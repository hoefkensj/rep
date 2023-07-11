# rep
the missing bash core utility, repeats a given string n times to stdout.
USAGE: %s <string> <int> [-o,--option] <string>
			 Prints <string> <int> times to stdout prefixed|suffixed|concatenated with <pfx>|<sfx>|<cat>

DOCS:  The stings can contain escape's : \\[r|n|t|v|a|0-9|x[0-F][0-F]'
       these will be converted to their respective byte values and printed as such
       the string and int are mandatory but can be 0(int), ""(string):not printed,for
       int=1 the --cat string will not be printed. should be compatible to use within
			 bash  printf, and supports recursing or nesting subshells.

ARGS:
    <STRING>          String to repeat.

    <INT>             Number of times to repeat the <STRING>.

OPTIONS:

    -h, --help        Show this help message and exit.
    -p, --pfx         <pfx>:<str>    Prefix, this string will be printed first, before the repeated sequence.
    -s, --sfx         <sfx>:<str>    Suffix, this string will be printed last, after the repeated sequence
    -c, --cat         <cat>:<str>    Concat, this string will be printed in between the repeated sequence 


EXAMPLES:

    COMMAND: <exe> <string> <int> [-o,--option] <string>   

$%s '#' 11                                
$%s '----' 2 -p 't1\t#' -c '+' -s '#'     


AUTHOR:               %s                 MAIL:                %s
VERSION:              %s                 DATE:                %s
GITHUB:               %s                 REPO:                %s
LICENSE:              %s


"s                 DATE:                %s\n\
GITHUB:               %s                 REPO:                %s\n\
LICENSE:              %s\n\
\n\
\n\
"

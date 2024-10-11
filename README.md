# rep
	the missing bash core utility, repeat text (n times) using patterns to prefix join and suffix everything to stdout.
## Features:
	* support for escapes:
		| `\a            Alarm,Terminal Bell`         | `\`                Backslash`           |
		| `\t            Horizontal TAB`              | `\f`               FormFeed`            |
		| `\v            Vertical TAB`                | `\b`               Backspace`           |
		| `\x[0-F]{2}    Hexadecimal value (BYTE)`    | `\n`               NewLine`             |
		| `\X[0-F]{2}    Hexadecimal value (BYTE)`    | `\r`               Carriage Return`     |
		| `\u            Unicode (0000-FFFF)`         | `\o[0-7]{1,2,3}`   Octal value (0-377)` |
		| `\U            Unicode (00000000-FFFFFFFF)` | `\O[0-7]{1,2,3}`   Octal value (0-377)` |
  
	* setting a start , prefix , join , suffix , final - string using arguments, options or env variables
	* reading the repeat string from stdin, env argument or option
	* maximum number of iterations :  `18 199 999 078 727 679`
 	* maximum number of output characters:  `Unknown`

## INSTALLATION :
### LINUX (binary):
	```bash
	wget -c https://github.com/hoefkensj/rep/releases/download/v0.99/rep
 	su -c 'mv rep /usr/bin/'
  	rep --help
	```

### WINDOWS (binary):
	```pwsh
	WGET https://github.com/hoefkensj/rep/releases/download/v0.99/rep.exe
	# (as administrator)
 	copy rep.exe c:\windows\system32\
	rep --help
	 ```

## BUILDING FROM SOURCE:

### LINUX (requires GCC)
	```
	git clone https://github.com/hoefkensj/rep
	cd rep
	make
	make install
	rep --help
	```

### WINDOWS: (requires the zig compiler : https://ziglang.org/download/)
	```
	git clone https://github.com/hoefkensj/rep
	cd rep
	make win
	cd build/bin/
 	copy rep.exe c:\windows\system32\
	rep --help
	```

# HELP :
USAGE:  %s <rep> <int> [-[o],--[option] <str>]
        prints <rep> , <int> times to output.
        NOTE: See exaples for other uses.

DESCRIPTION:
        this program wil print a string n times to its output. the string that will be printed can be modified
        with options, the format is : <begin>[[(<prefix<string><suffix>)+(<join>)]*n]<final>
        all strings will be escaped before printing see ESCAPES for more info.


ARGS:

    <rep>             String to repeat.
                        same as :
                          - piped from stdin
                          - passed with --repeat option
                        NOTE: defaults to empty string : ''

    <int>             Number of times to repeat <rep>.
                        same as :
                          - passed with --number option
                        NOTE: defaults to '0'

OPTIONS:

    -h. -?, --help                   Show this help message and exit.

    -b, --bgn,  --begin  <str>       Prefix, this string will be printed before the repeated sequence.
    -f, --fin,  --final  <str>       Suffix, this string will be printed after the repeated sequence.

    -p, --pre,  --prefix <str>       Concat, this string will be printed in between every two <rep>
    -s, --suf,  --suffix <str>       Concat, this string will be printed in between every two <rep>

    -j, --cat,  --join   <str>       Concat, this string will be printed in between every two <rep>
    -r, --rep,  --repeat <str>       Concat, this string will be printed in between every two <rep>

    -v, --version                    Show Version,About

ESCAPES:
  Strings in arguments or options may contain the following escape codes:
  ```
  \\                       Backslash
  \\a                      Alarm,Terminal Bell
  \\b                      Backspace
  \\f                      FormFeed
  \\n                      NewLine
  \\t                      Horizontal TAB
  \\v                      Vertical TAB
  \\r                      Carriage Return
  \\o[0-7]{1,2,3}          Octal value (0-377)
  \\O[0-7]{1,2,3}          Octal value (0-377)
  \\[0-7]{1,2,3}           Octal value (0-377)
  \\x[0-F]{2}              Hexadecimal value (BYTE)
  \\X[0-F]{2}              Hexadecimal value (BYTE)
  \\u                      Unicode (0000-FFFF)
  \\U                      Unicode (00000000-FFFFFFFF)
```
  This includes ANSI escape codes wich can be included using Octal(\\033) or Hexadecimal (\\x1b) escape codes.
  All Arguments support output from a subshell and the program can be run in one.
  This supports outputting to arguments of printf, or to the programs own arguments.


";

static char *USE ="\
USAGE:  %s  <string> <int> [-o,--option <string>] )
        USE -h or --help for more info
";


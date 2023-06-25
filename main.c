#include "main.h"

void rep(ARGS *args){
	unsigned long int n = args->n;
	char *string        = args->string;
	char *cat           = args->cat;
	if (n<2){
				printf("%s",string);
	} else {
		for (int i = 0; i < n; i++) {
			printf("%s",translate(string));
			if (i < (n-1)) {
				printf("%s", translate(cat));
			} // fi
		} // for
	} //fi
}

void print(ARGS *args){
	printf("%s",translate(args->pfx));
	rep(args);
	printf("%s",translate(args->sfx));
}

int parseArguments(int argc, char *argv[], ARGS *args) {
		int return_code = 0;
    args->string = NULL;
    args->pfx = "";
    args->sfx = "";
    args->cat = "";
    args->n = 0;

    int i;
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--pfx") == 0) {
            args->pfx = argv[++i];
        } else if (strcmp(argv[i], "--sfx") == 0) {
            args->sfx = argv[++i];
        } else if (strcmp(argv[i], "--cat") == 0) {
            args->cat = argv[++i];
        } else {
            if (args->string == NULL) {
                args->string = argv[i];
            } else {
                args->n = strtoul(argv[i], NULL, 10);
            }
        }
    }
	if ( args->n == 0){
		return_code=1;
	}
	return return_code;
}

// int main(int argc, char *argv[]) {
//     ARGS args;
//     return_code=parseArguments(argc, argv, &args);
//
//     printf("String: %s\n", args.string);
//     printf("n: %lu\n", args.n);
//     printf("pfx: %s\n", args.pfx);
//     printf("sfx: %s\n", args.sfx);
//     printf("cat: %s\n", args.cat);
//
//     return 0;
// }

int main(int argc, char **argv) {
	int return_code = 0;
	ARGS args;
  return_code=parseArguments(argc, argv, &args);
	print(&args);
	if (return_code == 1)	print_usage(argv[0]);
	return return_code;
}

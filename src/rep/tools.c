#define _GNU_SOURCE
#include "headers/tools.h"

void printbin(UI32 var){
	for (int i =31; i>=0; i--){
		printf("%s" ,(var&(1<<i))?"1":"0");
	}
	printf("\n");
}

UI32 Flag(UI32 action,UI32 flag){
    UI32 bit=0;
	switch (action){
		case 0:
			STATUS=STATUS&~(1<<flag);
			bit=Flag(get,flag);
			break;
		case 1:
			STATUS=STATUS|(1<<flag);
			bit=Flag(get,flag);
			break;
		case 2:
			bit=(STATUS&(1<<flag))?1:0;
			break;
	}

	return bit;
}

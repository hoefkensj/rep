#include "headers/tools.h"
#include "headers/info.h"
#include "locale_enUniversal.c"


static char *fmtInfo(char *strInfo ,char *exeName){
	char *bufUse=malloc(strlen(strInfo) + strlen(exeName) + 1);
	sprintf(bufUse,strInfo,exeName);
	return bufUse;
}
void runInfo(int select,int argc,char **argv){
	UI32 debug=0;
	for (int i=0;i<5;i++){
		if (select & (1<<i)) {
			printf("%d",i);
			switch(i){
				case 0: //use
					printf("\n%s\n",fmtInfo(USE,argv[0]));
					break;
				case 1: // about
					printf("\n%s\n",fmtInfo("%s ABOUT",argv[0]));
					break;
				case 2: //help
					printf("\n%s\n",fmtInfo(HELP,argv[0]));
					break;
				case 3:
					debug=1;
					break;
				default:
					break;
			}
		}
	}
}

void printbin(UI32 var){
	for (int i =31; i>=0; i--){
		printf("%s" ,(var&(1<<i))?"1":"0");
	}
	printf("\n");
}
UI32 STATUS=0;

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

#define _GNU_SOURCE
#include "headers/info.h"


static char *fmtInfo(char *strInfo ,char *exeName){
	char *bufUse=malloc(strlen(strInfo) + strlen(exeName) + 1);
	sprintf(bufUse,strInfo,exeName);
	return bufUse;
}
void runInfo(int select,int argc,char **argv){
	printf("select: %i\n", select);
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

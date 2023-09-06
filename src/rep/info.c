#define _GNU_SOURCE
#include "headers/info.h"
#include "headers/en-Universal.h"



char *help(char *strInfo,char *exeName){
	UI32 lnBHelp;
	char *strHelp=HELP;
	char bufHelp[lnBHelp];
	lnBHelp=strlen(strHelp)+strlen(exeName)+1;

	sprintf(strInfo,strHelp,exeName);
	return strInfo;
}

char *use(char *strInfo,char *exeName){
	UI32 lnBUse;
	char *strUse=USE;
	char bufUse[lnBUse];

	lnBUse=strlen(strUse)+strlen(exeName)+1;

	sprintf(strInfo,strUse,exeName);
	return strInfo;
}

void info(UI32 iInfo,char exeName){
	char *bufInfo;
	char bufAb[100];
	switch (iInfo){
		case 0:
			printf("\n%s\n","tmp");
		case 1:
			printf("\n%s\n",help(bufInfo,&exeName));
		case 2:
			printf("\n%s\n",use(bufInfo,&exeName));
	}
}

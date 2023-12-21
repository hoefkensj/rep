#define _GNU_SOURCE
#include "headers/about.h"
#define AUTHOR  "Hoefkens Jeroen      "
#define EMAIL   "Hoefkens.J@gmail.com "
#define GITHUB  "github.com/hoefkensj "
#define REPO    "rep                  "
#define VERSION "0.9                "
#define DATE    "2023.0.           "
#define LICENSE "MIT                  "
char *about(char *strAbout){
	char *mask="\x1b[%iG%s:\x1b[%iG%s%s";
	char *kv="                                 ";
	char *aAb[6]={kv,kv,kv,kv,kv,kv};

	printf(mask,0  ,"VERSION" ,12 ,VERSION,"");
	printf(mask,42 ,"DATE   " ,54 ,DATE   ,"\n");
	printf(mask,0  ,"GIT    " ,12 ,GITHUB,"");
	printf(mask,42 ,"REPO   " ,54 ,REPO   ,"\n");
	printf(mask,0  ,"AUTHORS" ,12 ,AUTHOR,"");
	printf(mask,42 ,"LICENSE" ,54 ,LICENSE   ,"\n");
	sprintf(strAbout,"%s%s%s%s%s%s",aAb[0],aAb[1],aAb[2],aAb[3],aAb[4],aAb[5]);
	return strAbout;
}

#include "translate.h"
// char *escape(char *string){
// 	unsigned int lnstr = strlen(string);
// 	char *pstr[lnstr];
// 	char cstring;
// 	char zstr[lnstr*2];
// 	unsigned int i,j,z;
// 	int nib,byte = 0;
//
// 	for (i = 0; i < lnstr; i++) {
// 		z=2*i;
// 		zstr[z]=string[i];
// 		zstr[z+1]=Z0;
// 		pstr[i]=&zstr[z];
// 	}
// 	char *cptr=pstr[0];
//
// 	for (int i = 0; i < lnstr; i++) {
// 		cstring=*cptr;
// 		j=i+1;
//
// 		if (cstring == '\\'){
// 			switch (*pstr[j]){
// 				case '\\':
// 					break;
// 				case 'r':
// 					*pstr[i] = '\r';
// 					*pstr[j]=Z0;
// 					break;
// 				case 'n':
// 					*pstr[i] = '\n';
// 					*pstr[j]=Z0;
// 					break;
// 				case 't':
// 					*pstr[i] = '\t';
// 					*pstr[j]=Z0;
// 					break;
// 				case 'v':
// 					*pstr[i] = '\v';
// 					*pstr[j]=Z0;
// 					break;
// 				case 'a':
// 					*pstr[i] = '\a';
// 					break;
// 				case 'x':
// 					sscanf(pstr[j+1],"%x",&nib);
// 					byte=16*nib;
// 					sscanf(pstr[i+3],"%x",&nib);
// 					byte=byte+nib;
// 					*pstr[j]=Z0;
// 					*pstr[j+1]=Z0;
// 					*pstr[i] = byte;
// 					break;
// 			}
// 		}//fi
// 		// byte=nib*16;s
// 		// *pstr[j+2]=Z0;
// 		// byte=byte+nib;
// 		// *pstr[i] = byte;
// 					// pstr[i+1]=&zstr[(i+3)*2];
// 			// break;
// 	cptr=pstr[i+1];
// 	}//done
// 	for (int i = 0; i < lnstr; i++){
// 		printf("%c",(int)*pstr[i]);
// 	}//done
// }
//


void escape(char *str,char *arstr[]){


	UI32 lnastr = strlen(str)+1;
	UI32 lnzstr =	lnastr*2;
	UI32 lnrstr =	lnastr;

	char *pstr[lnastr];
	char zstr[lnzstr];
	char rstr[lnastr];
	char val;
	UI32 i,j,k,l,zi,zj,zk,zl;
	UI32 o0,o1,o2,x0,x1;
	B c;

	for (int i = 0; i < lnastr; i++) {
		zstr[i*2] = str[i];
		zstr[(i*2)+1] = Z0;
		pstr[i]   = &zstr[i*2];
	}


	for (i = 0; i < lnastr; i++) {
							zi=i*2;
		j=i+1;		zj=j*2;
		k=i+2;		zk=k*2;
		l=i+3;		zl=l*2;
		if (zstr[zi] == '\\'){
			switch (str[j]){
				case '\\':
				break;
				case 'r':
					zstr[zi] = '\r';
					zstr[zj] = Z0;
					lnrstr--;
					break;
				case 'n':
					zstr[zi] = '\n';
					zstr[zj] = Z0;
					lnrstr--;
					break;
				case 't':
					zstr[zi] = '\t';
					zstr[zj] = Z0;
					lnrstr--;
					break;
				case 'v':
					zstr[zi] = '\v';
					zstr[zj] = Z0;
					lnrstr--;
					break;
				case 'a':
					zstr[zi] = '\a';
					zstr[zj] = Z0;
					lnrstr--;
					break;
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
					c = sscanf(&zstr[zj],"%o",&o0);
					if (c == 1){
						val=o0;
						c = sscanf(&zstr[zk],"%o",&o1);
						if (c == 1){
							val=(o0*8)+o1;
							if ( (0 <= o0) && (o0 < 4) ){
								c = sscanf( &zstr[zl] , "%o" , &o2 );
								if (c == 1 ){
									val=(o0*8*8)+(o1*8)+o2;
									zstr[zl] = Z0;
									lnrstr--;
								} //fi
								zstr[zj] = Z0;
								lnrstr--;
							} //fi
							zstr[zk] = Z0;
							lnrstr--;
						} //fi
						zstr[zi]=val;
					} //fi
					break;
				case 'x':
					c = sscanf(&zstr[zk],"%x",&x0);

					if (c == 1){
						c = sscanf(&zstr[zl],"%x",&x1);
							if (c == 1 ){
								zstr[zj]=Z0;
								val=(x0*16)+x1;
								zstr[zk]=Z0;
								lnrstr--;
								zstr[zl]=Z0;
								lnrstr--;
								zstr[zi]=val;


							} //fi
					}//fi
					break;
			}//switch


		}//fi
	}//done
	j=0;
	for (int i = 0; i < lnastr; i++) {
		if (*pstr[i] != Z0){
			rstr[j] = *pstr[i];
			j++;
		}
	}

	*arstr=rstr;

	return;
}


	// int               numlen;
	// printf("string: %s\n",string);
	// while (NULL!=(here=strchr(here,'\\'))){
	// 	switch (here[1]){
	// 		case '\\':
	// 			break;
	// 		case 'r':
	// 			here[0] = '\r';break;
	// 		case 'n':
	// 			here[0] = '\n';	return string;

 //
	// 		case 't':
	// 			*here = '\t';break;
	// 		case 'v':
	// 			*here = '\v';break;
	// 		case 'a':
	// 			*here = '\a';break;
 //
	// 		case '0':
	// 		case '1':
	// 		case '2':
	// 		case '3':
	// 		case '4':
	// 		case '5':
	// 		case '6':
	// 		case '7':
	// 			count = sscanf(here,"%o",&num);
	// 			printf("%i\n",count);
	// 			printf("%c\n",num);
	// 			printf("%i\n",num);
	// 			*here = (char)num;
	// 			break;
	// 		case 'x':
	// 			byte[0]=here[2];
	// 			byte[1]=here[3];
	// 			byte[2]='\0';
	// 			count = sscanf(byte,"%x",&num);
 //
	// 			printf("%i\n",count);
	// 			printf("%c\n",count);
	// 			printf("%x\n",count);
	// 			printf("%c\n",num);
	// 			printf("%i\n",num);
	// 			*here = (char)num;
 //
	// 			break;
	// 	}
	// 	num = here - string + count;
	// 	here++;
	// 	memmove(here,here+count,len-num );
	// }//done

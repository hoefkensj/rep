#include "headers/escape.h"





// char *escape(char *str,char arstr[]){
// 	UI32 lnstr  = strlen(str)+1;
// 	UI32 lnzstr =	lnstr*2;
//
// 	char *pstr[lnstr];
// 	char zstr[lnzstr];
// 	char val;
// 	UI32 a[16];
// 	UI32 z[16];
// 	UI32 x[16];
//
// 	UI32 i,j;
// 	UI32 o0,o1,o2;
// 	UI32 xval;
// 	// char *eval[]={'a','b','f',nNtvr01234567suUvxX'""'};
// 	for (int i = 0; i < lnstr; i++) {
// 		zstr[i*2] = str[i];
// 		zstr[(i*2)+1] = Z0;
// 		pstr[i]   = &zstr[i*2];
// 	}
//
//
//
// 	for (i = 0; i < lnstr; i++) {
// 		for (int b = 0; b < 16; b++) {
// 			a[b]=i+b;
// 			z[b]=2*a[b];
// 			printf("a[%i]= %i\n",b,a[b]);
// 			printf("z[%i]= %i\n",b,z[b]);
// 		}
//
//
// 		if (zstr[z[0]] == '\\'){
// 			switch (str[a[1]]){
// 				case '\\':					break;
// 				case '\'':					zstr[z[0]] = '\'';					zstr[z[1]] = Z0;					break;
// 				case '\"':					zstr[z[0]] = '\"';					zstr[z[1]] = Z0;					break;
// 				case 'a':					zstr[z[0]] = '\a';					zstr[z[1]] = Z0;					break;
// 				case 'b':					zstr[z[0]] = '\b';					zstr[z[1]] = Z0;					break;
// 				case 'f':					zstr[z[0]] = '\f';					zstr[z[1]] = Z0;					break;
// 				case 'n':					zstr[z[0]] = '\n';					zstr[z[1]] = Z0;					break;
// 				case 't':					zstr[z[0]] = '\t';					zstr[z[1]] = Z0;					break;
// 				case 'v':					zstr[z[0]] = '\v';					zstr[z[1]] = Z0;					break;
// 				case 'r':					zstr[z[0]] = '\r';					zstr[z[1]] = Z0;					break;
// 				case '0':
// 				case '1':
// 				case '2':
// 				case '3':
// 				case '4':
// 				case '5':
// 				case '6':
// 				case '7':
// 					if (sscanf(&zstr[z[1]],"%o",&o0) == 1){
// 						val=o0;
// 						if (sscanf(&zstr[z[2]],"%o",&o1) == 1){
// 							val=(o0*8)+o1;
// 							if ( (0 <= o0) && (o0 < 4) ){
// 								if ( sscanf(&zstr[z[3]], "%o", &o2) == 1 ){
// 									val=(o0*8*8)+(o1*8)+o2;
// 									zstr[z[3]] = Z0;
// 								} //fi
// 								zstr[z[2]] = Z0;
// 							} //fi
// 							zstr[z[1]] = Z0;
// 						} //fi
// 						zstr[z[0]]=val;
// 					} //fi
// 					break;
// 				case 'x':
// 				case 'X':
// 					if (
// 						( sscanf(&zstr[z[2]],"%x",&x[0]) == 1) &&
// 						( sscanf(&zstr[z[3]],"%x",&x[1]) == 1 )
// 					){
// 						zstr[z[1]]=Z0;
// 						zstr[z[2]]=Z0;
// 						zstr[z[3]]=Z0;
// 						zstr[z[0]]=(x[0] << 4)+x[1];
// 					} //fi
// 					break;
// 				case 'u':
// 					if (
// 						sscanf(&zstr[z[2]],"%x",&x[0]) &&
// 						sscanf(&zstr[z[3]],"%x",&x[1]) &&
// 						sscanf(&zstr[z[4]],"%x",&x[2]) &&
// 						sscanf(&zstr[z[5]],"%x",&x[3])
// 						) {
// 						for (int k=0; k<6;k++){
// 							zstr[z[k]] = Z0;
// 						}
// 						xval = 	( x[0] << 12 ) +
// 										( x[1] <<  8 ) +
// 										( x[2] <<  4 ) +#!/usr/bin/env bash

// 										x[3];
// 						if (xval <= 0x7F) {
// 							zstr[z[0]] = xval;
// 						} else if (xval <= 0x7FF) {
// 							zstr[z[0]] = 0xC0 | (xval >> 6);
// 							zstr[z[1]] = 0x80 | (xval & 0x3F);
// 						} else if (xval <= 0xFFFF) {
// 							zstr[z[0]] = 0xE0 | (xval >> 12);
// 							zstr[z[1]] = 0x80 | ((xval >> 6) & 0x3F);
// 							zstr[z[2]] = 0x80 | (xval & 0x3F);
// 						} else if (xval <= 0x10FFFF) {
// 							zstr[z[0]] = 0xF0 | (xval >> 18);
// 							zstr[z[1]] = 0x80 | ((xval >> 12) & 0x3F);
// 							zstr[z[2]] = 0x80 | ((xval >> 6) & 0x3F);
// 							zstr[z[3]] = 0x80 | (xval & 0x3F);
// 						} //fi
// 					} //fi
// 					break;
// 				case 'U':
// 					for (int k=2; k<9 ; k++){
// 						if ((zstr[z[k]] = Z0) || !sscanf(&zstr[z[k]],"%x",&x[k-2]) ){
// 							break;
// 						}//fi
// 						zstr[z[k]] = Z0;
// 					}//done
// 					xval = 	( x[0] << 28 ) +
// 									( x[1] << 24 ) +
// 									( x[2] << 20 ) +
// 									( x[3] << 16 ) +
// 									( x[4] << 12 ) +
// 									( x[5] <<  8 ) +
// 									( x[6] <<  4 ) +
// 										x[7];
// 					if (xval <= 0x7F) {
// 							zstr[z[0]] = xval;
// 					} else if (xval <= 0x7FF) {
// 							zstr[z[0]] = 0xC0 | (xval >> 6);
// 							zstr[z[1]] = 0x80 | (xval & 0x3F);
// 					} else if (xval <= 0xFFFF) {
// 							zstr[z[0]] = 0xE0 | (xval >> 12);
// 							zstr[z[1]] = 0x80 | ((xval >> 6) & 0x3F);
// 							zstr[z[2]] = 0x80 | (xval & 0x3F);
// 					} else if (xval <= 0x10FFFF) {
// 							zstr[z[0]] = 0xF0 | (xval >> 18);
// 							zstr[z[1]] = 0x80 | ((xval >> 12) & 0x3F);
// 							zstr[z[2]] = 0x80 | ((xval >> 6) & 0x3F);
// 							zstr[z[3]] = 0x80 | (xval & 0x3F);
// 					}//fi
// 					break;
// 			}//switch
// 		}//fi
// 	}//done
// 	for (i=0,j=0 ; i < lnstr; i++) {
// 		if (*pstr[i] != Z0){
// 			str[j] = *pstr[i];
// 			j++;
// 		}
// 	}
// 	str[j]=Z0;
// 	return str;
// }


char *escape(char *str){
	// printf("pointer: %p\tInt: %d\tchar: %c\tstring: %s\n",str,(int)str[0],str[0],str);
	UI32 lnstr  = strlen(str);
	char nstr[lnstr];
	char O[6] = {Z0,Z0,Z0,Z0,Z0,Z0};
	char X[8] = {Z0,Z0,Z0,Z0,Z0,Z0,Z0,Z0};
	UI32 o[3];
	UI32 x[8];
	UI32 i,j,idx ;
	i=0;j=0;
	for (i=0;i<lnstr;i++){

	// 	nstr[idx]=str[idx];
	// 	printf("%d", idx);
		if (str[i] == '\\'){
			switch (str[i+1]){
					case 'n':
						nstr[j] = '\n';
						j++;
						break;
			}
		}else{
			nstr[j]=str[i];
			j++;
		}
	// 		// switch (str[i+1]){
	// 				// case 'n':
	// 					// nstr[j++] = '\n';
	// 					// break;
	// 		// }
	// 	// }else{
	// 	// nstr[j++]=str[i];
	// 	// }
	// }
	// printf("i: %d\tJ: %d\tnew %s\tchar: %s\tstring: %s\n",i,j,&nstr[i],&str[i],str);
		// if (*pstr[i] == '\\'){
	}//done
	//done

	// char *eval[]={'a','b','f',ntvr01234567suUvxX'""'};
	// for (i = 0; i < lnstr; i++) pstr[i]  = &str[i];
 //
	// for (i = 0,j=0;i < lnstr; i++) {
	// 	printf("pointer: %p\tInt: %d\tchar: %c\tstring: %s\n",str,(int)str[i],str[i],str);
	// 	pstr[i] = &str[j++];
	// 	if (*pstr[i] == '\\'){
 //
	// 		switch (str[j]){
	// 			case '\\':                               break;
	// 			case '\'': *pstr[i] = '\''; pstr[++i]=&str[j++]; break;
	// 			case '\"': *pstr[i] = '\"'; pstr[++i]=&str[++j]; break;
	// 			case 'a':  *pstr[i] = '\a'; pstr[++i]=&str[++j]; break;
	// 			case 'b':  *pstr[i] = '\b'; pstr[++i]=&str[++j]; break;
	// 			case 'f':  *pstr[i] = '\f'; pstr[++i]=&str[++j]; break;
	// 			case 'n':  *pstr[i] = '\n'; pstr[++i]=&str[j+8]; break;
	// 			case 'o':
	// 			case 'O':
	// 				O[0] = str[i+2];
	// 				O[2] = str[i+3];
	// 				O[4] = str[i+4];
	// 				if ( sscanf( &O[0],"%o", &o[0] ) ){
	// 					str[i] = o[0];
	// 					if ( sscanf( &O[2],"%o", &o[1] ) ){
	// 						str[i] = (o[0]*8) + o[1];
	// 						if ( sscanf( &O[4],"%o", &o[2] ) ){
	// 							if (o[0] < 4 ){
	// 								str[i] = (o[0]*8*8) + (o[1]*8) + o[2];
	// 								str[i+3]=Z0;
	// 							}//fi
	// 						}//fi
	// 						str[i+2]=Z0;
	// 					}//fi
	// 					str[i+1]=Z0;
	// 				}//fi
	// 				break;
	// 			case 't':   *pstr[i] = '\t'; pstr[i++]=&str[j++]; break;
	// 			case 'v':   *pstr[i] = '\v'; pstr[i++]=&str[j++]; break;
	// 			case 'r':   *pstr[i] = '\r'; pstr[i++]=&str[j++]; break;
	// 			case 'x':
	// 			case 'X':
	// 				X[0] =str[i+2];
	// 				X[2] =str[i+3];
	// 				X[4] =str[i+4];
	// 				X[6] =str[i+5];	// for (i = 0,j=0;i < lnstr; i++) {
	// 	printf("pointer: %p\tInt: %d\tchar: %c\tstring: %s\n",str,(int)str[i],str[i],str);
	// 				if ( sscanf( &X[0],"%x", &x[0] ) ){
	// 					if ( sscanf( &X[2],"%x", &x[1] ) ){
	// 						str[i] = (x[0]*16) + (x[1]);
	// 						str[i++]=Z0;
	// 						str[i++]=Z0;
	// 						str[i++]=Z0;
	// 						if ( sscanf( &X[4],"%x", &x[2] ) ){
	// 							if ( sscanf( &X[6],"%x", &x[3] ) ){
	// 								str[i] = (x[0]*16*16*16) + (x[1]*16*16) + (x[2]*16) + (x[3]);
	// 								str[i++]=Z0;
	// 								str[i++]=Z0;
	// 							}//fi
	// 						}//fi
	// 					} //fi
	// 				} //fi
	// 				break;
	// 			case '0':
	// 			case '1':
	// 			case '2':
	// 			case '3':
	// 			case '4':
	// 			case '5':
	// 			case '6':
	// 			case '7':
	// 				O[0] = str[i+1];
	// 				O[2] = str[i+2];
	// 				O[4] = str[i+3];
	// 				if ( sscanf( &O[0],"%o", &o[0] ) ){
	// 					str[i] = o[0];
	// 					if ( sscanf( &O[2],"%o", &o[1] ) ){
	// 						str[i] = (o[0]*8) + o[1];
	// 						if ( sscanf( &O[4],"%o", &o[2] ) ){
	// 							if (o[0] < 4 ){
	// 								str[i] = (o[0]*8*8) + (o[1]*8) + o[2];
	// 								str[i+3]=Z0;
	// 							}//fi
	// 						}//fi
	// 						str[i+2]=Z0;
	// 					}//fi
	// 					str[i+1]=Z0;
	// 				}//fi
	// 				break;
	// 		}//switch
	// 	}//fi
 //
	// }//done

	// for (i=0,j=0 ; i < lnstr;i++) {
	// 	if (*pstr[i] == Z0) i++;
	// 	str[j++] = *pstr[i];
	// }//done
	// for (int k=j;k<i;k++){
	// 		str[k]=Z0;
	// }

	return str;
}


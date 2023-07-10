#include "escape.h"
char *escape(char *str,char arstr[]){
	UI32 lnstr  = strlen(str)+1;
	UI32 lnzstr =	lnstr*2;

	char *pstr[lnstr];
	char zstr[lnzstr];

	char val;
	UI32 i,j,k,l,zi,zj,zk,zl;
	UI32 o0,o1,o2,x0,x1;

	for (int i = 0; i < lnstr; i++) {
		zstr[i*2] = str[i];
		zstr[(i*2)+1] = Z0;
		pstr[i]   = &zstr[i*2];
	}


	for (i = 0; i < lnstr; i++) {
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
					break;
				case 'n':
					zstr[zi] = '\n';
					zstr[zj] = Z0;
					break;
				case 't':
					zstr[zi] = '\t';
					zstr[zj] = Z0;
					break;
				case 'v':
					zstr[zi] = '\v';
					zstr[zj] = Z0;
					break;
				case 'a':
					zstr[zi] = '\a';
					zstr[zj] = Z0;
					break;
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
					if (sscanf(&zstr[zj],"%o",&o0) == 1){
						val=o0;
						if (sscanf(&zstr[zk],"%o",&o1) == 1){
							val=(o0*8)+o1;
							if ( (0 <= o0) && (o0 < 4) ){
								if ( sscanf(&zstr[zl], "%o", &o2) == 1 ){
									val=(o0*8*8)+(o1*8)+o2;
									zstr[zl] = Z0;
								} //fi
								zstr[zk] = Z0;
							} //fi
							zstr[zj] = Z0;
						} //fi
						zstr[zi]=val;
					} //fi
					break;
				case 'x':
					if ((sscanf(&zstr[zk],"%x",&x0) == 1) && ( sscanf(&zstr[zl],"%x",&x1) == 1 )){
						zstr[zj]=Z0;
						zstr[zk]=Z0;
						zstr[zl]=Z0;
						zstr[zi]=(x0 << 4)+x1;
					} //fi
					break;
			}//switch
		}//fi
	}//done

	for (i=0,j=0; i < lnstr; i++) {
		if (*pstr[i] != Z0){
			str[j] = *pstr[i];
			j++;
		}
	}
	str[j]=Z0;
	return str;
}



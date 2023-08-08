#include "headers/escape.h"


static void octal(char str[], UI32 *i, UI32 *j, UI32 offset) {
	char O[6] = { Z0, Z0, Z0, Z0, Z0, Z0 };
	UI32 o[3];

	O[0] = str[*i + offset];
	O[2] = str[*i + offset+1];
	O[4] = str[*i + offset+2];
    if (sscanf(&O[0], "%o", &o[0])) {
        str[(*j)++] = o[0];
        if (sscanf(&O[2], "%o", &o[1])) {
            str[(*j) - 1] = (o[0] * 8) + o[1];
            if (sscanf(&O[4], "%o", &o[2])) {
                if (o[0] < 4) {
                    str[(*j) - 1] = (o[0] * 8 * 8) + (o[1] * 8) + o[2];
                    (*i)++;
                }//fi
            }//fi
            (*i)++;
        }//fi
        (*i)++;
    }//fi
}//octal
static void hex(char str[], UI32 *i, UI32 *j) {
    char X[8] = { Z0, Z0, Z0, Z0, Z0, Z0, Z0, Z0 };
    UI32 x[8];

    X[0] = str[*i + 2];
    X[2] = str[*i + 3];
    if (sscanf(&X[0], "%x", &x[0])) {
        if (sscanf(&X[2], "%x", &x[1])) {
            str[(*j)++] = (x[0] * 16) + (x[1]);
            X[4] = str[*i + 4];
            X[6] = str[*i + 5];
            if (sscanf(&X[4], "%x", &x[2])) {
                if (sscanf(&X[6], "%x", &x[3])) {
                    str[(*j) - 1] = (x[0] * 16 * 16 * 16) + (x[1] * 16 * 16) + (x[2] * 16) + (x[3]);
                    (*i) += 2;
                }//fi
            }//fi
            (*i) += 2;
        }//fi
        (*i)++;
    }//fi
}//hex
static void unicode4(char str[], UI32 *i, UI32 *j) {
	char U[8] = {Z0,Z0,Z0,Z0,Z0,Z0,Z0,Z0};
	UI32 x[8];
	UI32 xval;

					U[0]=str[*i+2];
					U[2]=str[*i+3];
					U[4]=str[*i+4];
					U[6]=str[*i+5];
					if (
						sscanf(&U[0],"%x",&x[0]) &&
						sscanf(&U[2],"%x",&x[1]) &&
						sscanf(&U[4],"%x",&x[2]) &&
						sscanf(&U[6],"%x",&x[3])
						) {
						i+=5;
						xval = 	( x[0] << 12 ) +
										( x[1] <<  8 ) +
										( x[2] <<  4 ) +
										( x[3] <<  0 );
						if (xval <= 0x7F) {
							str[*j++] = xval;
						} else if (xval <= 0x7FF) {
							str[*j++] = 0xC0 | ( xval >> 6);
							str[*j++] = 0x80 | ( xval        & 0x3F);
						} else if (xval <= 0xFFFF) {
							str[*j++] = 0xE0 | ( xval >> 12);
							str[*j++] = 0x80 | ((xval >> 6 ) & 0x3F);
							str[*j++] = 0x80 | ( xval        & 0x3F);
						} else if (xval <= 0x10FFFF) {
							str[*j++] = 0xF0 | ( xval >> 18);
							str[*j++] = 0x80 | ((xval >> 12) & 0x3F);
							str[*j++] = 0x80 | ((xval >> 6 ) & 0x3F);
							str[*j++] = 0x80 | ( xval        & 0x3F);
						} //fi
					} //fi
}//unicode4
static void unicode8(char str[], UI32 *i, UI32 *j) {
	char U[16] = {Z0,Z0,Z0,Z0,Z0,Z0,Z0,Z0,Z0,Z0,Z0,Z0,Z0,Z0,Z0,Z0};
	UI32 x[8];
	UI32 xval;
	U[0]=str[*i+2];		U[2]=str[*i+3];
	U[4]=str[*i+4];		U[6]=str[*i+5];
	U[8]=str[*i+6];		U[10]=str[*i+7];
	U[12]=str[*i+8];	U[14]=str[*i+9];
	if (
		sscanf(&U[0],"%x",&x[0])  &&	sscanf(&U[2],"%x",&x[1])  &&
		sscanf(&U[4],"%x",&x[2])  &&	sscanf(&U[6],"%x",&x[3])  &&
		sscanf(&U[8],"%x",&x[4])  &&	sscanf(&U[10],"%x",&x[5]) &&
		sscanf(&U[12],"%x",&x[6]) &&	sscanf(&U[14],"%x",&x[7])
		) {
		i+=9;
		xval = 	( x[0] <<  28 ) +		( x[1] <<  24 ) +
		( x[2] <<  20 ) +		( x[3] <<  16 ) +
		( x[4] <<  12 ) +		( x[5] <<  8 )  +
		( x[6] <<  4 )  +		( x[7] <<  0 );
		if (xval <= 0x7F) {
			str[*j++] = xval;
		} else if (xval <= 0x7FF) {
			str[*j++] = 0xC0 | ( xval >> 6);
			str[*j++] = 0x80 | ( xval        & 0x3F);
		} else if (xval <= 0xFFFF) {
			str[*j++] = 0xE0 | ( xval >> 12);
			str[*j++] = 0x80 | ((xval >> 6 ) & 0x3F);
			str[*j++] = 0x80 | ( xval        & 0x3F);
		} else if (xval <= 0x10FFFF) {
			str[*j++] = 0xF0 | ( xval >> 18);
			str[*j++] = 0x80 | ((xval >> 12) & 0x3F);
			str[*j++] = 0x80 | ((xval >> 6 ) & 0x3F);
			str[*j++] = 0x80 | ( xval        & 0x3F);
		} //fi
	} //fi
}//unicode8
char *escape(char str[]){
	UI32 lnstr  = strlen(str)+1;
	UI32 i,j;

	j=0;
	for (i=0;i<=lnstr;i++){
		if (str[i] == '\\'){
			switch (str[i+1]){
				case '\\':                           break;
				case '\'': str[j] = '\''; i=i+1;j++; break;
				case '\"': str[j] = '\"'; i=i+1;j++; break;
				case 'a' : str[j] = '\a'; i=i+1;j++; break;
				case 'b' : str[j] = '\b'; i=i+1;j++; break;
				case 'f' : str[j] = '\f'; i=i+1;j++; break;
				case 'n' : str[j] = '\n'; i=i+1;j++; break;
				case 'r' : str[j] = '\r'; i=i+1;j++; break;
				case 't' : str[j] = '\t'; i=i+1;j++; break;
				case 'v' : str[j] = '\v'; i=i+1;j++; break;
				case 'o':
				case 'O': octal(str, &i, &j, 2); break;
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7': octal(str, &i, &j, 1); break;
				case 'x':
				case 'X': hex(str, &i, &j); break;
				case 'u': unicode4(str, &i, &j); break;
				case 'U': unicode8(str, &i, &j) ;break;
			}//switch
		} else {
			str[j++]=str[i];
		} //fi
	}//done
  str[j] = Z0; // Null-terminate the modified string
  return str;
}

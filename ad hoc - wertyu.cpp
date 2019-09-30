#include <stdio.h>
#include <string.h>

int main(){
	
	char sent[10000];
	char temp;
	int i = 0;
	while(scanf("%c",&temp)!=EOF){
		sent[i]=temp;
		switch (sent[i]){
			case '1': sent[i]='`'; break;
			case '2': sent[i]='1'; break;
			case '3': sent[i]='2'; break;
			case '4': sent[i]='3'; break;
			case '5': sent[i]='4'; break;
			case '6': sent[i]='5'; break;
			case '7': sent[i]='6'; break;
			case '8': sent[i]='7'; break;
			case '9': sent[i]='8'; break;
			case '0': sent[i]='9'; break;
			case '-': sent[i]='0'; break;
			case '=': sent[i]='-'; break;
			case 'w': sent[i]='q'; break;
			case 'W': sent[i]='Q'; break;
			case 'e': sent[i]='w'; break;
			case 'E': sent[i]='W'; break;
			case 'r': sent[i]='e'; break;
			case 'R': sent[i]='E'; break;
			case 't': sent[i]='r'; break;
			case 'T': sent[i]='R'; break;
			case 'y': sent[i]='t'; break;
			case 'Y': sent[i]='T'; break;
			case 'u': sent[i]='y'; break;
			case 'U': sent[i]='Y'; break;
			case 'i': sent[i]='u'; break;
			case 'I': sent[i]='U'; break;
			case 'o': sent[i]='i'; break;
			case 'O': sent[i]='I'; break;
			case 'p': sent[i]='o'; break;
			case 'P': sent[i]='O'; break;	
			case '[': sent[i]='P'; break;
			case '{': sent[i]='P'; break;
			case ']': sent[i]='['; break;
			case '}': sent[i]='{'; break;
			case '\\': sent[i]=']'; break;
			case '|': sent[i]='}'; break;
			case 's': sent[i]='a'; break;
			case 'S': sent[i]='A'; break;
			case 'd': sent[i]='s'; break;
			case 'D': sent[i]='S'; break;
			case 'f': sent[i]='d'; break;
			case 'F': sent[i]='D'; break;
			case 'g': sent[i]='f'; break;
			case 'G': sent[i]='F'; break;
			case 'h': sent[i]='g'; break;
			case 'H': sent[i]='G'; break;
			case 'j': sent[i]='h'; break;
			case 'J': sent[i]='H'; break;
			case 'k': sent[i]='j'; break;
			case 'K': sent[i]='J'; break;
			case 'l': sent[i]='k'; break;
			case 'L': sent[i]='K'; break;
			case ';': sent[i]='L'; break;
			case ':': sent[i]='L'; break;
			case '\'': sent[i]=';'; break;
			case 'x': sent[i]='z'; break;
			case 'X': sent[i]='Z'; break;
			case 'c': sent[i]='x'; break;
			case 'C': sent[i]='X'; break;
			case 'v': sent[i]='c'; break;
			case 'V': sent[i]='C'; break;
			case 'b': sent[i]='v'; break;
			case 'B': sent[i]='V'; break;
			case 'n': sent[i]='b'; break;
			case 'N': sent[i]='B'; break;
			case 'm': sent[i]='n'; break;
			case 'M': sent[i]='N'; break;
			case ',': sent[i]='M'; break;
			case '<': sent[i]='M'; break;
			case '.': sent[i]=','; break;
			case '>': sent[i]='<'; break;
			case '/': sent[i]='.'; break;
			case '?': sent[i]='<'; break;
			case ' ': break;
		}
		i++;
	}
	printf("%s",sent);
	
	getchar();
	return 0;
}

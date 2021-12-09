#include <stdio.h>
#include <string.h>

void r_print(char* pch);
// pch: pointer to the beginning of the string

int main(void) {
	char str[80];

	printf("Enter a string >> ");
	fgets(str, 80, stdin);
	str[strlen(str)-1]='\0';

  r_print(str);
	printf("\n");

  return 0;
}

void r_print(char* pch){
	if((int)strlen(pch) <=0) return;
	else if((int)strlen(pch) < 2){
		char c = *pch;
		if(c >= 'a' && c<='z')
			c = 'A' + (c - 'a');
			printf("%c", c);
	}
	else{
		r_print(pch+2);

		char c1 = *(pch);
		if(c1 >= 'a' && c1<='z')
			c1 = 'A' + (c1 - 'a');
		char c2 = *(pch+1);
		if(c2 >= 'a' && c2<='z')
			c2 = 'A' + (c2 - 'a');

		printf("%c%c", c1, c2);
	}
}

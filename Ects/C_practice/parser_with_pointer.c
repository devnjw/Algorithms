#include <stdio.h>
#include <string.h>

int r_strlen(char* str);

int main(void) {
	char line[100];
	printf("Enter a string > ");
	fgets(line, 100, stdin);
	printf("length : %d\n", r_strlen(line));
	return 0;
}

int r_strlen(char* str){
	if((int)strlen(str)<=0)
		return 0;

	if(*(str) == ' ' || *(str) == '\n' || *(str) == '\t')
		return r_strlen(str + 1);
	else
		return r_strlen(str + 1) + 1;
}

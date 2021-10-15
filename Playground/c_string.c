#include <stdio.h>
#include <string.h>

int main(void) {
	char str[100]; // input string
	char reverse[100]; // string reversed

	printf("Enter string: ");
	char c;
	int cnt = 0;

	c = getchar();
	while (c != '\n' && c != EOF) {
		str[cnt] = c;
		c = getchar();
		cnt++;
	}

	for(int i=0; i<cnt; ++i){
		reverse[i] = str[cnt-i-1];
	}

	reverse[cnt] = '\0';

	printf("In reverse order: %s", reverse);

  return 0;
}

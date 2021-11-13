#include <stdio.h>

int markbingo(int num, int b[25]);
void printbingo(int b[25]);

int main(void) {
	int bingo[25]={0}; // bingo matrix
	int num;

	while(1){
		printf("Enter a number(1~25) > ");
		scanf("%d", &num);
		int result = markbingo(num, bingo);
		if(result==-1){
			printf("EXIT!\n");
			break;
		}
		else if(result==1){
			printf("Bingo!\n");
			break;
		}
	}

	printbingo(bingo);

}

int markbingo(int num, int b[25]){
	if(num<1 || num>25)
		return -1;

	num--;
	int c = num%5;
	int r = num/5;

	if(b[num]!=0){
		printf("Duplicated!\n");
	}
	else{
		b[num] = 1;
		int flag=1;
		for(int i=0; i<5; ++i){
			if(b[r*5 + i]==0){
				flag=0;
				break;
			}
		}
		if(flag){
			return 1;
		}
		flag = 1;
		for(int i=0; i<5; ++i){
			if(b[c + i*5]==0){
				flag=0;
				break;
			}
		}
		if(flag){
			return 1;
		}
	}
	return 0;
}

void printbingo(int b[25]){
	printf("BINGO MATRIX\n");
	printf("---------------------\n");
	for(int i=0; i<25; ++i){
		printf("| %d ", b[i]);
		if(i%5 == 4)
			printf("|\n");
	}
	printf("---------------------\n");
}

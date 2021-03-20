#include <iostream>

#define MAX 51
using namespace std;

int arr[MAX][MAX];
int SIZE[MAX];
int SUM = 0;

int main() {
	int N;
	cin >> N;
	for(int i=0; i<N; ++i){
		string temp;
		cin >> temp;
		for(int j=0; j<N; ++j){
			arr[i][j] = temp[j] - 48;
		}
	}

	int sz = 1;
	while(sz<=N){
		for(int i=0; i<=N-sz; ++i){
			for(int j=0; j<=N-sz; ++j){
				for(int k=i; k<i+sz; ++k)
					for(int h=j; h<j+sz; ++h){
						if(arr[k][j]==0){
							k=h=N;
							i += sz;
						}
						else if(k==i+sz-1 && h==j+sz-1){
							SIZE[sz]++;
							SUM++;
						}
					}
			}
		}
	}
	cout << "total: " << SUM;
	for(int i=1; i<=N; ++i)
		if(SIZE[i]>0)
			printf("size[%d]: %d", i, SIZE[i]);
	return 0;
}

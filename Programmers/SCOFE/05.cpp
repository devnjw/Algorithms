#include <iostream>
#include <queue>

using namespace std;

int arr[1002][22];
int N, M;
queue<int> q;

int main() {
	cin >> N >> M;
	for(int i=0; i<=M+1; ++i){
		for(int j=0; j<=N+1; ++j){
			arr[i][j] = 50000;
		}
	}

	for(int i=1; i<=M; ++i){
		string temp;
		cin >> temp;
		for(int j=0; j<N; ++j){
			if(temp[j]=='c'){
				arr[i][j+1] = 0;
				q.push(j+1);
			}
			else if(temp[j]=='x')
				arr[i][j+1] = 40000;
			else
				arr[i][j+1] = 30000;
		}
	}

	int index;
	for(int j=1; j<=M; ++j){
		if(arr[1][j]==0){
			index = j;
			while(1){
				if(arr[1][index-1]==50000) break;
				if(arr[1][index-1]==40000) break;
				if(arr[1][index-1] <= arr[1][index]) break;
				arr[1][index-1] = arr[1][index] + 1;
				index--;
			}
			index = j;
			while(1){
				if(arr[1][index+1]==50000) break;
				if(arr[1][index+1]==40000) break;
				if(arr[1][index+1] <= arr[1][index]) break;
				arr[1][index+1] = arr[1][index] + 1;
				index++;
			}
		}
	}

	for(int i=2; i<=M; ++i){
		for(int j=1; j<=N; ++j){
			if(arr[i-1][j]<30000 && arr[i][j] != 40000){
				arr[i][j] = arr[i-1][j];
				index = j;
				while(1){
					if(arr[i][index-1]==50000) break;
					if(arr[i][index-1]==40000) break;
					if(arr[i][index-1] <= arr[i][index]) break;
					arr[i][index-1] = arr[i][index] + 1;
					index--;
				}
				index = j;
				while(1){
					if(arr[i][index+1]==50000) break;
					if(arr[i][index+1]==40000) break;
					if(arr[i][index+1] <= arr[i][index]) break;
					arr[i][index+1] = arr[i][index] + 1;
					index++;
				}
			}
		}
	}

	// for(int i=0; i<=M+1; ++i){
	// 	for(int j=0; j<=N+1; ++j){
	// 		printf("%05d ", arr[i][j]);
	// 	}
	// 	printf("\n");
	// }

	int MIN = 30000;
	for(int j=1; j<=N; ++j){
		if(arr[M][j]<MIN) MIN = arr[M][j];
	}

	if(MIN>29000)
		printf("-1");
	else
		printf("%d",MIN);
	return 0;
}

#include <iostream>
#include <algorithm>

#define NMAX 10001
#define MMAX 101

using namespace std;

int arr[NMAX][MMAX];
int N, M;

int main() {
	cin >> M >> N;
	for(int i=1; i<=N; ++i){
		for(int j=1; j<=M; ++j){
			cin >> arr[i][j];
			arr[i][j] += max(arr[i-1][j], arr[i][j-1]);
		}
	}

	cout << arr[N][M];
	return 0;
}

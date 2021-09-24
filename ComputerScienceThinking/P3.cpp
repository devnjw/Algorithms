#include <iostream>
#define SIZE 100000

using namespace std;

int M, answer;
int arr[SIZE+1];

int main(){
	cin >> M;

	int tmp;
	while(cin >> tmp) {
		if(tmp < 0) break;
		arr[tmp]++;
	}

	int l = 1, r = M;
	while(arr[l]==0)
		l++;
	while(arr[r]==0)
		r--;

	while(l<=r){
 		if(l+r>M){
			answer++;
			arr[r]--;
			while(r>=0 && arr[r]==0)
				r--;
		}
		else{
			answer++;
			arr[r]--;
			arr[l]--;
			while(r>=0 && arr[r]<=0)
				r--;
			while(l<=M && arr[l]<=0)
				l++;
		}
	}

	cout << answer;

  return 0;
}

#include <iostream>

using namespace std;

int M, answer;
int arr[100001];

int main(){
	cin >> M;

	int tmp;
	while(true) {
		cin >> tmp;
		arr[tmp]++;
		if(tmp < 0) break;
		if(cin.eof() == true) {
		 break;
		}
	}

	int l = 0, r = M;
	while(arr[l]==0)
		l++;
	while(arr[r]==0)
		r--;

	while(l<=r){
 		if(l+r>M){
			answer++;
			arr[r]--;
			while(arr[r]==0 && r>=0)
				r--;
		}
		else{
			answer++;
			arr[r]--;
			arr[l]--;
			while(arr[r]==0 && r>=0)
				r--;
			while(arr[l]==0 && l<=M)
				l++;
		}
	}

	cout << answer;

  return 0;
}

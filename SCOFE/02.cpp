#include <iostream>
#include <string>

long long arr[50];

using namespace std;
int main() {
	int N;
	string str;
	cin >> N;
	cin >> str;

	for(int i=0; i<N; ++i)
		arr[i] = str[i] - 48;

	for(int i=2; i<N; ++i){
		if(arr[i]!=0) arr[i] = arr[i-1] + arr[i-2];
	}

	cout << arr[N-1];
	return 0;
}

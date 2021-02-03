#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int N;
int arr[500000];

int main() {
  cin >> N;
  for(int i = 0; i < N; ++i)
    cin >> arr[i];
  sort(arr, arr+N);

  long long cnt = 0;
  for(int i = 0; i < N; ++i){
    cnt += abs((i+1)-arr[i]);
  }
  cout << cnt;
}

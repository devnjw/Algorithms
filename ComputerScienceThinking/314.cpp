#include <iostream>

using namespace std;

// C(n) = C(n-1) + C(n-3) + C(n-4)

int arr[100];

int main(){
  int N;
  cin >> N;
  
  arr[1] = 1;
  arr[2] = 1;
  arr[3] = 2;
  arr[4] = 4;

  for(int i=5; i<=N; ++i){
    arr[i] = arr[i-1] + arr[i-3] + arr[i-4];
  }

  cout << arr[N];

  return 0;
}

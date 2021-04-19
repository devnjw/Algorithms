#include <iostream>
#include <algorithm>

using namespace std;

int arr[11];

int main(){
  int T;
  cin >> T;
  for(int i=0; i<T; ++i){
    cout << "#" << i+1 << endl;
    int N;
    cin >> N;
    fill(arr, arr+N+1, 0);
    arr[1] = 1;

    for(int j=1; j<=N; ++j){
      for(int k=j; k>0; --k){
        arr[k] = arr[k-1] + arr[k];
        cout << arr[k] << " ";
      }
      cout << endl;
    }
  }

  return 0;
}

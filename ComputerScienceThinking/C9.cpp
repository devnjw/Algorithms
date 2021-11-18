#include <iostream>

using namespace std;

int arr[8000][3];

int main(){
  int N;
  cin >> N;
  int groups = N;
  for(int i=0; i<N; ++i){
    cin >> arr[i][0] >> arr[i][1];
    for(int j=0; j<i; ++j){
      if(arr[i][2]*arr[j][2]==0 && arr[i][0] < arr[j][0] && arr[i][1] > arr[j][1]){
        groups--;
      }
      else if(arr[i][2]*arr[j][2]==0 && arr[i][0] > arr[j][0] && arr[i][1] < arr[j][1]){
        groups--;
      }
    }
  }

  cout << groups;

  return 0;
}

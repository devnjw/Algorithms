#include <iostream>

using namespace std;

int arr[8000][2];

int main(){
  int N;
  cin >> N;
  int groups = N;
  for(int i=0; i<N; ++i){
    cin >> arr[i][0] >> arr[i][1];
    cout << endl;
    for(int j=0; j<i; ++j){
      cout << arr[i][0] << " " << arr[i][1] << " " << arr[j][0] << " " << arr[j][1] << endl;
      if(arr[i][0] < arr[j][0] && arr[i][1] > arr[j][1]){
        cout << "yes\n";
        groups--;
        break;
      }
      else if(arr[i][0] > arr[j][0] && arr[i][1] < arr[j][1]){
        cout << "yes\n";
        groups--;
        break;
      }
    }
  }

  cout << groups;

  return 0;
}

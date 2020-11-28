#include <iostream>
using namespace std;

int arr1[9];
int arr2[9];

int main() {
  for(int i=0;i<9;i++)
    cin >> arr1[i];
  for(int i=0;i<9;i++)
    cin >> arr2[i];

  int cnt1 = 0;
  int cnt2 = 0;

  for(int i=0;i<9;i++){
    cnt1 += arr1[i];
    if(cnt1>cnt2){
      cout << "Yes";
      return 0;
    }
    cnt2 += arr2[i];
  }
  cout << "No";
  return 0;
}

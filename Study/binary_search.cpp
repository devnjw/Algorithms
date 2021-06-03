// 이분 탐색은 데이터가 이미 정렬 되어 있는 상황에서 탐색하는 알고리즘이다.

#include <iostream>
#include <algorithm>

using namespace std;

void Print(int arr[], int size){
  for(int i=0; i<size; ++i)
    cout << arr[i] << " ";
  cout << endl;
}

int binary_search(int * arr, int size, int target){
  int start = 0;
  int end = size;
  int index = (start+end)/2;

  while(arr[index]!=target && start<end){
    if(arr[index]<target)
      start = index+1;
    else
      end = index-1;
    index = (start+end)/2;
  }

  if(arr[index]==target)
    return index;
  else
    return -1;
}

int main(){
  int arr[9] = {2, 4, 6, 8, 10, 12, 14, 16, 18};

  sort(arr, arr + 9);

  int target = 3;
  cout << "INDEX of " << target << " is " << binary_search(arr, 9, target);

  return 0;
}

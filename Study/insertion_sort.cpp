#include <iostream>
#include <algorithm>

using namespace std;

void Print(int arr[], int size){
  for(int i=0; i<size; ++i)
    cout << arr[i] << " ";
  cout << endl;
}

void selection_sort(int * arr, int size){
  for(int i=1; i<size; ++i){
    int index = i;
    for(int j=i-1; j>=0; --j){
      if(arr[index]<arr[j]){
        swap(arr[index], arr[j]);
        index = j;
      }
    }
  }
}

int main(){
  int arr[9] = {8, 5, 9, 7, 4, 2, 6, 3, 1};
  Print(arr, 9);
  selection_sort(arr, 9);
  Print(arr, 9);

  return 0;
}

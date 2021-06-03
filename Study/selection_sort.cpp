#include <iostream>
#include <algorithm>

using namespace std;

void Print(int arr[], int size){
  for(int i=0; i<size; ++i)
    cout << arr[i] << " ";
  cout << endl;
}

void selection_sort(int * arr, int size){
  for(int i=0; i<size-1; ++i){
    int max_i = i;
    for(int j=i+1; j<size; ++j){
      if(arr[max_i]<arr[j]){
        max_i = j;
      }
    }
    swap(arr[i], arr[max_i]);
  }
}

int main(){
  int arr[9] = {8, 5, 9, 7, 4, 2, 6, 3, 1};
  Print(arr, 9);
  selection_sort(arr, 9);
  Print(arr, 9);

  return 0;
}

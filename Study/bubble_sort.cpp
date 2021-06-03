#include <iostream>
#include <algorithm>

using namespace std;

void Print(int arr[], int size){
  for(int i=0; i<size; ++i)
    cout << arr[i] << " ";
  cout << endl;
}

void bubble_sort(int * arr, int size){
  for(int i=0; i<size-1; ++i)
    for(int j=0; j<size-1-i; ++j)
      if(arr[j]>arr[j+1]) swap(arr[j], arr[j+1]);
}

int main(){
  int arr[9] = {8, 5, 9, 7, 4, 2, 6, 3, 1};
  Print(arr, 9);
  bubble_sort(arr, 9);
  Print(arr, 9);

  return 0;
}

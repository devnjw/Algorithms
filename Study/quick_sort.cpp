#include <iostream>
#include <algorithm>

using namespace std;

void Print(int arr[], int size){
  for(int i=0; i<size; ++i)
    cout << arr[i] << " ";
  cout << endl;
}

int partition(int * arr, int left, int right){
  int pivot = arr[left];
  int l = left, r = right;

  while(l<r){
    while(pivot < arr[r])
      r--;
    while(l<r && arr[l] <= pivot)
      l++;
    swap(arr[l], arr[r]);
  }

  arr[left] = arr[l];
  arr[l] = pivot;

  return l;
}

void quick_sort(int * arr, int left, int right){
  if(left >= right) return;

  int pivot = partition(arr, left, right);

  quick_sort(arr, pivot+1, right);
  quick_sort(arr, left, pivot-1);
}

int main(){
  int arr[9] = {8, 5, 9, 7, 4, 2, 6, 3, 1};
  Print(arr, 9);
  quick_sort(arr, 0, 9);
  Print(arr, 9);

  return 0;
}

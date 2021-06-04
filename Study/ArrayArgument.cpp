#include <iostream>

using namespace std;

void Display(int arr[], int size){
  for(int i=0; i<size; ++i)
    cout << arr[i] << " ";
  cout << endl;
}

void func1(int arr[9]){
  arr[0] = arr[0] + 1;
}

void func2(int * arr){
  arr[0] = arr[0] + 1;
}


int main(){
  int arr[9] = {8, 5, 9, 7, 4, 2, 6, 3, 1};
  Display(arr, 9);

  func1(arr);

  Display(arr, 9);

  func2(arr);

  Display(arr, 9);



  return 0;
}

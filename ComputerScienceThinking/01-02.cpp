#include <iostream>

using namespace std;

int arr[9] = {0, 1, 19, 271, 3439, 40951, 468559, 5217031, 56953279};

int main(){
  int N;
  cin >> N;

  int i=1;
  int j=0;

  while(N/i){
    if((N/i)%10>4)
      N -= i;
    N -= ((N/i)%10)*(arr[j]);
    i *= 10;
    j += 1;
  }

  cout << N;

  return 0;
}

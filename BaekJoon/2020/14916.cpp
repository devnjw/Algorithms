#include <iostream>
using namespace std;

int N;

int main() {
  cin >> N;
  if(N==3||N==1){
    cout<< -1;
    return 0;
  }

  int cnt5 = 0;
  while(N>=5){
    if(N<10 && (N-5)%2==1) break;
    cnt5++;
    N = N-5;
  }
  cout << cnt5++ + N/2;
}

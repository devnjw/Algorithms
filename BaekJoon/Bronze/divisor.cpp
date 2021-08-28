// 약수 구하기 문제
#include <iostream>

using namespace std;

int main(){
  int N, K;
  cin >> N >> K;

  int n = 1;
  while(n<=N){
    if(N%n==0){
      K--;
      if(K==0){
        cout << n;
        return 0;
      }
    }
    n++;
  }
  cout << 0;
  return 0;
}

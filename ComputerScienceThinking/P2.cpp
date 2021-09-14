#include <iostream>
#define SIZE 10000000

using namespace std;

long long arr[SIZE+1];

int N, K;
int main(){
  cin >> N >> K;

  int x, g;
  for(int i=0; i<N; ++i){
    cin >> g >> x;
    arr[x] = g;
  }

  int l=0, r=2*K+1;
  int cnt = 0;
  for(int i=l; i<r; ++i)
    cnt += arr[i];

  int answer = cnt;
  while(r<=SIZE){
    cnt -= arr[l++];
    cnt += arr[r++];
    if(cnt>answer) answer = cnt;
  }

  cout << answer;

  return 0;
}

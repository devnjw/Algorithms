#include <iostream>

using namespace std;

int N, d, M;
int cnt[100001];

int main(){
  cin >> N >> d >> M;
  int tmp;
  for(int i=0; i<M; ++i){
    cin >> tmp;
    cnt[tmp]++;
  }

  int mn, mx=0;
  for(int i=1; i<=N; ++i)
    if(cnt[i] > mx) mx = cnt[i];

  mn = mx%d > 0 ? mx/d+1 : mx/d;


  return 0;
}

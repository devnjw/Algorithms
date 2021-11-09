#include <iostream>

using namespace std;

int N, d, M;
int cnt[100001];

int main(){
  cin >> N >> d >> M;
  int tmp;
  for(int i=0; i<M; ++i){
    cin >> tmp;
    cnt[tmp+d]++;
  }

  int answer;

  for(answer=1; answer<=M; ++answer){
    int lefts = M;
    int total = M;
    bool flag = true;
    for(int i=1; i<=N; ++i){
      lefts -= answer;
      total -= cnt[i];
      if(total < lefts){
        flag = false;
        break;
      }
    }
    if(flag) break;
  }

  cout << answer;

  return 0;
}

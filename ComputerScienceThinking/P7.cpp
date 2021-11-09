#include <iostream>

using namespace std;

int N, d, M;
int tasks[100001];

int main(){
  cin >> N >> d >> M;
  d++;

  int tmp;
  for(int i=0; i<M; ++i){
    cin >> tmp;
    tasks[tmp]++;
  }

  int mn, mx=0;
  for(int i=0; i<=N; ++i)
    if(tasks[i] > mx) mx = tasks[i];
  mn = mx%d > 0 ? mx/d+1 : mx/d;
  int mid = (mn+mx)/2;

  while(mn < mx){
    int lefts = 0;
    for(int i=0; i<=N; ++i){
      if((lefts+tasks[i])/float(d) > mid){
        lefts = 1;
        break;
      }
      lefts = lefts + tasks[i] - mid;
      if(lefts<0) lefts=0;
    }

    if(lefts)
      mn = mid+1;
    else
      mx = mid;

    mid = (mn+mx)/2;
  }

  cout << mid;

  return 0;
}

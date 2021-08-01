#include <iostream>
#include <vector>

using namespace std;

int N, K;
int mx, mn = 100000;
int answer;
vector<int> H, A, B;

int main(){
  cin >> N >> K;

  int tmp;
  for(int i=0; i<N; ++i){
    cin >> tmp;
    if(tmp < mn) mn = tmp;
    if(tmp > mx) mx = tmp;
    H.push_back(tmp);
  }
  for(int i=0; i<N; ++i){
    cin >> tmp;
    A.push_back(tmp);
  }
  for(int i=0; i<N; ++i){
    cin >> tmp;
    B.push_back(tmp);
  }

  for(int h=mn; h<=mx; ++h){
    int cnt = 0;
    for(int i=0; i<N; ++i){
      if(H[i] > h)
        cnt += (H[i]-h)*B[i];
      else if(H[i] < h)
        cnt += (h - H[i])*A[i];
      if(cnt > K) break;
    }
    if(cnt < answer) answer = cnt;
  }

  cout << answer;

  return 0;
}

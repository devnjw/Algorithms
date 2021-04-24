#include <vector>
#include <iostream>

using namespace std;

int main() {
  vector<int> v;
  int N, M;
  cin >> N >> M;

  for(int i=0; i<N; ++i){
    int tmp;
    cin >> tmp;
    v.push_back(tmp);
  }

  int l = 0, r = 1;
  int sum = v[0];
  int cnt = 0;

  while(r<=v.size()){

    while(sum<M && r<=v.size())
      sum+=v[r++];

    while(sum>M && l<r)
      sum-=v[l++];

    if(sum==M){
      cnt++;
      sum-=v[l++];
    }
  }

  cout << cnt;

  return 0;
}

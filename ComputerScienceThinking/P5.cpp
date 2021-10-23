#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n, k, answer;
int mn=100000, mx=0;
vector<int> poles;

int main() {
  cin >> n >> k;

  int tmp;
  for(int i=0; i<n; ++i){
    cin >> tmp;
    poles.push_back(tmp);
    if(mn>tmp) mn=tmp;
    if(mx<tmp) mx=tmp;
  }

  sort(poles.begin(), poles.end());

  int l = mn, r = mx;
  while(l <= r){
      int cnt = 1;
      int mid = (l+r)/2;
      int min_d = mx;
      int curr = mn;

      for(int i=0; i<poles.size(); ++i){
        if(poles[i]==mn) continue;

        if(poles[i] - curr >= mid){
            min_d = min(min_d, poles[i] - curr);
            curr = poles[i];
            cnt++;
        }
      }
      if(cnt < k){
          r = mid - 1;
      }
      else{
          l = mid + 1;
          answer = min_d;
      }
  }

  cout << answer;

  return 0;
}

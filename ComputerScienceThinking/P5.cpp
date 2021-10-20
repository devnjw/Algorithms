#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n, k, answer;
int mn=100000, mx=0;
vector<int> poles;

int solution(int distance, , int n) {
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
      int cnt = 0;
      int mid = (l+r)/2;
      int min_d = mx;
      int curr = mn;

      for(auto pole : poles){
        if(pole==mn) continue;
        
        if(pole - curr < mid){
            cnt++;
        }
        else{
            min_d = min(min_d, pole - curr);
            curr = rock;
        }
      }
      if(cnt > n){
          r = mid - 1;
      }
      else{
          l = mid + 1;
          answer = min_d;
      }
  }

  return answer;
}

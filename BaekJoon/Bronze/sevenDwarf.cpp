// 일곱 나쟁이
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int cnt = 0;
  vector<int> v;
  int tmp;
  for(int i=0; i<9; ++i){
    cin >> tmp;
    v.push_back(tmp);
    cnt += tmp;
  }

  for(int i=0; i<8; ++i){
    for(int j=i+1; j<9; ++j){
      if(v[i]+v[j] == cnt-100){
        v.erase(v.begin()+j);
        v.erase(v.begin()+i);
        i=9;
        j=9;
      }
    }
  }
  sort(v.begin(), v.end());
  for(auto t:v)
    cout << t << "\n";
  return 0;
}

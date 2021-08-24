#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> v;

int main(){
  v.push_back(5);
  v.push_back(1);
  v.push_back(3);
  v.push_back(4);

  // 최대값
  cout << *max_element(v.begin(), v.end()) << endl;

  // 최대값 위치
  cout << max_element(v.begin(), v.end()) - v.begin() << endl;

  // 최대값 바로 변경
  *max_element(v.begin(), v.end()) += 1 ;
  cout << *max_element(v.begin(), v.end()) << endl;

  return 0;
}

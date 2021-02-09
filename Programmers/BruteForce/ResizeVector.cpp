#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void ResizeTest(vector<int> &v){
  printf("\n ---- Test 03 ----\n");
  for(int i=0; i<v.size(); ++i){
    printf("%d ",v[i]);
  }
  v[0] = 5;
  printf("\n");
}

int main() {
  vector<int> v = {1, 2, 3};
  vector<int> d;

  d.resize((int)(v.size()) - 1);

  copy(v.begin()+1, v.end(), d.begin());
  cout << &v[1] << " " << &d[0] << endl;

  cout << "Before: " << v[1] << " " << d[0] << endl;
  ResizeTest(d);
  cout << "After: " << v[1] << " " << d[0] << endl;

  return 0;
}

#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int number;
  cin >> number;

  int cmp = 1;
  int cnt = 0;
  while(cmp < number){
    int tmp = 1;
    while(cmp/tmp){
      if((cmp/tmp)%10==4){
        cmp += tmp;
        cnt += tmp;
      }
      tmp*=10;
    }
    cmp++;
  }

  cout << cmp - cnt;
  return 0;
}

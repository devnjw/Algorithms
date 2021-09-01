#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int number;
  cin >> number;

  int cmp = 1;
  int cnt = 1;
  while(cmp < number){
    int tmp = 1;
    while(cmp / tmp){
      cout << (cmp/tmp)%(tmp*10) << endl;
      if((cmp/tmp)%(tmp*10)==4){
        cmp += tmp;
      }
      tmp*=10;
    }
    if(cmp==number) break;
    cnt++;
    cmp++;
  }

  cout << cnt;

  return 0;
}

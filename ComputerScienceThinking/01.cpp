#include <iostream>
#include <time.h>

using namespace std;

int main() {
  clock_t start, end;
  start = clock();

  // ios::sync_with_stdio(false);
  // cin.tie(NULL);

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

  end = clock();

  printf("Timer : %.2f",((float)(end - start) / CLOCKS_PER_SEC));

  return 0;
}

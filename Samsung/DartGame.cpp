#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int TC, N;
  scanf("%d\n", &TC);
  for(int i=0; i<TC; ++i){
    scanf("%d\n", &N);
    long long cnt = 0;
    for(int j=0; j<N; ++j){
      int x, y;
      scanf("%d %d\n", &x, &y);
      int p = 11 - sqrt(x*x + y*y)/20;
      if(result > 0)
        cnt += p;
    }
    printf("#%d %d\n", i+1, cnt);
  }
  return 0;
}

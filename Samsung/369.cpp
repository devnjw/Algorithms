#include <iostream>
#include <vector>

using namespace std;

int N;

int main(){
  cin >> N;
  for(int i=1; i<=N; ++i) {
    int cnt369 = 0;
    int a = (i/100);
    int b = (i/10)%10;
    int c = (i%10)%10;

    if(a!=0 && a%3==0)
      cnt369++;
    if(b!=0 && b%3==0)
      cnt369++;
    if(c!=0 && c%3==0)
      cnt369++;

    if(cnt369==0) cout << i;
    while(cnt369-- > 0) cout << "-";
    cout << " ";
  }

  return 0;
}

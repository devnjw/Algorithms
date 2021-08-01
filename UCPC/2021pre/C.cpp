#include <iostream>
#include <vector>

using namespace std;

double a, d, k;
double answer;


int main(){
  cin >> a >> d >> k;
  int t = 1;

  while(1){
    answer += t*a*d/100;

    if(d==100) break;

    if(d + d * k / 10000 <= 100)
      d = (d + d * k / 100) * (100 - d) / 100;
    else
      d = (100 - d);


    t++;
  }

  printf("%0.6f", answer);
  return 0;
}

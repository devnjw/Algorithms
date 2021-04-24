#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int cntM = 0;
int cntP = 0;
int arrM[10000];
int arrP[10000];

int main() {
  cin >> N >> M;

  int temp = 0;
  for(int i=0; i<N; i++)
  {
    cin >> temp;
    if(temp < 0) arrM[cntM++] = abs(temp);
    else arrP[cntP++] = temp;
  }

  sort(arrM, arrM + cntM);
  sort(arrP, arrP + cntP);

  cntM--;
  cntP--;

  int steps = 0;
  int longest = 0;

  while(cntM >= 0)
  {
    if(longest < arrM[cntM])
      longest = arrM[cntM];
    steps += 2*arrM[cntM];
    //cout << steps << endl;
    cntM -= M;
  }

  while(cntP >= 0)
  {
    if(longest < arrP[cntP])
      longest = arrP[cntP];
    steps += 2*arrP[cntP];
    //cout << steps << endl;
    cntP -= M;
  }
  steps -= longest;
  cout << steps;
}

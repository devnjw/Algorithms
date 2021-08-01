#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, q;
int arr[200001][3];
int answer;

int main(){
  cin >> m >> q;
  for(int i=0; i<q; ++i){
    int a, b;
    cin >> a >> b;
    if(a==0) // y=b
      arr[b][1] = 1;
    if(a==60) // x=b
      arr[b][0] = 1;
    if(a==120) // x+y=b
      arr[b][2] = 1;
  }

  arr[0][0] = 1;
  arr[0][1] = 1;
  arr[m][2] = 1;

  for(int p0=0; p0<m; ++p0){
    if(arr[p0][0])
      for(int p1=0; p1<m+p0; ++p1){
        if(arr[p1][1])
          for(int p2=p0+p1+1; p2<=m; ++p2){
            if(arr[p2][2])
              if(p0+p1<=m){
                answer++;
              }
          }
      }
  }

  printf("%d", answer);
  return 0;
}

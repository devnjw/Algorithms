#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, q;
int arr[200001][3];

int main(){
  cin >> m >> q;

  arr[0][0] = 1;
  arr[0][1] = 1;
  arr[m][2] = 1;

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

  int cnt_x = 0, cnt_y = 0;
  for(int i=1; i<=m; ++i){
    // arr[i][0] = arr[i][0] + arr[i-1][0];
    // arr[i][1] = arr[i][1] + arr[i-1][1];
    cnt_x += arr[i-1][0];
    cnt_y += arr[i-1][1];
    arr[i][2] = arr[i][2] + arr[i-1][2];
  }

  printf("answer: %d %d %d\n", cnt_x, cnt_y, arr[m][2]);

  int answer = cnt_x * cnt_y * arr[m][2];

  for(int x=0; x<=m; x++){
    if(arr[x][0])
      for(int y=0; y<=m-x; y++){
        if(arr[y][1]){
          // printf("%d %d %d\n", x, y, arr[min(x, y)][2]);
          answer -= arr[min(x, y)][2];
        }
      }
  }

  printf("%d", answer);
  return 0;
}

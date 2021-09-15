#include <iostream>
#include <vector>

using namespace std;

int arr[52][52];
int cloud[52][52];
int cloud_moved[52][52];
int directions[8][2] =
{
  {-1,0},
  {-1,-1},
  {0,-1},
  {1,-1},
  {1,0},
  {1,1},
  {0,1},
  {-1,1}
};

int N, M;

void moveCloud(int d, int s){
  int dx = directions[d-1][0]*s;
  int dy = directions[d-1][1]*s;
  int x, y;

  // 1, 4
  for(int i=1; i<=N; ++i){
    for(int j=1; j<=N; ++j){
      if(cloud[i][j]){
        x = (j+dx-1)%N +1;
        if(x<=0)x+=N;
        y = (i+dy-1)%N +1;
        if(y<=0)y+=N;
        cloud_moved[y][x] = 1;
        arr[y][x]++;
      }
    }
  }

  for(int i=1; i<=N; ++i){
    for(int j=1; j<=N; ++j){
      cloud[i][j] = 0;
      if(cloud_moved[i][j]){
        if(arr[i-1][j-1]) arr[i][j]++;
        if(arr[i-1][j+1]) arr[i][j]++;
        if(arr[i+1][j-1]) arr[i][j]++;
        if(arr[i+1][j+1]) arr[i][j]++;
      }
    }
  }

  for(int i=1; i<=N; ++i){
    for(int j=1; j<=N; ++j){
      if(arr[i][j]>=2 && cloud_moved[i][j]==0){
        cloud[i][j] = 1;
        arr[i][j] -= 2;
      }
      cloud_moved[i][j] = 0;
    }
  }
}

int main(){
  cin >> N >> M;
  for(int i=1; i<=N; ++i)
    for(int j=1; j<=N; ++j)
      cin >> arr[i][j];

  cloud[N-1][1] = cloud[N-1][2] = cloud[N][1] = cloud[N][2] = 1;

  int d, s;
  for(int i=0; i<M; ++i){
    cin >> d >> s;
    moveCloud(d, s);
  }

  int cnt = 0;
  for(int i=1; i<=N; ++i){
    for(int j=1; j<=N; ++j){
      cnt += arr[i][j];
    }
  }
  cout << cnt;

  return 0;
}

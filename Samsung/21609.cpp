#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N, M;
int arr[22][22];
int visited[22][22];
int visited_rainbow[22][22];
int cnt_rb;

stack<pair<int, int> > rbs;

int DFS(int y, int x, int num){
  visited[y][x] = 1;

  if(arr[y][x] == 0){
    rbs.push(make_pair(y, x));
    cnt_rb++;
  }

  if(arr[y-1][x] == num || arr[y-1][x] == 0){
    if(visited[y-1][x]==0){
      visited[y-1][x] = 1;
      visited[y][x] += DFS(y-1, x, num);
    }
  }
  if(arr[y+1][x] == num || arr[y+1][x] == 0){
    if(visited[y+1][x]==0){
      visited[y+1][x] = 1;
      visited[y][x] += DFS(y+1, x, num);
    }
  }
  if(arr[y][x+1] == num || arr[y][x+1] == 0){
    if(visited[y][x+1]==0){
      visited[y][x+1] = 1;
      visited[y][x]  += DFS(y, x+1, num);
    }
  }
  if(arr[y][x-1] == num || arr[y][x-1] == 0){
    if(visited[y][x-1]==0){
      visited[y][x-1] = 1;
      visited[y][x]  += DFS(y, x-1, num);
    }
  }

  return visited[y][x];
}

int Boom(int y, int x, int num){
  visited[y][x] = 1;

  if(arr[y][x] == 0){
    rbs.push(make_pair(y, x));
    cnt_rb++;
  }

  if(arr[y-1][x] == num || arr[y-1][x] == 0){
    if(visited[y-1][x]==0){
      visited[y-1][x] = 1;
      visited[y][x] += DFS(y-1, x, num);
    }
  }
  if(arr[y+1][x] == num || arr[y+1][x] == 0){
    if(visited[y+1][x]==0){
      visited[y+1][x] = 1;
      visited[y][x] += DFS(y+1, x, num);
    }
  }
  if(arr[y][x+1] == num || arr[y][x+1] == 0){
    if(visited[y][x+1]==0){
      visited[y][x+1] = 1;
      visited[y][x]  += DFS(y, x+1, num);
    }
  }
  if(arr[y][x-1] == num || arr[y][x-1] == 0){
    if(visited[y][x-1]==0){
      visited[y][x-1] = 1;
      visited[y][x]  += DFS(y, x-1, num);
    }
  }

  return visited[y][x];
}

int main(){
  for(int i=0; i<22; ++i)
    for(int j=0; j<22; ++j)
      arr[i][j] = -1;

  cin >> N >> M;

  for(int i=1; i<=N; ++i)
    for(int j=1; j<=N; ++j)
      cin >> arr[i][j];

cout << endl;
  for(int i=1; i<=N; ++i){
    for(int j=1; j<=N; ++j)
      cout << arr[i][j] << " ";
    cout << endl;
  }
  cout << endl;

  int mx = 0;
  int mxX = 0, mxY = 0;
  int tmp;
  for(int i=1; i<=N; ++i){
    for(int j=1; j<=N; ++j){
      if(visited[i][j]==0  && arr[i][j] > 0){
        cnt_rb = 0;
        tmp = DFS(i, j, arr[i][j]);
        visited_rainbow[i][j] = cnt_rb;
        if(tmp > mx){
          mx = tmp;
          mxX = j;
          mxY = i;
        }
      }
      while(!rbs.empty()){
        visited[rbs.top().first][rbs.top().second] = 0;
        rbs.pop();
      }
    }
  }

  answer += mx*mx;

  for(int i=1; i<=N; ++i){
    for(int j=1; j<=N; ++j){
      cout << visited[i][j] << " ";
    }
    cout << endl;
  }

  for(int i=1; i<=N; ++i){
    for(int j=1; j<=N; ++j){
      cout << visited_rainbow[i][j] << " ";
    }
    cout << endl;
  }


  cout << answer;



  return 0;
}

#include <iostream>

using namespace std;

int N, L, R;
int population[50][50];
int visited[50][50];
int sums[50*50][2];

int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

void init_visited(){
  for(int i=0; i<N; ++i){
    for(int j=0; j<N; ++j){
      visited[i][j] = -1;
    }
  }
}

void init_sums(){
  for(int i=0; i<N*N; ++i){
    sums[i][0] = sums[i][1] = 0;
  }
}

bool is_possible(int r, int c){
  if(r < 0 || r >= N)
    return false;
  if(c < 0 || c >= N)
    return false;
  return true;
}

void DFS(int r, int c, int team){
  visited[r][c] = team;
  sums[team][0] += population[r][c];
  sums[team][1]++;

  for(int i=0; i<4; ++i){
    int y = r + dir[i][0];
    int x = c + dir[i][1];

    if(is_possible(y, x) && visited[y][x]==-1){
      int diff = abs(population[r][c] - population[y][x]);
      if(diff >= L && diff <= R){
        DFS(y, x, team);
      }
    }
  }
}

int main(){
  cin >> N >> L >> R;
  for(int i=0; i<N; ++i)
    for(int j=0; j<N; ++j)
      cin >> population[i][j];

  int answer = 0;

  while(1){
    init_visited();
    init_sums();
    int team = 0;

    for(int i=0; i<N; ++i){
      for(int j=0; j<N; ++j){
        if(visited[i][j]==-1){
          DFS(i, j, team);
          team++;
        }
      }
    }

    for(int i=0; i<N; ++i){
      for(int j=0; j<N; ++j){
        population[i][j] = sums[visited[i][j]][0] / sums[visited[i][j]][1];
      }
    }

    if(team < N*N)
      answer++;
    else
      break;
  }

  cout << answer;
  return 0;
}

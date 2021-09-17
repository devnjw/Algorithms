#include <iostream>
#define MAXSIZE 500

using namespace std;

int N;
int mountain[MAXSIZE][MAXSIZE];
int difficulty[MAXSIZE][MAXSIZE];
int directions[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};

int DFS(int x, int y){
  int diff = 0;
  int tmp, tx, ty;

  for(int i=0; i<4; ++i){
    tx = x + directions[i][0];
    ty = y + directions[i][1];

    if(ty < 0 || ty >= N) continue;
    if(tx < 0 || tx >= N) continue;

    if(mountain[y][x] > mountain[ty][tx]){
      if(difficulty[ty][tx]!=-1)
        tmp = difficulty[ty][tx] + mountain[y][x] - mountain[ty][tx];
      else
        tmp = DFS(tx, ty) + mountain[y][x] - mountain[ty][tx];

      if(diff < tmp) diff = tmp;
    }
  }

  difficulty[y][x] = diff;

  return diff;
}

int main(){
  int answer = 0;

  cin >> N;
  for(int i=0; i<N; ++i){
    for(int j=0; j<N; ++j){
      cin >> mountain[i][j];
      difficulty[i][j] = -1;
    }
  }

  for(int i=0; i<N; ++i){
    for(int j=0; j<N; ++j){
      if(difficulty[i][j]==-1)
        DFS(j, i);
      if(answer < difficulty[i][j])
        answer = difficulty[i][j];
    }
  }

  cout << answer;

  return 0;
}

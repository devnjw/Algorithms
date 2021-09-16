#include <iostream>
#define MAXSIZE 500

using namespace std;

int N;
int mountain[MAXSIZE][MAXSIZE];
int difficulty[MAXSIZE][MAXSIZE];

int DFS(int x, int y){
  if(difficulty[y][x]!=-1)
    return difficulty[y][x];

  int diff = 0;

  int tmp;
  if(y-1 >= 0 && mountain[y][x] > mountain[y-1][x]){
    tmp = DFS(x, y-1) + mountain[y][x] - mountain[y-1][x];
    if(diff < tmp) diff = tmp;
  }
  if(y+1 < N && mountain[y][x] > mountain[y+1][x]){
    tmp = DFS(x, y+1) + mountain[y][x] - mountain[y+1][x];
    if(diff < tmp) diff = tmp;
  }
  if(x-1 >= 0 && mountain[y][x] > mountain[y][x-1]){
    tmp = DFS(x-1, y) + mountain[y][x] - mountain[y][x-1];
    if(diff < tmp) diff = tmp;
  }
  if(x+1 < N && mountain[y][x] > mountain[y][x+1]){
    tmp = DFS(x+1, y) + mountain[y][x] - mountain[y][x+1];
    if(diff < tmp) diff = tmp;
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

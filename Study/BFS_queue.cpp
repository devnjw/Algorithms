#include <iostream>
#include <queue>

#define SIZE 4

using namespace std;

int arr[SIZE][SIZE];
int is_visited[SIZE];

queue<int> q;

void BFS(){
  int index;
  q.push(0);
  is_visited[0] = 1;

  while(!q.empty()){
    index = q.front();
    cout << index << " ";
    q.pop();
    for(int i=0; i<SIZE; ++i){
      if(!is_visited[i] && arr[index][i]>0){
        is_visited[i] = 1;
        q.push(i);
      }
    }
  }
}

int main(){
  for(int i=0; i<SIZE; ++i){
    for(int j=0; j<SIZE; ++j){
      if(i!=j) arr[i][j] = 1;
    }
  }
  arr[0][2] = 0;

  BFS();

  return 0;
}

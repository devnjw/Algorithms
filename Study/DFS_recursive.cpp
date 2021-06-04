#include <iostream>

#define SIZE 4

using namespace std;

int arr[SIZE][SIZE];
int is_visited[SIZE];

void DFS(int index){
  cout << index+1 << " -> ";
  for(int i=0; i<SIZE; ++i){
    if(!is_visited[i]&&arr[index][i]>0){
      is_visited[i] = 1;
      DFS(i);
      is_visited[i] = 0;
    }
  }
}

int main(){
  for(int i=0; i<SIZE; ++i){
    for(int j=0; j<SIZE; ++j){
      if(i!=j) arr[i][j] = 1;
    }
  }

  is_visited[0] = 1;
  DFS(0);

  return 0;
}

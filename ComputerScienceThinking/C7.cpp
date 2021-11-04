#include <iostream>
#include <queue>
#define SIZE 10000

using namespace std;

struct Node{
  int data;
  Node *next;
};

struct Node * adj_arr[SIZE+1];

int N, M;
int visited[SIZE+1];
queue<int> q;

void connect(int curr, int next){
  Node * new_node = (Node*)malloc(sizeof(Node));
  new_node->data = next;
	new_node->next = NULL;

  if(adj_arr[curr]==NULL)
    adj_arr[curr] = new_node;
  else{
    new_node->next = adj_arr[curr];
    adj_arr[curr] = new_node;
  }
}

bool isImpossible(int st){
    q.push(st);
    int depth = 1;
    visited[st] = depth;

    while(!q.empty()){
      if(visited[q.front()] != depth)
        depth++;

      Node * tmp_node = adj_arr[q.front()];
      while(tmp_node != NULL){
        if(visited[tmp_node->data]){
          if(visited[tmp_node->data]%2 == depth%2)
            return true;
        }
        else{
          q.push(tmp_node->data);
          visited[tmp_node->data] = depth+1;
        }
        tmp_node = tmp_node->next;
      }

      q.pop();
    }

    for(int i=1; i<=N; ++i)
      visited[i] = 0;

    return false;
}

int main(){
  cin >> N >> M;

  int a, b;
  for(int i=0; i<M; ++i){
    cin >> a >> b;
    connect(a, b);
    connect(b, a);
    if(isImpossible(a)){
      cout << i+1;
      return 0;
    }
  }

  return 0;
}

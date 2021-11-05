#include <iostream>
#include <stack>
#define SIZE 10000

using namespace std;

struct Node{
  int data;
  Node *next;
};

struct Node * adj_arr[SIZE+1];

int N, M;
int visited[SIZE+1];
stack<int> s;

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

bool isImpossible(int prev, int curr, int day){
  if(visited[curr]){
    if(visited[curr] != day)
      return true;
    else
      return false;
  }

  visited[curr] = day;
  Node * tmp_node = adj_arr[curr];
  while(tmp_node != NULL){
    if(tmp_node->data != prev && isImpossible(curr, tmp_node->data, (day%2)+1))
      return true;
    tmp_node = tmp_node->next;
  }
  visited[curr] = 0;

  return false;
}

int main(){
  cin >> N >> M;

  int a, b;
  for(int i=0; i<M; ++i){
    cin >> a >> b;
    connect(a, b);
    connect(b, a);
    if(isImpossible(0, a, 1)){
      cout << i+1;
      break;
    }
  }

  return 0;
}

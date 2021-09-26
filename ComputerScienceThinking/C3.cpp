#include <iostream>
#define SIZE 40000

using namespace std;

struct Queue{
  int arr[SIZE];
  int start;
  int end;
  bool empty(){
    if(start==end)
      return true;
    else
      return false;
  }
  void init(){
    start = 0;
    end = 0;
  }
  void push(int data){
    arr[end] = data;
    end++;
  }
  void pop(){
    start++;
  }
  int front(){
    return arr[start];
  }
};

struct Node{
  int data;
  Node *next;
};

struct Node * adj[SIZE];

// distances from Node 0(=N), 1 and 2
int dists[3][SIZE];
int visited[3][SIZE];

int p, q, r;
int N, M;

void connect(int curr, int next){
  Node * new_node = (Node*)malloc(sizeof(Node));
  new_node->data = next;
	new_node->next = NULL;

  if(adj[curr]==NULL)
    adj[curr] = new_node;
  else{
    Node * tmp_node = adj[curr];
    while(tmp_node->next!=NULL){
      tmp_node = tmp_node->next;
    }
    tmp_node->next = new_node;
  }
}

void search_dist(int node){
  Queue q;
  q.init();
  q.push(node);

  while(!q.empty()){
    Node * tmp_node = adj[q.front()];
    int dist = dists[node][q.front()] + 1;

    while(tmp_node != NULL){
      if(visited[node][tmp_node->data]==0){
        visited[node][tmp_node->data] = 1;
        dists[node][tmp_node->data] = dist;
        q.push(tmp_node->data);
      }
      tmp_node = tmp_node->next;
    }
    q.pop();
  }
}

int main(){
  cin >> p >> q >> r;
  cin >> N >> M;

  int a, b;
  for(int i=0; i<M; ++i){
    cin >> a >> b;
    connect(a%N, b%N);
    connect(b%N, a%N);
  }

  for(int i=0; i<3; ++i){
    dists[i][i] = 0;
    visited[i][i] = 1;
    search_dist(i);
  }

  int answer = dists[0][0] * r + dists[1][0] * p + dists[2][0] * q;
  for(int i=1; i<N; ++i){
    int tmp = dists[0][i] * r + dists[1][i] * p + dists[2][i] * q;
    if(tmp < answer) answer = tmp;
  }

  cout << answer;

  return 0;
}

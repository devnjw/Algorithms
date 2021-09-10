#include <iostream>
#define MAXNUM 2000

using namespace std;

int cntFriends[MAXNUM+1];
int N, K, F;

struct Node{
  int data;
  Node *next;
};

struct Node * friendship[MAXNUM+1];

void connect(int curr, int next){
  Node * new_node = (Node*)malloc(sizeof(Node));
  new_node->data = next;
	new_node->next = NULL;

  Node * tmp_node = friendship[curr];
  while(tmp_node->next!=NULL){
    tmp_node = tmp_node->next;
  }
  tmp_node->next = new_node;
}

void removeNode(int node){
  cntFriends[node] = 0;

  Node * tmp_node = friendship[node];
  tmp_node = tmp_node->next;
  while(tmp_node != NULL){
    cntFriends[tmp_node->data]--;
    tmp_node = tmp_node->next;
  }
}

int main(){
  cin >> N >> K >> F;

  for(int i=1; i<=N; ++i){
    Node * new_node = (Node*)malloc(sizeof(Node));
    new_node->data = i;
    new_node->next = NULL;
    friendship[i] = new_node;
  }

  int a, b;
  for(int i=0; i<F; ++i){
    cin >> a >> b;
    connect(a, b);
    connect(b, a);
    cntFriends[a]++;
    cntFriends[b]++;
  }

  int flag;
  do{
    flag = 0;
    for(int i=1; i<=N; ++i){
      if(cntFriends[i] > 0 && cntFriends[i] < K){
        flag = 1;
        removeNode(i);
      }
    }
  }while(flag);

  int answer = 0;
  for(int i=1; i<=N; ++i)
    if(cntFriends[i] >= K)
      answer++;

  cout << answer;

  return 0;
}

#include <iostream>
#include <stack>

#define SIZE 32000

using namespace std;

struct Node{
  int data;
  Node *next;
};

struct Node * arr[SIZE+1];

void connect(int curr, int next){
  Node * new_node = (Node*)malloc(sizeof(Node));
  new_node->data = next;
	new_node->next = NULL;

  // Check first element
  Node * tmp_node = arr[curr];
  while(tmp_node->next!=NULL){
    tmp_node = tmp_node->next;
  }
  tmp_node->next = new_node;
}

int N, M;
int connected[SIZE+1];

stack<int> st;

void DFS(int n){
  if(connected[n])
      return;

  st.push(n);

  Node * tmp_node = arr[n];
  while(tmp_node != NULL){
    connected[tmp_node->data]--;
    DFS(tmp_node->data);
    tmp_node = tmp_node->next;
  }
}

int main(){
  cin >> N >> M;

  for(int i=1; i<=SIZE; ++i){
    Node * new_node = (Node*)malloc(sizeof(Node));
    new_node->data = i;
    new_node->next = NULL;
    arr[i] = new_node;
  }

  int a, b;
  for(int i=0; i<M; ++i){
    cin >> a >> b;
    connect(b, a);
    connected[a]++;
  }

  for(int i=1; i<=N; ++i){
    if(connected[i]==0){
      DFS(i);
    }
  }

  while(!st.empty()){
    cout << st.top() << " ";
    st.pop();
  }

  return 0;
}

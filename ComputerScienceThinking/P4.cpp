#include <iostream>

using namespace std;

struct Node{
  int a;
  int c;
  Node * next;
};

Node *root;
Node *tail;
Node *curr;

void Print(){
  Node *tmp = root;
  cout << "\n";
  while(tmp != NULL){
    cout << tmp->a << "(" << tmp->c << ") -> ";
    tmp = tmp->next;
  }
  cout << "\n";
}

void push_back(int a, int c){
  Node * new_node = (Node*)malloc(sizeof(Node));
  new_node->a = a;
  new_node->c = c;
  new_node->next = NULL;

  if(root==NULL){
    root = new_node;
    tail = new_node;
  }
  else{
    tail->next = new_node;
    tail = tail->next;
  }
}

void push_inside(int a, int c){
  Node * new_node = (Node*)malloc(sizeof(Node));
  new_node->a = a;
  new_node->c = c;
  new_node->next = NULL;

  if(root==NULL){
    root = new_node;
    tail = new_node;
  }
  else if(curr==NULL){
    curr = new_node;
    curr = curr->next;
  }
  else{
    while(curr->next!=NULL && curr->next->a < a){
      curr = curr->next;
    }
    new_node->next = curr->next;
    curr->next = new_node;
  }
}

int main(){
  int answer = 0;
  int F, G, a, c, p, q;

  push_back(-2000000000, 0);

  cin >> F;
  for(int i=0; i<F; ++i){
    cin >> a >> c;
    push_back(a, c);
  }

  curr = root;
  cin >> G;
  for(int i=0; i<G; ++i){
    cin >> a >> c;
    push_inside(a, c);
  }

  cin >> p >> q;

  if(root==NULL){
    cout << 0;
    return 0;
  }

  curr = root;
  while(curr->next!=NULL && curr->next->a <= p){
    curr = curr->next;
  }

  if(curr->next==NULL || curr->next->a > q){
    cout << ((q-p+1)*curr->c) % 10007;
    return 0;
  }

  c = curr->c;
  answer = ((curr->next->a - p) * c) % 10007;
  curr = curr->next;

  while(curr->next!=NULL && curr->next->a <= q){
    if(curr->c > c) c = curr->c;
    answer = (answer + (curr->next->a - curr->a) * c) % 10007;
    curr = curr->next;
  }

  if(curr->c > c) c = curr->c;
  answer = (answer + (q - curr->a + 1) * c) % 10007;

  cout << answer;

  return 0;
}

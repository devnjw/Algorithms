#include <iostream>

using namespace std;

struct Node{
  char data;
  Node *prev;
  Node *next;
};

Node *curr;

void key_in(char key){
  Node * new_node = (Node*)malloc(sizeof(Node));
  new_node->data = key;
	new_node->prev = curr;

  if(curr->next==NULL){
    new_node->next = NULL;
  }
  else{
  	new_node->next = curr->next;
    Node * tmp = curr->next;
    tmp->prev = new_node;
  }

  curr->next = new_node;
  curr = new_node;
}

void back_space(){
  Node * tmp = curr;

  if(tmp->prev != NULL && tmp->next != NULL){
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp-> prev;
    curr = curr->prev;
    free(tmp);
  }
  else if(tmp->prev != NULL){
    tmp->prev->next = NULL;
    curr = curr->prev;
    free(tmp);
  }
}

void print_linked_list(){
  Node * tmp_node = curr;
  while(tmp_node->prev!=NULL){
    tmp_node = tmp_node->prev;
  }
  while(tmp_node->next != NULL){
    tmp_node = tmp_node->next;
    cout << tmp_node->data;
  }
  cout << endl;
}

void free_all(){
  // Node * tmp_node;
  int cnt = 1;
  while(curr->next!=NULL){
    curr = curr->next;
  }
  while(curr->prev!=NULL){
    back_space();
  }
}

int main(){
  Node * head_node = (Node*)malloc(sizeof(Node));
	head_node->prev = NULL;
	head_node->next = NULL;

  curr = head_node;

  int N;
  cin >> N;

  for(int i=0; i<N; ++i){
    string s;
    cin >> s;
    for(int j=0; j<s.size(); ++j){
      char key = s[j];
      if(key=='<'){
        if(curr->prev != NULL) curr = curr->prev;
      }
      else if(key=='>'){
        if(curr->next != NULL) curr = curr->next;
      }
      else if(key=='-') back_space();
      else key_in(key);
    }

    print_linked_list();
    free_all();
  }

  free_all();

  return 0;
}

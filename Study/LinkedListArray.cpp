#include <iostream>
#define SIZE 5

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

void print_linked_list_arr(){
  Node * tmp_node;
  for(int i=1; i<=SIZE; ++i){
    tmp_node = arr[i];
    while(tmp_node != NULL){
      cout << tmp_node->data << " - ";
      tmp_node = tmp_node->next;
    }
    cout << endl;
  }

  cout << tmp_node->data << endl;
}

int main(){
  for(int i=1; i<=SIZE; ++i){
    Node * new_node = (Node*)malloc(sizeof(Node));
    new_node->data = i;
    new_node->next = NULL;
    arr[i] = new_node;
  }

  connect(1, 2);
  connect(1, 3);
  connect(2, 4);
  connect(4, 5);
  connect(4, 6);

  print_linked_list_arr();

  return 0;
}

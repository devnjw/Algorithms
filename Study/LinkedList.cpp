#include <iostream>

using namespace std;

struct Node{
  int data;
  Node *prev;
  Node *next;
};

Node *list;

void push_back(int key){
  Node * new_node = (Node*)malloc(sizeof(Node));
  new_node->data = key;
	new_node->prev = NULL;
	new_node->next = NULL;

  // Check first element
	if (list == NULL) {
		list = new_node;
	}
	else {
    Node * tmp_node = list;
    while(tmp_node->next!=NULL){
      tmp_node = tmp_node->next;
    }
    tmp_node->next = new_node;
    new_node->prev = tmp_node;
	}
}

void print_linked_list(){
  Node * tmp_node = list;
  while(tmp_node->next != NULL){
    cout << tmp_node->data << endl;
    tmp_node = tmp_node->next;
  }
  cout << tmp_node->data << endl;
}

int main(){
  push_back(1);
  push_back(2);
  push_back(4);
  push_back(8);

  print_linked_list();

  return 0;
}

#include <iostream>
#include <algorithm>
#include <queue>

#define MAX_SIZE 100

using namespace std;

struct Node{
  int data;
  Node * left_child;
  Node * right_child;
};

class BinarySearchTree{
  public:
    void Insert(int elem){
      Node * newNode = new Node();
      newNode->data = elem;

      if (root == nullptr) root = newNode;
      else {
        Node * curr = root;
        Node * tmp = nullptr;

        while(curr != nullptr){
          tmp = curr;
          if(curr->data < newNode->data)
            curr = curr->right_child;
          else
            curr = curr->left_child;
        }

        if(tmp->data < newNode->data)
          tmp->right_child = newNode;
        else
          tmp->left_child = newNode;
      }
    }

    void Delete(int elem){
      Node * curr = root;
      Node * tmp = curr;
      while(curr != nullptr){
        if(curr->data == elem){
          // 자식이 없을 때

          // 자식이 하나일 때

          // 자식이 두 개일 때 -> 왼쪽 노드 중 가장 큰 값 찾아 부모 노드로 바꾸기

        }
        else if(curr->data > elem) curr = curr->left_child;
        else curr = curr->right_child;
      }

      cout << "No Element " << elem << endl;
    }

    bool Find(int elem){
      Node * curr = root;
      while(curr != nullptr){
        if(curr->data == elem) return true;
        else if(curr->data > elem) curr = curr->left_child;
        else curr = curr->right_child;
      }
      return false;
    }

    void Display(){
      queue<Node*> q;
      if(root!=nullptr) q.push(root);
      while(!q.empty()){
        Node * curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if(curr->left_child) q.push(curr->left_child);
        if(curr->right_child) q.push(curr->right_child);
      }
      cout << endl;
    }

  private:
    Node * root;
};

int main(){
  BinarySearchTree * bst = new BinarySearchTree();

  bst->Insert(5);
  bst->Insert(1);

  if(bst->Find(6)) cout << "Find (" << 6 << ") \n";
  else cout << "No (" << 6 << ") \n";

  bst->Insert(6);
  if(bst->Find(6)) cout << "Find (" << 6 << ") \n";
  else cout << "No (" << 6 << ") \n";

  bst->Insert(7);
  bst->Insert(8);
  bst->Insert(3);
  bst->Display();

  return 0;
}

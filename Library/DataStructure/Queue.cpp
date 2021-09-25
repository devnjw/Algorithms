#include <iostream>
#define SIZE 100

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

int main(){
  Queue q;
  q.init();

  q.push(5);
  q.push(1);
  q.push(3);
  q.push(6);

  cout << q.front() << endl;
  q.pop();
  cout << q.front() << endl;

  return 0;
}

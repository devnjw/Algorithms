#include <iostream>
#include <algorithm>

using namespace std;

int Heap[101];
int heap_size = 0;

void insert(int elem){
  heap_size++;
  int i = heap_size;
  Heap[i] = elem;

  while(i!=1 && Heap[i]>Heap[i/2])
    swap(Heap[i], Heap[i/2]);
}

void Print(){
  for(int i=1; i<=heap_size; ++i)
    cout << Heap[i] << " ";
  cout << endl;
}

void Heapify(int index){
  if(index >= heap_size) return;
  int left_index = index*2;
  int right_index = index*2+1;

  int bigest = index;
  if(left_index<=heap_size && Heap[index]<Heap[left_index]) bigest = left_index;
  if(right_index<=heap_size && Heap[bigest]<Heap[right_index]) bigest = right_index;
  if(bigest!=index){
    swap(Heap[index], Heap[bigest]);
    Heapify(bigest);
  }
}

void Delete(int elem){
  int i=1;
  while(Heap[i]!=elem){
    i++;
    if(i>heap_size){
      cout << "No elemment " << elem << " in Heap\n";
      return;
    }
  }

  swap(Heap[i], Heap[heap_size--]);

  Heapify(i);
}

int main(){

  insert(1);
  Print();

  insert(5);
  Print();

  insert(3);
  Print();

  insert(2);
  Print();

  insert(4);
  Print();

  Delete(6);
  Delete(5);
  Print();

  return 0;
}

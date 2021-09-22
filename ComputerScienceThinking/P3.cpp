#include <iostream>
#define MAX_SIZE 100000000

using namespace std;

int heap[MAX_SIZE];
int heapSize = 0;

int heapPush(int value)
{
	heap[heapSize] = value;

	int current = heapSize;
	while (current > 0 && heap[current] < heap[(current - 1) / 2])
	{
		int temp = heap[(current - 1) / 2];
		heap[(current - 1) / 2] = heap[current];
		heap[current] = temp;
		current = (current - 1) / 2;
	}

	heapSize = heapSize + 1;

	return 1;
}

int M;

int main(){

  int n;

  do {
      cin >> n;
      heapPush(n);

  } while (getc(stdin) == '\n');

  for(int i=0; i<heapSize; ++i){
    cout << heap[i] << " ";
  }

  return 0;
}

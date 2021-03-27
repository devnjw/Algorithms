#include <iostream>
#include <vector>

using namespace std;

int N, Q;
int arr[500001];

int main() {
	cin >> N >> Q;
	for(int i=0; i<N-1; ++i){
		int parent, child;
		cin >> parent >> child;
		arr[child] = parent;
	}
	for(int i=0; i<Q; ++i){
		int parent, child;
		cin >> parent >> child;
		while(1){
			if(arr[child]==parent){
				cout << "yes" << endl;
				break;
			}
			else if(arr[child]==0){
				cout << "no" << endl;
				break;
			}
			child = arr[child];
		}
	}
	return 0;
}

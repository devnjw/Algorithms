// Tree 부모 노드 찾기

#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[100001];
vector<int> v[100001];

void DFS(int curr, int prev=-1){
  arr[curr] = prev;
  for(auto tmp:v[curr]){
    if(tmp != prev){
      DFS(tmp, curr);
    }
  }
}

int main(){
  cin >> N;
  int a, b;
  for(int i=1; i<N; ++i){
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  DFS(1);
  for(int i=2; i<=N; ++i)
    cout << arr[i] << "\n";

  return 0;
}

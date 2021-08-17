// Baekjoon 1967 https://www.acmicpc.net/problem/1967
// 트리의 지름 구하기, pair
// 참고: https://xkdlaldfjtnl.tistory.com/43

#include <iostream>
#include <vector>
#include <utility>
#define MAX 100001

using namespace std;

vector<pair<int, int> > adj[MAX];
int N;
int max_distance, max_node;

void DFS(int curr, int distance, int prev = -1){
  for(auto a:adj[curr]){
    if(a.first == prev) continue;
    if(distance + a.second > max_distance){
      max_distance = distance + a.second;
      max_node = a.first;
    }
    DFS(a.first, distance + a.second, curr);
  }
}

int main(){
  cin >> N;

  int x, y, w;
  for(int i=0; i<N-1; ++i){
    cin >> x >> y >> w;
    adj[x].push_back(make_pair(y, w));
    adj[y].push_back(make_pair(x, w));
  }

  DFS(1, 0);
  DFS(max_node, 0);

  cout << max_distance;

  return 0;
}

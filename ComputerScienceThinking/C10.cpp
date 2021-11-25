#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

pair<int, int> buildings[50000];
int visited[50000];
vector<int> relationships[50000];

bool check_dist(pair<int, int> a, pair<int, int> b){
  return 25 > (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
}

void DFS(int num, int &a, int &b, int turn){
  visited[num] = 1;
  if(turn) a++;
  else b++;

  for(int i=0; i<relationships[num].size(); ++i){
    if(visited[relationships[num][i]] == 0){
      DFS(relationships[num][i], a, b, (turn+1)%2);
    }
  }
}

int main(){
  int N;
  cin >> N;

  for(int i=0; i<N; ++i){
    cin >> buildings[i].first >> buildings[i].second;
    for(int j=0; j<i; ++j){
      if(check_dist(buildings[i], buildings[j])){
        relationships[i].push_back(j);
        relationships[j].push_back(i);
      }
    }
  }

  int answer = 0;

  for(int i=0; i<N; ++i){
    if(visited[i]) continue;
    int a = 1, b = 0;
    DFS(i, a, b, 1);
    answer += min(a, b);
  }

  cout << answer;

  return 0;
}

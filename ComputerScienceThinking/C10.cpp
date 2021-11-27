#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

pair<int, int> buildings[50000];
vector<int> relationships[50000];
int visited[50000];
queue<int> q;
queue<int> lv;

bool check_dist(pair<int, int> a, pair<int, int> b){
  return 25 > (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
}

bool cmp(pair<int, int> a, pair<int, int> b){
  return a.first <= b.first;
}

void DFS(int num, int &a, int &b, int turn){
  visited[num] = 1;
  if(turn) a++;
  else b++;

  for(int i=0; i<(int)relationships[num].size(); ++i){
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
  }

  sort(buildings, buildings + N, cmp);

  for(int i=0; i<N; ++i){
    for(int j=i+1; j<N; ++j){
      if(buildings[j].first - buildings[i].first > 10) break;
      if(check_dist(buildings[i], buildings[j])){
        relationships[i].push_back(j);
        relationships[j].push_back(i);
      }
    }
  }

  int answer = 0;

  for(int i=0; i<N; ++i){
    if(visited[i]==0){

      int a = 0, b = 0, turn = 1;
      DFS(i, a, b, turn);

      answer += a > b ? b : a;
    }
  }

  cout << answer;

  return 0;
}

#include <iostream>
#include <vector>
#define N_MAX 451

using namespace std;

int N, B, max_w;
int weights[N_MAX];
int visited[N_MAX];
int vesselsArr[N_MAX][N_MAX];
vector<vector<int> > vessels;

void find_cluster(int cell, vector<int> &cluster, int weight){
  for(auto next_cell:vessels[cell]){
    if(visited[next_cell]==0){
      int flag=1;
      for(auto c:cluster){
        if(vesselsArr[next_cell][c]==0){
          flag=0;
          break;
        }
      }
      if(flag){
        visited[next_cell] = 1;
        weight += weights[next_cell];
        cluster.push_back(next_cell);

        if(max_w < weight)
          max_w = weight;
        find_cluster(next_cell, cluster, weight);

        cluster.pop_back();
        weight -= weights[next_cell];
        visited[next_cell] = 0;
      }
    }
  }
}

int main(){
  cin >> N >> B;
  for(int i=1; i<=N; ++i)
    cin >> weights[i];

  for(int i=0; i<=N; ++i){
    vector<int> tmp;
    vessels.push_back(tmp);
  }

  int a, b;
  for(int i=0; i<B; ++i){
    cin >> a >> b;
    vessels[a].push_back(b);
    vessels[b].push_back(a);
    vesselsArr[a][b] = 1;
    vesselsArr[b][a] = 1;
  }

  for(int i=1; i<=N; ++i){
    visited[i] = 1;
    vector<int> cluster;
    cluster.push_back(i);
    find_cluster(i, cluster, weights[i]);
  }

  cout << max_w;

  return 0;
}

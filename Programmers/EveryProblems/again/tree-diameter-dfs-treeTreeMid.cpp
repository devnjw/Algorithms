// 프로그래머스 트리 트리오 중간값
// 트리 지름 찾기, 복잡한 엣지 케이스
// https://programmers.co.kr/learn/courses/30/lessons/68937

#include <iostream>
#include <vector>
#include <utility>
#define MAX 250001

using namespace std;

vector<int> adj[MAX];
int flag;
int max_distance, max_node;

void DFS(int curr, int distance, int prev = -1){
  for(auto a:adj[curr]){
    if(a == prev) continue;
    if(distance + 1 > max_distance){
        max_distance = distance + 1;
        max_node = a;
        flag = 0;
    }
    else if(distance + 1 == max_distance){
        flag = 1;
    }
    DFS(a, distance + 1, curr);
  }
}

int solution(int n, vector<vector<int>> edges) {

    for(auto &e:edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    DFS(1, 0);
    max_distance = 0;
    DFS(max_node, 0);
    if(flag)
        return max_distance;

    max_distance = 0;
    DFS(max_node, 0);

    if(flag)
        return max_distance;
    else
        return max_distance - 1;
}

#include <string>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

vector<vector<int>> links;

int visited[300000];
long long answer;

long long DFS(vector<int> &a, int idx){
    long long cnt = (long long)a[idx];
    long long tmp;
    for(auto l : links[idx]){
        if(!visited[l]){
            visited[l] = 1;
            tmp = DFS(a, l);
            cnt += tmp;
            answer += abs(tmp);
        }
    }
    return cnt;
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    if(accumulate(a.begin(), a.end(), 0ll)!=0)
        return -1;
    for(auto t:a) links.push_back({});
    for(auto edge:edges){
        links[edge[0]].push_back(edge[1]);
        links[edge[1]].push_back(edge[0]);
    }
    visited[0] = 1;
    DFS(a, 0);

    return answer;
}

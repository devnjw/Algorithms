#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int arr[51][51];
int visited[51];
int answer[51];

// p: current location, T: delivery time
void DFS(int p, int t, int N, int K){
    answer[p] = 1;
    for(int i=1; i<=N; ++i){
        if(p!=i && arr[p][i]>0)
            if(visited[i]==0 && t+arr[p][i] <= K){
                visited[i] = 1;
                DFS(i, t+arr[p][i], N, K);
                visited[i] = 0;
            }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int a = 0;

    for(auto r:road){
        if(arr[r[0]][r[1]])
            arr[r[0]][r[1]] = min(arr[r[0]][r[1]], r[2]);
        else
            arr[r[0]][r[1]] = r[2];

        if(arr[r[1]][r[0]])
            arr[r[1]][r[0]] = min(arr[r[1]][r[0]], r[2]);
        else
            arr[r[1]][r[0]] = r[2];
    }


    visited[1] = 1;
    DFS(1, 0, N, K);

    for(auto v:answer)
        if(v==1)
            a++;

    return a;
}

#include <string>
#include <vector>

using namespace std;

vector<int> used(200, 0);

void DFS(int &n, vector<vector<int>> &computers, int index){
    if(index>=n) return;

    for(int i=0; i<n; ++i){
        printf("%d %d", index, i);
        if(computers[index][i]==1 && used[i]==0){
            printf(" connected\n");
            used[i]=1;
            DFS(n, computers, i);
        }
        else
            printf("\n");
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i=0; i<n; ++i){
        if(used[i] == 0){
            used[i]=1;
            answer++;
            DFS(n, computers, i);
        }
    }

    return answer;
}

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int MAX = 0;
int visited[1000000];

void DFS(vector<int> money, int index, int cnt){
    if(MAX<cnt) MAX=cnt;
    // cout << index-1 << " " << cnt << " " << MAX << endl;

    if(index>=money.size()) return;

    if(visited[index-1]!=0)
        DFS(money, index+1, cnt);
    else{
        DFS(money, index+2, cnt);

        if(index==money.size()-1)
            if(visited[0]==1)
                return;
        visited[index] = 1;
        cnt += money[index];
        DFS(money, index+2, cnt);
        visited[index] = 0;
        cnt -= money[index];
    }
}

int solution(vector<int> money) {

    DFS(money, 1, 0);
    visited[0] = 1;
    DFS(money, 1, money[0]);

    return MAX;
}

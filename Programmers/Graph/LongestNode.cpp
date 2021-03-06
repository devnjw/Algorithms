#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int arr[20001][20001];

void Print(int n){
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int cnt = 0;
    int turn = 1;

    for(auto it: edge){
        if(it[0]==1||it[1]==1) cnt++;
        arr[it[0]][it[1]] = arr[it[1]][it[0]] = 1;
    }
    //Print(n);
    while(cnt != n-1){
        for(int i=2; i<=n; ++i){
            if(arr[1][i]==turn){
                for(int j=2; j<=n; ++j){
                    if(arr[i][j]==1&&arr[1][j]==0){
                        arr[1][j] = turn + 1;
                        cnt++;
                    }
                }
            }
        }
        turn++;
    }
    //cout << endl;
    //Print(n);

    int MAX = *max_element(arr[1]+2, arr[1] + n);
    for(auto it: arr[1])
        if(it==MAX) answer++;

    return answer;
}

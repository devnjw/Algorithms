// https://programmers.co.kr/learn/courses/30/lessons/49191
// 프로그래머스 그래프 문제 - 순위

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int arr[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    for(auto it: results){
        arr[it[0]][it[1]] = 1;
        arr[it[1]][it[0]] = -1;
    }

    for(int k=0; k<n; ++k){
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j){
                for(int l=1; l<=n; ++l){
                    if(arr[i][j] != 0 && arr[i][j] == -arr[i][k]){
                        arr[k][j] = arr[i][j];
                        arr[j][k] = -arr[i][j];
                    }
                }
            }
        }
    }

    for(int i=1; i<=n; ++i){
        int cnt = 1;
        for(int j=1; j<=n; ++j)
            if(arr[i][j] != 0) cnt++;
        if(cnt == n) answer++;
    }

    return answer;
}

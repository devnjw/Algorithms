#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int visited[100];

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    visited[0] = 1;

    while(*min_element(visited, visited+n)==0){
        int mindex = 0;
        int minval = 10000000;
        for(auto it:costs){
            if(visited[it[0]] && visited[it[1]])
                continue;
            else if(visited[it[0]] && minval > it[2]){
                minval = it[2];
                mindex = it[1];
            }
            else if(visited[it[1]] && minval > it[2]){
                minval = it[2];
                mindex = it[0];
            }
        }
        visited[mindex] = 1;
        answer += minval;

    }
    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/43164
// 프로그래머스 DFS 문제 - 여행경로

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> answer;
bool visited[1000000];

// return true if answer is found
bool dfs(vector<vector<string>> &tickets, string next){
    if(answer.size()==tickets.size()){
        answer.push_back(next);
        return true;
    }

    for(int i=0; i<tickets.size(); ++i){
        if(!visited[i] && next == tickets[i][0]){
            visited[i] = true;
            answer.push_back(next);

            if(dfs(tickets, tickets[i][1]))
                return true;
            else{
                visited[i] = false;
                answer.pop_back();
            }
        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    dfs(tickets, "ICN");

    return answer;
}

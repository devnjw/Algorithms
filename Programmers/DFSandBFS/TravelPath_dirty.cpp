#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

stack< vector<string> > s;
queue< vector<string> > q;

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;

    sort(tickets.begin(), tickets.end());
    for(auto ticket : tickets)
        q.push(ticket);

    string next = "ICN";
    int cnt = 0;
    while(s.size()!=tickets.size()){
        if(next==q.front()[0]){
            next=q.front()[1];
            s.push(q.front());
            q.pop();
            cnt = 0;
        }
        else{
            cnt++;
            q.push(q.front());
            q.pop();
            if(cnt==q.size()){
                while(!s.empty() && s.top()[1] != q.front()[0]){
                    q.push(s.top());
                    s.pop();
                }
                next = q.back()[0];
            }
        }
    }

    answer.push_back(s.top()[1]);
    while(!s.empty()){
        answer.push_back(s.top()[0]);
        s.pop();
    }
    reverse(answer.begin(), answer.end());

    return answer;
}

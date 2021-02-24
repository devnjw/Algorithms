#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

bool isConnected(string A, string B){
    int cnt=0;
    for(int i=0; i<A.size(); ++i)
        if(A[i]==B[i]) cnt++;
    if(cnt==A.size()-1) return true;
    else return false;
}

bool isSame(string A, string B){
    int cnt=0;
    for(int i=0; i<A.size(); ++i)
        if(A[i]==B[i]) cnt++;
    if(cnt==A.size()) return true;
    else return false;
}


int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    string curr = begin;

    queue<int> q;
    vector<bool> used(50, 0);

    answer++;
    for(int i=0; i<words.size(); ++i){
        if(isConnected(curr, words[i])){
            if(isSame(target, words[i])) return answer;
            q.push(i);
            used[i] = true;
        }
    }

    while(!q.empty()){
        answer++;
        queue<int> nextQ;
        while(!q.empty()){
            curr = words[q.front()];
            q.pop();
            for(int i=0; i<words.size(); ++i){
                if(isConnected(curr, words[i]) && !used[i]){
                    if(isSame(target, words[i])) return answer;
                    nextQ.push(i);
                    used[i] = true;
                }
            }
        }
        q = nextQ;
    }

    return 0;
}

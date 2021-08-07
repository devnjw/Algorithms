#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    for(int i=1; i<words.size(); ++i){
        if(words[i][0]!=words[i-1][words[i-1].size()-1]){
            answer.push_back(i%n + 1);
            answer.push_back(i/n + 1);
            break;
        }

        for(int j=0; j<i; ++j){
            if(words[j]==words[i]){
                answer.push_back(i%n + 1);
                answer.push_back(i/n + 1);
            }
        }
        if(answer.size()>0) break;
    }
    if(answer.size()==0) return {0, 0};
    return answer;
}

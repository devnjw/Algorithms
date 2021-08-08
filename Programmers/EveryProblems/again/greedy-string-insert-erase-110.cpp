// Greedy 그리디
// 용현이 발상이 좋았다..
// string insert, erase 활용

#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool is110(string &s, int i){
    if(s[i]=='1'&&s[i+1]=='1'&&s[i+2]=='0')
        return true;
    return false;
}

vector<string> solution(vector<string> str) {
    vector<string> answer;
    for(auto s:str){
        int cnt110 = 0;
        for(int i=0; i<s.size(); ++i){
            while(i<s.size()-2 && is110(s, i)){
                cnt110++;
                s.erase(i, 3);
                i -= 2;
                if(i<0) i=0;
            }
        }
        int i;
        for(i=s.size()-1; i>=0; --i){
            if(s[i]=='0')
                break;
        }
        for(int j=0; j<cnt110; ++j){
            s.insert(i+1, "110");
        }
        answer.push_back(s);
    }
    return answer;
}

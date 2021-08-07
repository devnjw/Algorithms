// 11 minute
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer = {0, 0};

    while(s.size()>1){
        answer[0]++;
        int cnt = 0;
        for(auto c:s){
            if(c=='1') cnt++;
            else answer[1]++;
        }
        s.clear();
        while(cnt > 0){
            if(cnt%2) s += '1';
            else s += '0';
            cnt /= 2;
        }
    }

    return answer;
}

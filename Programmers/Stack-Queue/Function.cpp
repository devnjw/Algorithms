#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    stack<int> s;
    int size = progresses.size();
    int cnt = 0;

    for(int i=0;i<size; ++i){
        int dayLeft;
        if((100-progresses[i])%speeds[i] == 0)
            dayLeft = (100-progresses[i])/speeds[i];
        else
            dayLeft = (100-progresses[i])/speeds[i] + 1;
        while(!s.empty()&&s.top()<dayLeft){
            cnt++;
            s.pop();
        }
        if(s.empty()&&cnt!=0){
            answer.push_back(cnt);
            cnt = 0;
        }
        s.push(dayLeft);
    }

    while(!s.empty()){
        cnt++;
        s.pop();
    }
    answer.push_back(cnt);

    return answer;
}

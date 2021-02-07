#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> q;
    queue<int> sorted_q;

    vector<int> cp = priorities;
    sort(cp.begin(), cp.end(), greater<int>());

    for(int i=0; i<priorities.size(); ++i){
        q.push(priorities[i]);
        sorted_q.push(cp[i]);
    }

    while(1){
        if(q.front() == sorted_q.front()){
            q.pop();
            sorted_q.pop();
            answer++;
            if(location==0) break;
        }
        else{
            q.push(q.front());
            q.pop();
        }
        if(location > 0)
                location--;
        else
            location = q.size()-1;
    }

    return answer;
}

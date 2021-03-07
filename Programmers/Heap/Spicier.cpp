#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> q;
    // 다른 답안 보니 이렇게 바로 초기화도 가능
    // priority_queue<int,vector<int>,greater<int>> pq (scoville.begin(),scoville.end());

    for(auto it:scoville)
        q.push(it);

    while(q.top()<K && q.size() > 1){
        answer++;
        int new_food = q.top();
        q.pop();
        new_food += q.top()*2;
        q.pop();
        q.push(new_food);
    }

    if(q.top()<K) return -1;

    return answer;
}

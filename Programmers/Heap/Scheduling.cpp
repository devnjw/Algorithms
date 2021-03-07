#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue< int, vector<int>, greater<int> > pq;

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end());

    int answer = 0;
    int time = jobs[0][0];

    for(auto job:jobs){
        while(job[0]>time && !pq.empty()){
            time += pq.top();
            answer += pq.top() * pq.size();
            pq.pop();
        }
        if(time<job[0] && pq.empty())
            time = job[0];
        pq.push(job[1]);
        answer += time - job[0];
    }
    while(!pq.empty()){
        answer += pq.top() * pq.size();
        pq.pop();
    }

    return answer/jobs.size();
}

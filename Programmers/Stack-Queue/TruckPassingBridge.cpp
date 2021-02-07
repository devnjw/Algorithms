#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    queue<int> w;
    queue<int> t;

    int curr_w = 0;
    int i = 0;
    int t_diff = 0;

    t.push(bridge_length);
    w.push(truck_weights[i]);
    curr_w += truck_weights[i++];

    while(!t.empty()){
        t.front()--;
        answer++;
        t_diff++;
        if(t.front()==0){
            curr_w -= w.front();
            w.pop();
            t.pop();
        }
        if(weight-curr_w >= truck_weights[i] && i<truck_weights.size()){
            t.push(t_diff);
            w.push(truck_weights[i]);
            curr_w += truck_weights[i++];
            t_diff = 0;
        }
    }

    return answer;
}

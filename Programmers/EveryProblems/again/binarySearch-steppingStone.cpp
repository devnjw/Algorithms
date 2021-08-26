// 이분탐색 - 징검다리
// https://programmers.co.kr/learn/courses/30/lessons/43236

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());

    int l = 0, r = distance;
    int answer;
    while(l <= r){
        int cnt = 0;
        int mid = (l+r)/2;
        int min_d = distance;
        int curr = 0;

        for(auto rock : rocks){
            if(rock - curr < mid){
                cnt++;
            }
            else{
                min_d = min(min_d, rock - curr);
                curr = rock;
            }
        }
        if(cnt > n){
            r = mid - 1;
        }
        else{
            l = mid + 1;
            answer = min_d;
        }
    }

    return answer;
}

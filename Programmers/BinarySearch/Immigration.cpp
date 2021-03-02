//프로그래머스 이분탐색 문제 입국심사
//https://programmers.co.kr/learn/courses/30/lessons/43238

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long maxtime = *max_element(times.begin(), times.end()) * n;
    long long mintime = 1;
    long long N;

    while(1){
        answer = (maxtime + mintime) / 2;
        N = 0;
        for(int i=0; i<times.size(); ++i)
            N += answer/times[i];

        if(mintime == maxtime -1) return answer+1;

        if(N < n){
            mintime = answer;
            answer = (answer + maxtime) / 2;
        }
        else if(N >= n){
            maxtime = answer;
            answer = (answer + mintime) / 2;
        }
    }
}

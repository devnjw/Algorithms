// https://programmers.co.kr/learn/courses/30/lessons/42578
// 프로그래머스 해시 문제 - 위장

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> hsmap;
    for(auto clothe : clothes){
        if(hsmap.count(clothe[1]))
            hsmap.find(clothe[1])->second++;
        else
            hsmap.insert({clothe[1], 1});
    }
    for(auto it = hsmap.begin(); it != hsmap.end(); it++)
		  answer *= (it->second+1) ;
    return answer-1;
}

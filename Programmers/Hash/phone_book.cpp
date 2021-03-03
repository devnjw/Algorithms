// https://programmers.co.kr/learn/courses/30/lessons/42577
// 프로그래머스 해시 문제 - 전화번호 목록

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_map<string, int> hsmap;
    sort(phone_book.begin(), phone_book.end());
    for(auto str: phone_book){
        for(int i=0; i<str.size(); ++i){
            string sub = str.substr(0, i);
            if(hsmap.count(sub))
                return false;
        }
        hsmap.insert({str, 0});
    }
    return true;
}

// Palindrome 펠린드롬 문제
// 짝수 팰린드롬도 있다는 것... abba

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int palinCheckerForEven(string &s, int idx){
    int leng = 0;
    int l = idx-1;
    int r = idx;
    while(l>=0&&r<s.size()){
        if(s[l--]==s[r++])
            leng += 2;
        else
            break;
    }
    return leng;
}

int palinChecker(string &s, int idx){
    int leng = 1;
    int l = idx-1;
    int r = idx+1;
    while(l>=0&&r<s.size()){
        if(s[l--]==s[r++])
            leng += 2;
        else
            break;
    }
    return leng;
}

int solution(string s)
{
    int answer = max(palinChecker(s, s.size()/2), palinCheckerForEven(s, s.size()/2));
    int r = s.size()/2 + 1;
    int l = s.size()/2 - 1;
    while(l*2+1>answer){
        answer = max(answer, max(palinChecker(s, l), palinCheckerForEven(s, l)));
        answer = max(answer, max(palinChecker(s, r), palinCheckerForEven(s, r)));
        l--;
        r++;
    }

    return answer;
}

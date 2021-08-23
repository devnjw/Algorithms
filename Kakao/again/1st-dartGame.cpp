// https://programmers.co.kr/learn/courses/30/lessons/17682
// 다른 사람들 풀이 보기
// sstream 활용법

// 모범 답안 01:
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    stringstream ss(dartResult);

    int sum[3] = { 0, 0, 0 };
    int options[3] = { 1, 1, 1 };
    for (int i = 0; i < 3; i++) {
        int score;
        char bonus;
        char option;

        ss >> score;

        bonus = ss.get();
        option = ss.get();

        if (option != '*' && option != '#') {
            ss.unget();
        }

        switch (bonus) {
        case 'S':
            sum[i] += pow(score, 1);
            break;
        case 'D':
            sum[i] += pow(score, 2);
            break;
        case 'T':
            sum[i] += pow(score, 3);
            break;
        default:
            break;
        }

        switch (option) {
        case '*':
            if (i > 0 && options[i - 1]) options[i - 1] *= 2;
            options[i] *= 2;
            break;
        case '#':
            options[i] = -options[i];
            break;
        default:
            break;
        }
    }

    return sum[0] * options[0] + sum[1] * options[1] + sum[2] * options[2];
}


// 모범 답안 2:
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int solution(string dartResult) {
    vector<int> v;
    for(int i = 0, s = 0; i < dartResult.size(); ++i) {
        if(dartResult[i] >= '0' && dartResult[i] <= '9')
            s = s * 10 + dartResult[i] - '0';
        else if(dartResult[i] == 'S') v.push_back(s), s = 0;
        else if(dartResult[i] == 'D') v.push_back(s * s), s = 0;
        else if(dartResult[i] == 'T') v.push_back(s * s * s), s = 0;
        else if(dartResult[i] == '*') {
            if(v.size() > 1) v.back() *= 2, v[v.size() - 2] *= 2;
            else v.back() *= 2;
        } else v.back() = -v.back();

    }
    int ans = 0;
    for(int i = 0; i < v.size(); ++i) ans += v[i];
    return ans;
}


// 내 풀이:
#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> point;
vector<char> opt;

int solution(string dartResult) {
    int answer = 0;
    for(int i=0; i<dartResult.size(); ++i){
        if(dartResult[i]=='1' && dartResult[i+1]=='0'){
            int tmp;
            if(dartResult[i+2]=='S')
                tmp = 10;
            else if(dartResult[i+2]=='D')
                tmp = 100;
            else
                tmp = 1000;
            point.push_back(tmp);

            if(dartResult.size()>i+3){
                if(dartResult[i+3]=='*')
                    opt.push_back('*');
                else if(dartResult[i+3]=='#')
                    opt.push_back('#');
                else
                    opt.push_back(' ');
            }
            i++;
        }
        else if(dartResult[i] >= '0' && dartResult[i] <= '9'){
            int tmp = dartResult[i] - '0';
            if(dartResult[i+1]=='D')
                tmp = tmp*tmp;
            else if(dartResult[i+1]=='T')
                tmp = tmp*tmp*tmp;
            point.push_back(tmp);

            if(dartResult.size()>i+2){
                if(dartResult[i+2]=='*')
                    opt.push_back('*');
                else if(dartResult[i+2]=='#')
                    opt.push_back('#');
                else
                    opt.push_back(' ');
            }
        }
    }

    for(int i=0; i<3; ++i){
        if(opt[i]=='*'){
            if(i!=0)
                point[i-1] *= 2;
            point[i] *= 2;
        }
        else if(opt[i]=='#')
            point[i] *= -1;
    }

    for(auto p:point)
        answer += p;
    return answer;
}

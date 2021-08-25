// 2시간 걸림..

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> split(string input, char delimiter=' ') {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

int toSec(string t){
    vector<string> time = split(split(t)[1], ':');
    int h = stoi(time[0]);
    int m = stoi(time[1]);
    int s = stoi(split(time[2], '.')[0]);
    int sz = split(time[2], '.')[1].size();
    int ms = stoi(split(time[2], '.')[1]);
    for(int i=0; i<3-sz; ++i) ms *= 10;
    return (s + h*60*60 + m*60)*1000 + ms;
}

int addSec(int st, string t){
    float s = stof(split(split(t)[2], 's')[0]);
    return st - (int)(s*1000);
}

vector<int> starts_v;
vector<int> ends_v;

int solution(vector<string> lines) {
    int answer = 0;
    for(auto l:lines){
        int et = toSec(l);
        int st = addSec(et, l);
        starts_v.push_back(st);
        ends_v.push_back(et);
    }
    sort(starts_v.begin(), starts_v.end());
    sort(ends_v.begin(), ends_v.end());

    int l = 0, r = 0;
    int cnt = 0;
    while(r<starts_v.size()){
        while(r<starts_v.size()&&starts_v[r]<ends_v[l]+999){
            r++;
            cnt++;
        }
        if(cnt>answer) answer=cnt;
        while(r<starts_v.size()&&starts_v[r]>=ends_v[l]+999){
            l++;
            cnt--;
        }
    }

    return answer;
}

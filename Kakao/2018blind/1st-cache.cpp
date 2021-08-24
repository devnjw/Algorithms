#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<pair<string, int>> cache;

string toUpperString(string str){
    string result;
    for(auto c:str)
        result += toupper(c);
    return result;
}

int check(int cacheSize, string city){
    int isHit = 0;
    for(auto &c:cache){
        c.second++;
        if(c.first==city){
            isHit = 1;
            c.second = 0;
        }
    }

    if(isHit) return 1;
    else if(cache.size() < cacheSize){
        cache.push_back(make_pair(city, 0));
    }
    else{
        int mx = 0;
        int mxdex = 0;
        for(int i=0; i<cache.size(); ++i){
            if(cache[i].second > mx){
                mx = cache[i].second;
                mxdex = i;
            }
        }
        cache[mxdex].first = city;
        cache[mxdex].second = 0;
    }
    return 0;
}

int solution(int cacheSize, vector<string> cities) {
    if(cacheSize==0) return cities.size() * 5;
    int answer = 0;
    for(auto city:cities){
        if(check(cacheSize, toUpperString(city)))
            answer += 1;
        else
            answer += 5;
    }
    return answer;
}

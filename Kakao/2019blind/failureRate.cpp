#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<float, int>> v;

bool cmp(pair<float, int> a, pair<float, int> b){
    if(a.first > b.first) return true;
    return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    for(int i=0; i<=N+1; ++i)
        v.push_back(make_pair(0, i));

    for(auto s:stages){
        v[s].first++;
    }

    int cnt = v[N+1].first;
    for(int i=N; i>=1; --i){
        cnt += v[i].first;
        v[i].second = i;
        if(v[i].first)
            v[i].first = v[i].first / cnt;
    }

    stable_sort(v.begin()+1, v.end()-1, cmp);

    for(int i=1; i<=N; ++i)
        answer.push_back(v[i].second);

    return answer;
}

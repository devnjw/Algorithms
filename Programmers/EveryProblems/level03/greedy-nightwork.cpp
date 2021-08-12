#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    if(a>b) return true;
    return false;
}

long long solution(int n, vector<int> works) {
    long long answer = 0;
    sort(works.begin(), works.end(), cmp);
    int idx = 0;
    while(n>0){
        if(works[idx]==0) break;
        works[idx]--;
        n--;
        if(works[idx]<works[(idx+1)%works.size()])
            idx = (idx+1)%works.size();
        else if(idx>0 && works[idx-1]>=works[idx])
            idx = 0;
    }
    for(auto w: works)
        answer += w*w;

    return answer;
}

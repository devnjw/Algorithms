// Binary Search
// 선입 선출 스케줄링
// 교훈: 함부로 Sort 하지 말자.... 문제 잘 읽자..

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> cores) {
    int l=1, r=n* (*min_element(cores.begin(), cores.end()));
    int t;
    int Xt;
    while(l<r){
        t = (l+r)/2;
        Xt = 0;
        for(int j=0; j<cores.size(); ++j){
            Xt += t/cores[j];
            if(t%cores[j])
                Xt += 1;
        }
        if(Xt>=n) r = t;
        else if(l==t) break;
        else l = t;
    }

    for(int i=0; i<cores.size(); ++i){
        if(t%cores[i]==0){
            Xt += 1;
            if(Xt >= n)
                return i+1;
        }
    }
    return -1;
}

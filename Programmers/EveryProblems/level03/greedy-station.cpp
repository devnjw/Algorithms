#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int cnt = 0;
    int next_s = 0; // next station
    for(int i=1; i<=n; ++i){
        if(next_s==stations.size()){
            cnt += (n - i + 1) / (2*w + 1);
            if((n - i + 1) % (2*w + 1)) cnt ++;
            break;
        }
        if(i+w < stations[next_s]){
            cnt++;
            i += 2*w;
        }
        else{
            i = stations[next_s] + w;
            next_s++;
        }
    }
    return cnt;
}

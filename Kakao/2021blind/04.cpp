#include <string>
#include <vector>

using namespace std;

int arr[11];
int max_diff = 0;
vector<int> answer;

void comb(int n, vector<int> &v){
    if(n==0){
        int cnt_appeach=0;
        int cnt_lion=0;

        for(int i=0; i<10; ++i){
            if(v[i] && v[i]>=arr[i])
                cnt_appeach += 10-i;
            else if(arr[i] > v[i])
                cnt_lion += 10-i;
        }

        if(cnt_lion-cnt_appeach >= max_diff){
            max_diff = cnt_lion-cnt_appeach;
            answer.clear();
            for(int i=0; i<11; ++i)
                answer.push_back(arr[i]);
        }
        return;
    }
    for(int i=0; i<11; ++i){
        if(i==10 && n>0){
            arr[i] = n;
            comb(0, v);
            arr[i] = 0;
        }
        if(arr[i]==0 && n>v[i]){
            arr[i] = v[i] + 1;
            comb(n - arr[i], v);
            arr[i] = 0;
        }
    }
}

vector<int> solution(int n, vector<int> info) {
    comb(n, info);

    if(max_diff > 0)
        return answer;
    else
        return {-1};
}

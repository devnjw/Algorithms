#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[20];

void select(vector<int> &x, vector<int> &y, int st, int n){
    if(n==0){
        int X = 0;
        for(int i=0; i<x.size(); ++i){
            if(arr[i]==1)
                X += x[i];
        }
        for(int i=0; i<y.size(); ++i){
            if(X==y[i]){
                y.erase(y.begin() + i);
                for(int i=x.size()-1; i>=0; --i)
                    if(arr[i])
                        arr[i] = -1;
            }
        }
    }
    for(int i=st; i<x.size(); ++i){
        if(arr[i]==0){
            arr[i] = 1;
            select(x, y, i+1, n-1);
            if(arr[i] != -1)
                arr[i] = 0;
        }
    }
}

bool CASE(vector<int> x, vector<int> y){
    for(int n=1; n<=x.size(); ++n){
        select(x, y, 0, n);
        if(y.size()==0) return true;
    }

    if(y.size()==0)
        return true;
    else
        return false;
}

vector<bool> solution(vector<vector<int>> p, vector<vector<int>> q) {
    vector<bool> answer;
    for(int t=0; t<p.size(); ++t){
        //sort(p[t].begin(), p[t].end());
        //sort(q[t].begin(), q[t].end());
        if(CASE(p[t], q[t]))
            answer.push_back(true);
        else
            answer.push_back(false);
    }
    return answer;
}

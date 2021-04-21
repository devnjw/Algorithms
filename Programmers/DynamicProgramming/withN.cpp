#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> v;

int answer = -1;

void make_set_and_find(int x, int N, int number) {
    vector<int> tmp;
    int cont = N;
    for(int i=1; i<x; ++i)
        cont = cont * 10 + N;
    tmp.push_back(cont);

    for(int l=1; l<x; ++l){
        int r=x-l;
        for(int j=0; j < v[l-1].size(); ++j){
            for(int k=0; k < v[r-1].size(); ++k){
                tmp.push_back(v[l-1][j]+v[r-1][k]);
                tmp.push_back(v[l-1][j]-v[r-1][k]);
                tmp.push_back(v[l-1][j]*v[r-1][k]);
                if(v[r-1][k]!=0){
                    tmp.push_back(v[l-1][j]/v[r-1][k]);
                }
            }
        }
    }

    std::vector<int>::iterator it;
    it = find(tmp.begin(), tmp.end(), number);
        if (it != tmp.end()){
            answer = x;
            return ;
        }
        else
            v.push_back(tmp);
}

int solution(int N, int number) {
    if(N==number) return 1;

    v.push_back({N});

    for(int i=2; i<9; ++i){
        make_set_and_find(i, N, number);
        if(answer!=-1)
            break;
    }

    return answer;
}

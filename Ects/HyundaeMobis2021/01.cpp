#include <string>
#include <vector>

using namespace std;

int arr[4][6];
int tmp[4];
int nums[10000];

void MAKE(vector<int> &v, int n, int X){
    if(n==0){
        nums[X] = 1;
    }
    for(int i=0; i<n; ++i){
        if(tmp[i]==0){
            tmp[i] = 1;
            MAKE(v, n-1, X*10 + v[i]);
            tmp[i] = 0;
        }
    }
}

void check(int n, vector<vector<int>> &dice){
    if(n==dice.size()){
        vector<int> tmp;
        for(int i=0; i<n; ++i){
            for(int j=0; j<6; ++j){
                if(arr[i][j])
                    tmp.push_back(dice[i][j]);
            }
        }
        MAKE(tmp, n, 0);
        return ;
    }
    for(int i=0; i<6; ++i){
        for(int j=0; j<n; ++j)
            if(arr[j][i])
                i++;
        if(i>=6) continue;
        arr[n][i] = 1;
        check(n+1, dice);
        arr[n][i] = 0;
    }
}

int solution(vector<vector<int>> dice) {

    check(0, dice);

    for(int i=10; i<=99; ++i)
        if(nums[i]==0) return i;
    return -1;
}

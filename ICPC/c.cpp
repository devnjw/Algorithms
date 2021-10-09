#include <bits/stdc++.h>
using namespace std;

int N;
char chars[25];
int nums[25];

long long arr[25];
int reversed[25];

int main(){
    cin >> N;

    for(int i=0; i<N; ++i){
        cin >> chars[i] >> nums[i];
    }

    arr[N-1] = 1;
    if(chars[N-1] == 'B') reversed[N-1] = 1;

    for(int i=N-2; i>=0; --i){
        arr[i] = arr[i+1]*2 + reversed[i+1];
        if(arr[i]%2 == 1 && chars[i] == 'B')
            reversed[i] = 1;
        else if(arr[i]%2 == 0 && chars[i] == 'R')
            reversed[i] = 1;
    }

    long long answer = 0;
    for(int i=0; i<N; ++i){
        answer += (arr[i]+reversed[i]) * nums[i];
    }

    cout << answer;

    return 0;
}

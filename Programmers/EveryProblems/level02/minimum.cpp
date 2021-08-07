#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    if(a>b) return true;
    else return false;
}

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), cmp);

    for(int i=0; i<B.size(); ++i)
        answer += A[i]*B[i];

    return answer;
}

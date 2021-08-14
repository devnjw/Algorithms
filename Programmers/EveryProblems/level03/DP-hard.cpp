// https://programmers.co.kr/learn/courses/30/lessons/12902#
// 3xn Tileing

#include <string>
#include <vector>

using namespace std;

long long arr[5001];

int solution(int n) {
    if(n%2==1) return 0;

    arr[2] = 3;
    for(int i=4; i<=n; i=i+2){
        long long tmp = 0;
        for(int j=2; j<i-2; j=j+2)
            tmp += arr[j];
        arr[i] = arr[i-2]*3 + (tmp + 1)*2;
        arr[i] %= 1000000007;
    }
    return arr[n];
}

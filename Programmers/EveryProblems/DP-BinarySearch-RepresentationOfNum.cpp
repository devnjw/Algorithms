// DP
// 이진탐색, Binary Search
// 숫자의 표현

#include <string>
#include <vector>

using namespace std;

int arr[10001];

int solution(int n) {
    int answer = 0;

    arr[1] = 1;
    for(int i=2; i<=n; ++i)
        arr[i] = arr[i-1] + i;

    int l = n-1, r = n;
    while(l >= 0){
        if(arr[r] - arr[l] == n){
            answer++;
            l--;
        }
        while(arr[r] - arr[l] > n) r--;
        while(arr[r] - arr[l] < n) l--;
    }

    return answer;
}

// DP
// Fibonacci

using namespace std;

int arr[600001];

int solution(int n) {
    arr[1] = 1;
    arr[2] = 2;
    for(int i=3; i<=n; ++i)
        arr[i] = (arr[i-2] + arr[i-1])%1000000007;
    return arr[n];
}

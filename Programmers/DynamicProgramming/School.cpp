#include <string>
#include <vector>

#define MAX 101
using namespace std;

int arr[MAX][MAX];

int solution(int m, int n, vector<vector<int>> puddles) {
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            arr[i][j] = 1;

    for(auto p:puddles)
        arr[p[1]][p[0]] = 0;

    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            if(arr[i][j]==1 && i*j!=1)
                arr[i][j] = (arr[i][j-1] + arr[i-1][j])%1000000007;

    return arr[n][m];
}

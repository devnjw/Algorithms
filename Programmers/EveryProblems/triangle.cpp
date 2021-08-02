#include <string>
#include <vector>

using namespace std;

int arr[1001][1001];
int N;

vector<int> solution(int n) {
    vector<int> answer;
    N = n;

    int r = 0, c = 1;
    int num = 1;
    while(n>0){
        for(int i=0; i<n; ++i)
            arr[++r][c] = num++;
        n--;
        for(int i=0; i<n; ++i)
            arr[r][++c] = num++;
        n--;
        for(int i=0; i<n; ++i)
            arr[--r][--c] = num++;
        n--;
    }

    for(int i=1; i<=N; ++i)
        for(int j=1; j<=N; ++j)
            if(arr[i][j])
                answer.push_back(arr[i][j]);

    return answer;
}

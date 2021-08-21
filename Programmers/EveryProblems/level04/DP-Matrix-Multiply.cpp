// DP 문제
// 최적의 행렬 곱셈..
// 구현이 어려워서 알고리즘 수업 pdf 보고 함..

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int m[201][201];
int p[201];
int N;

void Print(){
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=N; ++j)
            printf("%d ", m[i][j]);
        printf("\n");
    }
    printf("\n");
}

int solution(vector<vector<int>> matrix_sizes) {
    int answer = 0;
    N = matrix_sizes.size();

    p[0] = matrix_sizes[0][0];
    for(int i=1; i<=N; ++i){
        p[i] = matrix_sizes[i-1][1];
    }

    for(int r=2; r<=N; ++r){
        for(int i=1; i<=N-r+1; ++i){
            int j=i+r-1;
            m[i][j] = 2000000000;
            for(int k=i; k<=j-1; ++k){
                m[i][j] = min(m[i][j], m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]);
            }
        }
    }

    return m[1][N];
}

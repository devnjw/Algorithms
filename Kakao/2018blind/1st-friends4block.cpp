#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<char>> v;
int arr[30][30];

void Print(int m, int n){
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            printf("%c ",v[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    for(int i=0; i<n; ++i){
        vector<char> tmp;
        for(int j=m-1; j>=0; --j){
            tmp.push_back(board[j][i]);
        }
        v.push_back(tmp);
    }

    while(1){
        int cnt = 0;
        for(int i=0; i<n-1; ++i){
            for(int j=0; j<m-1; ++j){
                if(v[i][j]!='0'){
                    if(v[i][j]==v[i+1][j]&&v[i][j]==v[i][j+1]&&v[i][j]==v[i+1][j+1]){
                        arr[i][j] = arr[i+1][j] = arr[i][j+1] = arr[i+1][j+1] = 1;
                    }
                }
            }
        }

        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(arr[i][j]){
                    cnt++;
                    v[i][j] = '0';
                    arr[i][j] = 0;
                }
            }
        }

        for(int i=0; i<n; ++i){
            for(int j=m-1; j>=0; --j){
                if(v[i][j]=='0'){
                    for(int k=j; k<m-1; ++k){
                        if(v[i][k+1]=='0')
                            k++;
                        else
                            swap(v[i][k], v[i][k+1]);
                    }
                }
            }
        }

        if(cnt)
            answer += cnt;
        else
            break;
    }

    return answer;
}

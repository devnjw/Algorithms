#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> board[7];
int visited[7][6];
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

bool isValid(int c, int r, int color){
    if(r < 0 || r >= board[c].size())
        return false;
    if(c < 1 || c > 6)
        return false;
    if(board[c][r] != color)
        return false;
    return true;
}

int check(int c, int r, int num){
    int result = num;

    printf("ch: %d %d\n", c, r);

    visited[c][r] = 1;

    for(int i=0; i<4; ++i){
        int x = c+dir[i][0];
        int y = r+dir[i][1];
        if(isValid(x, y, board[c][r])){
            if(visited[x][y] == 0){
                result = max(result, check(x, y, num+1));
            }
        }
    }

    visited[c][r] = 0;

    return result;
}

void remove(int c, int r, int color){
    printf("erase %d %d\n", c, r);
    if(isValid(c, r, color))
        board[c].erase(board[c].begin()+r);

    for(int i=0; i<4; ++i){
        int x = c+dir[i][0];
        int y = r+dir[i][1];
        if(isValid(x, y, board[c][r])){
            remove(x, y, color);
        }
    }
}

void Print(){
    printf("\n");
    for(int i=1; i<=6; ++i){
        printf("%d: ", i);
        for(int j=0; j<board[i].size(); ++j){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

vector<string> solution(vector<vector<int>> macaron) {
    vector<string> answer;

    for(auto m:macaron){
        board[m[0]].push_back(m[1]);
        Print();
        if(check(m[0], board[m[0]].size()-1, 1) >= 3)
            remove(m[0], board[m[0]].size()-1, m[1]);
    }

    Print();

//     for(int i=1; i<=6; ++i){
//         for(int j=0; j<6-board[i].size(); ++j)
//             board[i].push_back(0);
//     }

//     for(int i=0; i<6; ++i){
//         string tmp;
//         for(int j=1; j<=6; ++j){
//             tmp += board[j][i];
//         }
//         answer.push_back(tmp);
//     }

    return answer;
}

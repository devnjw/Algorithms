#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    for(auto b:board) for(auto t:b) if(t) answer=1;

    for(int i=1; i<board.size(); ++i)
        for(int j=1; j<board[0].size(); ++j){
            if(board[i][j]*board[i-1][j]*board[i][j-1]*board[i-1][j-1]){
                board[i][j] = min(min(board[i-1][j], board[i][j-1]), board[i-1][j-1]) + 1;
                if(board[i][j] > answer) answer = board[i][j];
            }
        }

    return answer*answer;
}

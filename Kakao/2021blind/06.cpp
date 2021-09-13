#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    for(auto s:skill){
        for(int r=s[1]; r<=s[3]; ++r){
            for(int c=s[2]; c<=s[4]; ++c){
                if(s[0]==1)
                    board[r][c] -= s[5];
                else
                    board[r][c] += s[5];
            }
        }
    }

    for(int r=0; r<board.size(); r++){
        for(int c=0; c<board[0].size(); ++c){
            if(board[r][c]>0)
                answer++;
        }
    }

    return answer;
}

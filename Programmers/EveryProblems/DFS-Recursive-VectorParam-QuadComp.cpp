// vector 인자를 참조형으로 주지 않으면 매 호출 마다 새로운 vector를 만들어야 해서 시간 초과가 나온다.
// DFS, Recursive

#include <string>
#include <vector>

using namespace std;

vector<int> QuadComp(vector<vector<int>> &arr, int x1, int y1, int x2, int y2){
    if(x1+1==x2&&y1+1==y2){
        if(arr[x1][y1]) return {0, 1};
        else return {1, 0};
    }

    vector<int> q1 = QuadComp(arr, x1, y1, (x1+x2)/2, (y1+y2)/2);
    vector<int> q2 = QuadComp(arr, (x1+x2)/2, y1, x2, (y1+y2)/2);
    vector<int> q3 = QuadComp(arr, x1, (y1+y2)/2, (x1+x2)/2, y2);
    vector<int> q4 = QuadComp(arr, (x1+x2)/2, (y1+y2)/2, x2, y2);

    if(q1[0] && q2[0] && q3[0] && q4[0])
        if(!q1[1] && !q2[1] && !q3[1] && !q4[1])
            return {1, 0};
    if(q1[1] && q2[1] && q3[1] && q4[1])
        if(!q1[0] && !q2[0] && !q3[0] && !q4[0])
            return {0, 1};

    return {q1[0]+q2[0]+q3[0]+q4[0], q1[1]+q2[1]+q3[1]+q4[1]};
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;

    return QuadComp(arr, 0, 0, arr.size(), arr.size());
}

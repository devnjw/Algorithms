#include <string>
#include <vector>

using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    for(int j=0; j<scores.size(); ++j){
        int sum = 0;
        int mn = 100;
        int mx = 0;
        for(int i=0; i<scores[j].size(); ++i){
            if(scores[i][j] < mn && j!=i) mn = scores[i][j];
            if(scores[i][j] > mx && j!=i) mx = scores[i][j];
            sum += scores[i][j];
        }

        int avg;
        if(scores[j][j]<mn || scores[j][j]>mx)
            avg = (sum - scores[j][j]) / (scores[j].size() - 1);
        else
            avg = sum / scores[j].size();

        if(avg < 50) answer += "F";
        else if(avg < 70) answer += "D";
        else if(avg < 80) answer += "C";
        else if(avg < 90) answer += "B";
        else answer += "A";
    }
    return answer;
}

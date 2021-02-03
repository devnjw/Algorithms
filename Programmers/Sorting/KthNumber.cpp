#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;


    for(int i=0; i<commands.size(); i++)
    {
        int s = commands[i][0] - 1;
        int e = commands[i][1];
        int tar = commands[i][2] - 1;
        temp = array;
        sort(&temp[s], &temp[e]);

        answer.push_back(temp[tar+s]);
    }

    return answer;
}

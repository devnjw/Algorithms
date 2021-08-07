#include <string>
#include <vector>

using namespace std;

vector<vector<int>> v;

void Print(){
    for(int i=0; i<v.size(); ++i){
        for(int j=0; j<v[0].size(); ++j)
            printf("%02d ", v[i][j]);
        printf("\n");
    }
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int MAX = rows*columns;

    for(int i=0; i<rows; ++i){
        vector<int> tmp;
        for(int j=1; j<=columns; ++j)
            tmp.push_back(i*columns+j);
        v.push_back(tmp);
    }

    for(auto q:queries){
        for(int i=0; i<4; ++i) q[i]--;
        int temp = v[q[0]][q[3]-1];
        int min = temp;
        // top
        for(int i=q[3]-1; i>q[1]; i--){
            v[q[0]][i] = v[q[0]][i-1];
            if(min>v[q[0]][i]) min = v[q[0]][i];
        }
        // left
        for(int j=q[0]; j<q[2]; j++){
            v[j][q[1]] = v[j+1][q[1]];
            if(min>v[j][q[1]]) min = v[j][q[1]];
        }
        // bottom
        for(int i=q[1]; i<q[3]; i++){
            v[q[2]][i] = v[q[2]][i+1];
            if(min>v[q[2]][i]) min = v[q[2]][i];
        }
        // right
        for(int j=q[2]; j>q[0]; j--){
            v[j][q[3]] = v[j-1][q[3]];
            if(min>v[j][q[3]]) min = v[j][q[3]];
        }
        //right top
        v[q[0]][q[3]] = temp;

        // Print();
        // printf("\n");

        answer.push_back(min);
    }

    return answer;
}

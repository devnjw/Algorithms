#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[5];

vector<string> split(string input, char delimiter=' ') {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    sort(table.begin(), table.end());
    for(int t=0; t<5; ++t){
        for(int i=1; i<=5; ++i){
            for(int l=0; l<languages.size(); ++l){
                if(split(table[t])[i]==languages[l])
                    arr[t] += (6-i)*preference[l];
            }
        }
    }

    return split(table[max_element(arr, arr + 5) - arr])[0];
}

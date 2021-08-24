#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> table;

void Print(){
    for (auto it = table.begin(); it != table.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

vector<int> solution(string msg) {
    vector<int> answer;
    string c = "A";
    for(int i=0; i<26; ++i){
        table[c] = i+1;
        c[0] += 1;
    }

    for(int i=0; i<msg.size(); ++i){
        for(int l=1; l<=msg.size()-i; ++l){
            if(!table.count(msg.substr(i, l))){
                table[msg.substr(i, l)] = table.size() + 1;
                answer.push_back(table[msg.substr(i, l-1)]);
                i += l-2;
                break;
            }
            else if(i+l==msg.size()){
                answer.push_back(table[msg.substr(i, l)]);
                i += l-1;
                break;
            }
        }
    }
    return answer;
}

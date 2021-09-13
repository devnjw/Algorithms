#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<string> split(string input, char delimiter=' ') {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

unordered_map<string, int> hsmap;
unordered_map<string, int> hsmap_user;
unordered_map<string, int> hsmap_report;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    for(auto r:report){
        if(hsmap_report.count(r)==0){
            hsmap_report[r]++;
            hsmap[split(r)[1]]++;
        }
    }

    for(auto r:hsmap_report){
        if(hsmap[split(r.first)[1]] >= k){
            hsmap_user[split(r.first)[0]]++;
        }
    }

    for(auto id:id_list){
        answer.push_back(hsmap_user[id]);
    }

    return answer;
}

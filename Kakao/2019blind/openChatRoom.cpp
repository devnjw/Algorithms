#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

unordered_map<string, string> hsmap;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    for(int i=record.size()-1; i>=0; --i){
        stringstream ss(record[i]);
        string cmd, uid, name;
        getline(ss, cmd, ' ');
        getline(ss, uid, ' ');
        if(cmd == "Leave") continue;
        getline(ss, name, ' ');
        if(hsmap.count(uid)==0)
            hsmap[uid] = name;
    }
    for(auto r:record){
        stringstream ss(r);
        string cmd, uid, name;
        getline(ss, cmd, ' ');
        getline(ss, uid, ' ');
        string str;
        if(cmd=="Enter")
            str = hsmap[uid] + "님이 들어왔습니다.";
        else if(cmd=="Leave")
            str = hsmap[uid] + "님이 나갔습니다.";
        else
            continue;
        answer.push_back(str);
    }
    return answer;
}

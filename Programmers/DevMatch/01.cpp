#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> hsmap;

string recommend_id(string id){
    string S;
    string N;

    int i;
    for(i=0; i<id.size(); ++i){
        if(id[i] < 'a'){
            N.push_back(id[i]);
        }
        else{
            S.push_back(id[i]);
        }
    }

    if(N!="")
        N = to_string(stoi(N) + 1);
    else
        N = "1";

    id = S+N;

    return id;
}

string solution(vector<string> registered_list, string new_id) {
    for(auto id:registered_list)
        hsmap[id]++;

    while(hsmap.count(new_id) > 0){
        new_id = recommend_id(new_id);
    }

    return new_id;
}

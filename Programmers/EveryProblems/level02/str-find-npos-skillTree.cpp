// 8m 55s

#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(auto skill_tree:skill_trees){
        int idx = 0;
        for(auto s:skill_tree){
            if(skill.find(s) != string::npos) {
                if(skill.find(s) == idx)
                    idx++;
                else{
                    idx = -1;
                    break;
                }
            }
        }
        if(idx!=-1)
            answer++;
    }
    return answer;
}

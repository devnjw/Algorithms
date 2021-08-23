// 엣지 케이스 조심..
// [a,a,a,b,b], [a,a,b,b,b]

#include <string>
#include <vector>
#include <cctype>

using namespace std;

vector<string> s1;
vector<string> s2;

int solution(string str1, string str2) {
    float answer = 0;

    for(int i=0; i<str1.size()-1; ++i){
        string tmp;
        if(isalpha(str1[i]) && isalpha(str1[i+1])){
            tmp += toupper(str1[i]);
            tmp += toupper(str1[i+1]);
            s1.push_back(tmp);
        }
    }

    for(int i=0; i<str2.size()-1; ++i){
        string tmp;
        if(isalpha(str2[i]) && isalpha(str2[i+1])){
            tmp += toupper(str2[i]);
            tmp += toupper(str2[i+1]);
            s2.push_back(tmp);
        }
    }

    for(auto s:s1){
        for(auto &c:s2){
            if(s==c){
                answer++;
                c = ' ';
                break;
            }
        }
    }

    if(s1.size()==0 && s2.size()==0)
        answer = 1;
    else
        answer = answer / (s1.size()+s2.size()-answer);

    return (int)(answer * 65536);
}

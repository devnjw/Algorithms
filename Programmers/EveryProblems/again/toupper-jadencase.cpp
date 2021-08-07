// 모범 답안
// To Upper 대문자, 소문자

// #include <string>
// #include <vector>
//
// using namespace std;
//
// string solution(string s) {
//     string answer = "";
//
//     answer += toupper(s[0]);
//     for (int i = 1; i < s.size(); i++)
//         s[i - 1] == ' ' ? answer += toupper(s[i]) : answer += tolower(s[i]);
//
//     return answer;
// }

#include <string>
#include <vector>

using namespace std;

string solution(string s){
    if(s[0] >= 'a' && s[0] <= 'z')
        s[0] -= 0x20;
    for(int i=1; i<s.size(); ++i){
        if(s[i-1] == ' '){
            if(s[i] >= 'a' && s[i] <= 'z')
                s[i] -= 0x20;
        }
        else if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] += 0x20;
        }
    }
    return s;
}

#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<char> st;

int solution(string s) {
    int answer = 0;
    for(int i=0; i<s.size(); ++i){
        for(int j=i; j<i+s.size(); ++j){
            char c = s[j%s.size()];
            if(c == '}' && !st.empty() && st.top() == '{')
                st.pop();
            else if(c == ']' && !st.empty() && st.top() == '[')
                st.pop();
            else if(c == ')' && !st.empty() && st.top() == '(')
                st.pop();
            else
                st.push(c);
        }
        if(st.empty())
            answer++;
        while(!st.empty())
            st.pop();
    }
    return answer;
}

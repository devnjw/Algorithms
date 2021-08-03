#include <string>
#include <iostream>
#include <stack>

using namespace std;

stack<char> st;

bool solution(string s)
{
    for(auto c:s){
        if(c==')'){
            if(!st.empty()&&st.top()=='(')
                st.pop();
            else
                return false;
        }
        else
            st.push(c);
    }

    if(!st.empty())
        return false;

    return true;
}

#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<int> st;

int solution(string s)
{
    for(auto c:s){
        if(!st.empty()&&st.top()==c) st.pop();
        else st.push(c);
    }

    if(st.empty()) return 1;
    else return 0;
}

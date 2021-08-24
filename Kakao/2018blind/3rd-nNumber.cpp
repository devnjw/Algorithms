#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

char arr[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
stack<char> st;

string transferNum(int n, int num){
    if(num==0) return "0";
    string result;
    while(num>0){
        st.push(arr[num%n]);
        num /= n;
    }

    // stack 대신 reverse 도 좋겠네..
    // reverse(result.begin(), result.end());

    while(!st.empty()){
        result += st.top();
        st.pop();
    }
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer;
    string str;

    int num = 0;
    while(str.size()<t*m){
        str += transferNum(n, num);
        num++;
    }

    for(int i=0; i<t; ++i)
        answer += str[p-1+m*i];

    return answer;
}

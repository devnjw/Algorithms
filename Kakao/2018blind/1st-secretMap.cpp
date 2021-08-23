#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    stack<char> st;
    for(int i=0; i<n; ++i){
        string tmp;
        for(int j=0; j<n; ++j){
            if( (arr1[i]%2) + (arr2[i]%2) > 0 )
                st.push('#');
            else
                st.push(' ');
            arr1[i] /= 2;
            arr2[i] /= 2;
        }
        while(!st.empty()){
            tmp += st.top();
            st.pop();
        }
        answer.push_back(tmp);
    }
    return answer;
}

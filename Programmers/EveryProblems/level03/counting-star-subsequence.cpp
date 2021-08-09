#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;

unordered_map<int, int> hsmap;
stack<int> st;

int solution(vector<int> a) {
    int answer = 0;
    int mx = 0;
    int mx_num = a[0];
    int prev01 = -1;
    int prev02 = -2;
    for(auto num:a){
        if(num!=prev01||num!=prev02)
            if(prev01!=num||prev02!=-1)
                hsmap[num]++;
        if(hsmap[num]>mx){
            mx = hsmap[num];
            mx_num = num;
        }
        prev02 = prev01;
        prev01 = num;
    }

    for(auto num:a){
        if(!st.empty()&&st.top()==mx_num&&num!=mx_num){
            answer += 2;
            st.pop();
        }
        else if(!st.empty()&&st.top()!=mx_num&&num==mx_num){
            answer += 2;
            st.pop();
        }
        else if(st.empty()){
            st.push(num);
        }
    }

    return answer;
}

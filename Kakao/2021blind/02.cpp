#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string input, char delimiter=' ') {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        if(!temp.empty())
            answer.push_back(temp);
    }

    return answer;
}

int solution(int n, int k) {
    int answer = 0;

    string s = "";
    while(n){
        s = to_string(n%k) + s;
        n /= k;
    }

    vector<string> v = split(s, '0');

    for(int i=0; i<v.size(); ++i){
        int flag = 1;
        long long num = stoll(v[i]);
        if(num<=1) continue;
        for(long long div=2; div<num/2; ++div){
            if(num%div==0){
                flag = 0;
                //continue;
            }
        }
        if(flag)
            answer++;
    }

    return answer;
}

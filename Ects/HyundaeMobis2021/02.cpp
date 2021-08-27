#include <string>
#include <vector>

using namespace std;

vector<bool> solution(vector<string> a) {
    vector<bool> answer;
    for(auto s:a){
        int cnt=0;
        for(int i=0; i<s.size(); ++i)
            if(s[i]=='a') cnt++;
        int l=0, r=s.size()-1;
        while(1){
            if(l>=r){
                if(s[l] == 'b' || s[r] == 'b')
                    answer.push_back(false);
                else
                    answer.push_back(true);
                break;
            }

            if(s[l]=='b'&&s[r]=='b'){
                if(cnt==0){
                    answer.push_back(false);
                    break;
                }
                for(int i=0; i<cnt; ++i){
                    if(s[l]=='b'&&s[r]=='b'){
                        r--;
                        l++;
                    }
                    else{
                        answer.push_back(false);
                        l = -1;
                        break;
                    }
                }
                if(l==-1) break;
            }
            else if(s[l]=='a'){
                l++;
                cnt--;
            }
            else if(s[r]=='a'){
                r--;
                cnt--;
            }
        }
    }
    return answer;
}

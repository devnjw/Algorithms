#include <string>
#include <vector>

using namespace std;

int countLeft(vector<int> v, int index){
    int cnt = 0;
    while(cnt!=v.size()-1){
        if(index==0) index = v.size() - 1;
        else index--;

        if(v[index]==0) cnt++;
        else break;
    }
    return cnt;
}

int countRight(vector<int> v, int index){
    int cnt = 0;
    while(cnt!=v.size()-1){
        if(index==v.size() - 1) index = 0;
        else index++;

        if(v[index]==0) cnt++;
        else break;
    }
    return cnt;
}

int solution(string name) {
    int answer = 0;
    vector<int> v;

    for(const auto ch : name)
        v.push_back((int)ch - (int)'A') ;

    int index = 0;

    while(1){
        if(v[index]>12)
            answer+=26-v[index];
        else answer+=v[index];
        v[index]=0;

        if(countRight(v, 0)==v.size()-1) break;

        if(countLeft(v, index)>=countRight(v, index))
            while(v[index]==0 && countLeft(v, 0)!=v.size()-1){
                if(index==v.size()-1)
                    index = 0;
                else
                    index++;
                answer++;
            }
        else
            while(v[index]==0 && countRight(v, 0)!=v.size()-1){
                if(index==0)
                    index = v.size()-1;
                else
                    index--;
                answer++;
            }
    }

    return answer;
}

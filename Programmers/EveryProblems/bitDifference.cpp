#include <string>
#include <vector>

using namespace std;

long long Func(long long num){
    long long cnt = 1;
    while(1){
        if(num%2==0){
            return cnt - cnt/2;
        }
        else{
            num /= 2;
            cnt *= 2;
        }
    }
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(auto num:numbers){
        answer.push_back(num+Func(num));
    }
    return answer;
}

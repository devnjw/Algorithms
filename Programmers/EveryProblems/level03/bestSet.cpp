#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    if(s/n==0) return {-1};
    vector<int> answer;
    for(int i=0; i<n; ++i){
        if(i<n-s%n)
            answer.push_back(s/n);
        else
            answer.push_back(s/n+1);
    }
    return answer;
}

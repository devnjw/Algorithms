#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> v(n+2, 1);
    v[0]=0;
    v[n+1]=0;

    // for(int i : reserve) student[i] += 1; Loop를 이렇게도 작성할 수 있구나... (모범답안참조)
    for(int i=0; i<lost.size(); ++i)
       v[lost[i]]--;
    for(int i=0; i<reserve.size(); ++i)
        v[reserve[i]]++;

    for(int i=1; i<n; ++i){
        if(v[i]==0 && v[i+1]==2){
            v[i]++;
            v[i+1]--; // v[i] = v[i+1] = 1; 이렇게도 작성할 수 있다. (모범답안참조)
        }
        else if(v[i]==2&&v[i+1]==0){
            v[i]--;
            v[i+1]++;
        }
    }

    for(const auto it : v)
        if(it>=1) answer++;

    return answer;
}

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int arr[5] = {781, 156, 31, 6, 1};

int solution(string word) {
    int answer = 0;
    for(int i=0; i<word.size(); ++i){
        if(word[i]=='E')
            answer += arr[i]*1;
        else if(word[i]=='I')
            answer += arr[i]*2;
        else if(word[i]=='O')
            answer += arr[i]*3;
        else if(word[i]=='U')
            answer += arr[i]*4;
    }
    answer += word.size();
    return answer;
}

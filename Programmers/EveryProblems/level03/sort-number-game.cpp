#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int a = 0, b = 0;
    while(b<B.size()){
        if(B[b]>A[a]){
            answer++;
            a++;
        }
        b++;
    }
    return answer;
}

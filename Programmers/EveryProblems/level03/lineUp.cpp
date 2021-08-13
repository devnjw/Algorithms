#include <string>
#include <vector>

using namespace std;

int visited[21];
int N;

int NthNum(int n){
    for(int i=1; i<=N; ++i){
        if(visited[i]==0){
            n--;
            if(n==0){
                visited[i] = 1;
                return i;
            }
        }
    }
}

long long Fact(long long num){
    if(num<=1) return 1;
    else return num * Fact(num-1);
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    N = n;
    while(n){
        int num = NthNum(((k-1)/Fact(n-1))+1);
        answer.push_back(num);
        k = (k-1)%Fact(n-1)+1;
        n--;
    }
    return answer;
}

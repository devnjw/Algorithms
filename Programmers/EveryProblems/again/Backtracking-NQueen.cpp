// Backtracking

#include <string>
#include <vector>
#define MAX 12

using namespace std;

int Y[MAX];
int XmY[2*MAX];
int XpY[2*MAX];
int answer;

void Search(int n, int curr){
    int i = curr-1;
    for(int j=0; j<n; ++j){
        if(Y[j]==0 && XmY[n+i-j]==0 && XpY[i+j]==0){
            if(curr==n){
                answer++;
            }
            else{
                Y[j] = 1;
                XmY[n+i-j] = 1;
                XpY[i+j] = 1;
                Search(n, curr+1);
                Y[j] = 0;
                XmY[n+i-j] = 0;
                XpY[i+j] = 0;
            }
        }
    }
}

int solution(int n) {
    Search(n, 1);
    return answer;
}

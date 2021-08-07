#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = -1;
    int cnt = 0;

    int l = 1;
    int r = n;

    while(r>l){
        n = (l+r)/2;
        if(answer==-1){
            if(a<=n&&b>n) answer = cnt;
            else if(a>n&&b<=n) answer = cnt;
        }
        if(a<=n)
            r = n;
        else
            l = n+1;

        cnt++;
    }

    return cnt - answer;
}

// 괜히 쫄았다...

#include <vector>

using namespace std;

int CountBinary(int num){
    int cnt = 0;
    while(num > 0){
        if(num%2==1) cnt++;
        num /= 2;
    }
    return cnt;
}

int solution(int n) {
    int answer = 1;
    int tmp = CountBinary(n);
    while(1){
        n++;
        if(tmp == CountBinary(n)){
            return n;
        }
    }
}

#include <bits/stdc++.h>
using namespace std;
int W, H, L;

bool isValid(int x, int y){
    if(x*x+y*y <= L*L){
        return true;
    }
    return false;
}

long long spaceX(int l){
    long long answer = 0;
    int x = l;
    int y = 0;
    while(x>=0){
        while(isValid(x, y+1)){
            y++;
        }
        answer += y;
        x--;
    }
    return answer;
}

bool isValid2(int x1, int y1, int x2, int y2, int l){
    if((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1) <= l)
        return true;
    return false;
}

int main(){
    int answer = 0;
    cin >> W >> H >> L;

    answer += spaceX(L)*3 - L;

    if(L > W){
        answer += spaceX(L-W);
    }
    if(L > H){
        answer += spaceX(L-H);
    }
    if(L > W+H){
        int x = L-H-1;
        int y = H+1;
        while(x>L){
            while(isValid2(W, 0, x, y, L-W) && isValid2(0, H, x, y, L-H)){
                y++;
            }
            answer -= y-H-1;
            x--;
        }
    }

    cout << answer;

    return 0;
}

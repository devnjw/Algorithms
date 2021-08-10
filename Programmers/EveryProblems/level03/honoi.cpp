#include <string>
#include <vector>

using namespace std;

int arr[16];
vector<vector<int>> answer;

void AtoB(int x, int y, int n){
    if(n==1) answer.push_back({x, y});
    else{
        int z;
        if(x*y==2) z=3;
        else if(x*y==3) z=2;
        else if(x*y==6) z=1;

        AtoB(x, z, n-1);
        AtoB(x, y, 1);
        AtoB(z, y, n-1);
    }
}

vector<vector<int>> solution(int n) {
    AtoB(1, 3, n);
    return answer;
}

// 인상 깊었던 다른 사람 풀이
// #include <string>
// #include <vector>
// #include <algorithm>
//
// using namespace std;
//
// int gcd(int x, int y) { return x % y == 0 ? y : gcd(y, x % y); }
// int lcm(int x, int y) { return x * y / gcd(x, y); }
// int solution(vector<int> arr) {
//     int answer = arr[0];
//     for (int i = 1; i < arr.size(); i++)
//         answer = lcm(answer, arr[i]);
//     return answer;
// }

//내 풀이
// 최소공배수, 최대공약수
#include <vector>

using namespace std;

int facts[101];

int solution(vector<int> arr) {
    int answer = 1;
    for(auto n:arr){
        for(int i=2; i<=n; ++i){
            int cnt = 0;
            while(n%i==0){
                n/=i;
                cnt++;
            }
            if(cnt>facts[i]) facts[i]=cnt;
        }
    }
    for(int i=2; i<=100; ++i){
        if(facts[i]){
            for(int j=0; j<facts[i]; ++j)
                answer *= i;
        }
    }
    return answer;
}

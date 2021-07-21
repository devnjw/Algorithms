#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    string numbers = "412";

    while(n>0){
        answer = numbers[n%3] + answer;
        if(n % 3 == 0) n--;
        n /= 3;
    }

    return answer;
}

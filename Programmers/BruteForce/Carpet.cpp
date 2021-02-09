#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int x = 3; x < brown; ++x){
        for(int y = 3; y < brown; ++y){
            if(x*y - (x-2)*(y-2) == brown && (x-2)*(y-2) == yellow){
                answer.push_back(y);
                answer.push_back(x);
                return answer;
            }
        }
    }
    return answer;
}

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int distance(int x, int y){
    int dis = 0;
    dis += abs((y+2)%3 - (x+2)%3);
    dis += abs((y-1)/3 - (x-1)/3);
    return dis;
}


string solution(vector<int> numbers, string hand) {
    int left = 10;
    int right = 12;
    string answer = "";

    for(int i=0; i<numbers.size(); ++i){
        if(numbers[i]==0) numbers[i] = 11;
        if(numbers[i]%3 == 0){
            answer.append("R");
            right = numbers[i];
        }
        else if(numbers[i]%3 == 1){
            answer.append("L");
            left = numbers[i];
        }
        else if(distance(numbers[i], left) > distance(numbers[i], right)){
            answer.append("R");
            right = numbers[i];
        }
        else if(distance(numbers[i], left) < distance(numbers[i], right)){
            answer.append("L");
            left = numbers[i];
        }
        else if(hand=="right"){
            answer.append("R");
            right = numbers[i];
        }
        else{
            answer.append("L");
            left = numbers[i];
        }
    }
    return answer;
}

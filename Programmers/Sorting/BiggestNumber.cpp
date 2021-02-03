#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int digit_of_num(int num){
    int digit = 1;
    while(num>=10){
        num/=10;
        digit++;
    }
    return digit;
}

int encode(int num){
    if(num < 10) num = num*1000 + num*100 + num*10 + num;
    else if(num < 100) num = num*100 + num;
    else if(num < 1000) num = num*10 + num/100;
    return num;
}

bool compare(int a, int b){
    if(encode(a) > encode(b))
        return true;
    else if(encode(a) == encode(b))
        return digit_of_num(a) > digit_of_num(b);
    else return false;
}

string solution(vector<int> numbers) {
    string answer = "";

    sort(numbers.begin(), numbers.end(), compare);
    if(numbers.at(0)==0) return "0";
    for(int i=0; i<numbers.size(); ++i){
        answer.append(to_string(numbers.at(i)));
    }

    return answer;
}

//-----------Better Code from Others-------------//
bool Compare(const string &a, const string &b)
{
    if (b + a < a + b) //깔... 끔....
        return true;
    return false;
}

string Solution(vector<int> numbers) {
    string answer = "";

    vector<string> strings;

    for (int i : numbers)
        strings.push_back(to_string(i));

    sort(strings.begin(), strings.end(), Compare);

    for (auto iter = strings.begin(); iter < strings.end(); ++iter)
        answer += *iter; //이 부분도 참고하기

    if (answer[0] == '0')
        answer = "0";

    return answer;
}

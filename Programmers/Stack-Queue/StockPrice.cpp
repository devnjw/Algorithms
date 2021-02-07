#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

typedef struct Item
{
    int value;
    int order;
}item;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<item> s;
    for(int i=0; i<prices.size(); ++i){
        Item temp = {prices[i], i};
        while(!s.empty() && s.top().value > temp.value){
            answer.at(s.top().order) = temp.order - s.top().order;
            s.pop();
        }
        s.push(temp);
    }
    while(!s.empty()){
        answer.at(s.top().order) = prices.size() - s.top().order - 1;
        s.pop();
    }

    return answer;
}

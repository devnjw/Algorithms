#include <string>
#include <vector>

using namespace std;

int cnt = 0;
int TARGET;

int SUM(vector<int> numbers){
    int result = 0;
    for(auto i : numbers)
        result += i;

    return result;
}

void DFS(vector<int> numbers, int index){
    if(index==numbers.size()) return;

    DFS(numbers, index+1);

    numbers[index] = -numbers[index];

    if(SUM(numbers)==TARGET) cnt++;
    DFS(numbers, index+1);
}

int solution(vector<int> numbers, int target) {
    TARGET = target;

    if(SUM(numbers)==TARGET) cnt++;
    DFS(numbers, 0);

    return cnt;
}

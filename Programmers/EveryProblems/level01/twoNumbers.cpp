#include <string>
#include <vector>

using namespace std;

int arr[201];

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for(int i=0; i<numbers.size()-1; ++i){
        for(int j=i+1; j<numbers.size(); ++j){
            arr[numbers[i]+numbers[j]] = 1;
        }
    }
    for(int i=0; i<=200; ++i)
        if(arr[i])
            answer.push_back(i);
    return answer;
}

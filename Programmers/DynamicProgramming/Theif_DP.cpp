#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr1[1000000];
int arr2[1000000];

int solution(vector<int> money) {
    if(money.size() <= 3) return *max_element(money.begin(), money.end());
    arr1[0] = money[0];
    arr2[1] = money[1];
    arr1[2] = money[0]+money[2];
    arr2[2] = money[2];
    for(int i=3; i<money.size()-1; ++i){
        arr1[i] = max(arr1[i-3], arr1[i-2]) + money[i];
    }
    for(int i=3; i<money.size(); ++i){
        arr2[i] = max(arr2[i-3], arr2[i-2]) + money[i];
    }
    return max(*max_element(arr1, arr1+money.size()), *max_element(arr2, arr2+money.size()));
}

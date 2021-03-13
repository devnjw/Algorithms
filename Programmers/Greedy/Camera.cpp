#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end(), compare);

    int answer = 1;
    int curr = routes[0][1];

    for(auto it:routes){
        if(it[0]>curr){
            answer++;
            curr = it[1];
        }
    }
    return answer;
}

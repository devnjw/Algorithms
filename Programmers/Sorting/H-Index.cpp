#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp (int a, int b){
    return a > b;
}

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), cmp);
    int h = 1;
    while(citations[h-1] >= h)
        h++;
    return --h;
}

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int MIN;

void merge(vector<int> v, int l, int r, int n);
void search(vector<int> v, int n);

void search(vector<int> v, int n){
    int minElementIndex = min_element(v.begin(),v.end()) - v.begin();
    int minElement = *min_element(v.begin(), v.end());

    if(minElement > MIN) MIN = minElement;

    if(n == 0) return;


    if(minElementIndex==0){
        merge(v, 0, 1, n);
    }
    else if(minElementIndex==v.size()-1){
        merge(v, v.size()-2, v.size()-1, n);
    }
    else{
        merge(v, minElementIndex, minElementIndex + 1, n);
        merge(v, minElementIndex - 1, minElementIndex, n);
    }
}

void merge(vector<int> v, int l, int r, int n){
    v[l] = v[l] + v[r];
    v.erase(v.begin()+r);
    search(v, n-1);
}

int solution(int distance, vector<int> rocks, int n) {
    rocks.push_back(0);
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());

    vector<int> diff;
    for(int i=1; i<rocks.size(); ++i)
        diff.push_back(rocks[i]-rocks[i-1]);

    MIN = *min_element(diff.begin(), diff.end());
    search(diff, n);

    for(auto it: diff) cout << it << " ";
    cout << endl;

    return MIN;
}

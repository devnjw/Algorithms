// Binary Search 이분탐색

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1000000];

int solution(vector<int> a) {
    int answer = 0;
    for(int i=0; i<a.size(); ++i)
        arr[i] = 1;

    int mindex = min_element(a.begin(), a.end()) - a.begin();
    int l = 1;
    int r = a.size() - 2;

    while(l<mindex){
        if(a[l]>a[l-1]){
            arr[l] = 0;
            a[l] = a[l-1];
        }
        l++;
    }
    while(r>mindex){
        if(a[r]>a[r+1]){
            arr[r] = 0;
            a[r] = a[r+1];
        }
        r--;
    }
    for(int i=0; i<a.size(); ++i)
        if(arr[i])
            answer++;
    return answer;
}

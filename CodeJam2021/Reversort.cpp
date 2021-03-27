#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    int T, N, tmp;
    cin >> T;
    for(int i=0; i<T; ++i){
        int answer = 0;
        cin >> N;
        vector<int> v;
        for(int j=0; j<N; ++j){
            cin >> tmp;
            v.push_back(tmp);
        }

        for(int j=0; j<N-1; ++j){
            answer++;
            int mindex = min_element(v.begin()+j, v.end()) - v.begin();
            int st = j;
            while(mindex > st){
                if(mindex > st+1)
                    answer++;
                swap(v[st++], v[mindex--]);
                answer++;
            }
        }

        printf("Case #%d: %d\n",i+1, answer);
    }

    return 0;
}

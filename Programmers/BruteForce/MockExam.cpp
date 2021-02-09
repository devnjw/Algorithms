#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> index = {1, 2, 3};
    vector<int> cnt = {0, 0, 0};

    vector<int> p1 = {1,2,3,4,5};
    vector<int> p2 = {2,1,2,3,2,4,2,5};
    vector<int> p3 = {3,3,1,1,2,2,4,4,5,5};

    for(int i=0; i<answers.size(); ++i){
        if(answers[i]==p1[i%p1.size()])
            cnt[0]++;
        if(answers.at(i)==p2[i%p2.size()])
            cnt[1]++;
        if(answers.at(i)==p3[i%p3.size()])
            cnt[2]++;
    }

    // 베스트답안을 보니 max_element()라는 함수가 있다.
    // int max_index = max_element(v.begin(), v.end); 와 같이 작성하면 보다 깔끔하게 짤 수 있다.
    for(int i=1; i<cnt.size(); ++i){
        if(cnt[0]<cnt[i]){
            swap(cnt[0], cnt[i]);
            swap(index[0], index[i]);
        }
    }
    answer.push_back(index[0]);
    for(int i=1; i<index.size(); ++i){
        if(cnt[0]==cnt[i])
            answer.push_back(index[i]);
    }


    return answer;
}

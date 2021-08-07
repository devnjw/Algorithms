#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, string> refers;
unordered_map<string, int> sales;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;

    for(int i=0; i<referral.size(); ++i){
        refers[enroll[i]] = referral[i];
        sales[enroll[i]] = 0;
    }

    for(int i=0; i<seller.size(); ++i){
        amount[i] *= 100;
        string next_person = seller[i];
        while(next_person!="-" && amount[i]){
            sales[next_person] += amount[i] - amount[i] / 10;
            next_person = refers[next_person];
            amount[i] /= 10;
        }
    }

    for(int i=0; i<enroll.size(); ++i){
        answer.push_back(sales[enroll[i]]);
    }
    return answer;
}

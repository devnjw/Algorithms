#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    int cnt = 0;

    for(int i=0; i<number.size()-1; ++i){
        while(number[i] < number[i+1] && cnt < k){
            number.erase(number.begin()+i);
            cnt++;
            if(i!=0 && number[i-1]<number[i])
                i--;
        }
    }
    while(cnt++<k)
        number.erase(number.begin()+number.size()-1);

    return number;
}

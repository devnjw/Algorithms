#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

unordered_map<string, int> hsmap_time;
unordered_map<string, int> total_time;
vector<string> cars;

vector<string> split(string input, char delimiter=' ') {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

int toTime(string str){
    return 60*stoi(split(str, ':')[0]) + stoi(split(str, ':')[1]);
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    for(auto record:records){
        int Time = toTime(split(record)[0]);
        string car_num = split(record)[1];

        if(total_time.count(car_num)==0){
            cars.push_back(car_num);
            total_time[car_num] = 0;
        }

        if(split(record)[2] == "IN"){
            hsmap_time[car_num] = Time;
        }
        else{
            total_time[car_num] += Time - hsmap_time[car_num];
            hsmap_time.erase(car_num);
        }
    }

    for(auto t:hsmap_time){
        total_time[t.first] += toTime("23:59") - t.second;
    }

    sort(cars.begin(), cars.end());
    for(auto car:cars){
        int fee = fees[1];
        total_time[car] -= fees[0];
        if(total_time[car]>0){
            if(total_time[car]%fees[2])
                total_time[car] += fees[2];
            fee += total_time[car]/fees[2]*fees[3];
        }
        answer.push_back(fee);
    }

    return answer;
}

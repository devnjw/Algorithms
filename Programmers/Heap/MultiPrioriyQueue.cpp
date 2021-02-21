#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

priority_queue< int, vector<int>, greater<int> > minh;
priority_queue< int, vector<int>, less<int> > maxh;

vector<string> split(string input, char delimiter);

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int size = 0;

    for(int i=0; i<operations.size(); ++i){

        vector<string> result = split(operations[i], ' ');
        if(size==0){
            while(!minh.empty()) minh.pop();
            while(!maxh.empty()) maxh.pop();
        }

        if(result[0] == "I"){
            minh.push(stoi(result[1]));
            maxh.push(stoi(result[1]));
            size++;
        }
        else if(size > 0){
            if(result[1] == "1"){
                maxh.pop();
                size--;
            }
            else if(result[1] == "-1"){
                minh.pop();
                size--;
            }
        }
    }
    if(size<=0){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(maxh.top());
        answer.push_back(minh.top());
    }

    return answer;
}

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

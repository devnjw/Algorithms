#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> split(string input, char delimiter){
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while(getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

struct Music{
    int time;
    string title;
    string melody;
};

// input string format -> HH:mm
// output integer -> mm
int duration(string start_time, string end_time){
    int answer = 0;
    int start_H = stoi(split(start_time, ':')[0]);
    int end_H = stoi(split(end_time, ':')[0]);
    int start_m = stoi(split(start_time, ':')[1]);
    int end_m = stoi(split(end_time, ':')[1]);

    if(start_H <= end_H) answer += 60 * (end_H - start_H);
    else answer += 60 * (24 + end_H - start_H);

    if(start_m <= end_m) answer += end_m - start_m;
    else answer += 60 + end_m - start_m;

    return answer;
}

string get_melody(string melody, int time){
    string answer = "";
    int index = 0;
    for(int i=0; i<time; ++i){
        if(index+1!=melody.size() && melody[index+1]=='#'){
            answer += (melody[index] + 32);
            index = (index + 2)%melody.size();
        }
        else{
            answer += melody[index];
            index = (index + 1)%melody.size();
        }
    }
    return answer;
}

string parsing(string m){
    string answer = "";
    for(int i=0; i<m.size(); ++i){
        if(i+1!=m.size() && m[i+1]=='#'){
            answer += m[i] + 32;
            i++;
        }
        else answer += m[i];
    }
    return answer;
}

int KMP(string str, string key){
    for(int i=0; i<str.size(); ++i){
        if(str[i]==key[0]){
            for(int j=1; j<key.size(); ++j){
                if(str[++i]!=key[j]) break;
                else if(j==key.size()-1) return i - j;
            }
        }
    }

    return -1;
}

int cmp(Music m1, Music m2){
    if(m1.time > m2.time) return true;
    return false;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    vector<Music> musics;
    for(auto info:musicinfos){
        vector<string> splited_info = split(info, ',');
        int time = duration(splited_info[0], splited_info[1]);
        string title = splited_info[2];
        string melody = get_melody(splited_info[3], time);
        musics.push_back({time, title, melody});
    }
    m = parsing(m);

    sort(musics.begin(), musics.end(), cmp);

    for(auto music:musics){
        if(KMP(music.melody, m)!=-1){
            answer = music.title;
            break;
        }
    }

    return answer;
}

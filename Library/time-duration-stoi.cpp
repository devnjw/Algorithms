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

#include <string>
#include <vector>

using namespace std;

int days[30];
int maxdays = 0;

void DFS(int leave, int day){
    if(leave==0){
        int cnt = 0;
        for(int i=0; i<30; ++i){
            if(days[i]){
                cnt++;
                if(maxdays<cnt){
                    maxdays = cnt;
                }
            }
            else
                cnt = 0;
        }
        return;
    }

    for(int i=day; i<30; ++i){
        if(days[i] == 0){
            days[i] = 1;
            DFS(leave-1, i+1);
            days[i] = 0;
        }
    }
}

int solution(int leave, string day, vector<int> holidays) {
    int tmp;
    if(day=="MON"){
        tmp = 0;
    }
    else if(day=="TUE"){
        tmp = 1;
    }
    else if(day=="WED"){
        tmp = 2;
    }
    else if(day=="THU"){
        tmp = 3;
    }
    else if(day=="FRI"){
        tmp = 4;
    }
    else if(day=="SAT"){
        tmp = 5;
    }
    else if(day=="SUN"){
        tmp = 6;
    }

    int total=0;

    for(int i=0; i<30; ++i){
        if((tmp+i)%7 >= 5){
            days[i] = 1;
            total++;
        }
    }

    for(auto holiday:holidays){
        if(days[holiday-1]==0) total++;
        days[holiday-1] = 1;
    }

    if(30 - total <= leave)
        return 30;

    DFS(leave, 0);

    return maxdays;
}

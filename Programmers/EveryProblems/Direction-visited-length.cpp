// 방문 길이
// 방향
// visited check

#include <string>
using namespace std;

int arr[11][11][4];

int solution(string dirs) {
    int answer = 0;

    int x = 5, y = 5;

    for(auto dir:dirs){
        if(dir=='U'&&y<10){
            arr[x][y][0] = 1;
            y++;
            if(!arr[x][y][2]){
                answer++;
                arr[x][y][2] = 1;
            }
        }
        else if(dir=='D'&&y>0){
            arr[x][y][2] = 1;
            y--;
            if(!arr[x][y][0]){
                answer++;
                arr[x][y][0] = 1;
            }
        }
        else if(dir=='R'&&x<10){
            arr[x][y][1] = 1;
            x++;
            if(!arr[x][y][3]){
                answer++;
                arr[x][y][3] = 1;
            }
        }
        else if(dir=='L'&&x>0){
            arr[x][y][3] = 1;
            x--;
            if(!arr[x][y][1]){
                answer++;
                arr[x][y][1] = 1;
            }
        }
    }

    return answer;
}

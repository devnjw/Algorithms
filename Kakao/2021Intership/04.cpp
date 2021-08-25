#include <string>
#include <vector>

using namespace std;

#define MAXSIZE 1000

int arr0[MAXSIZE+1][MAXSIZE+1];
int arr1[MAXSIZE+1][MAXSIZE+1];

int visited0[MAXSIZE+1];
int visited1[MAXSIZE+1];

int isTrap[MAXSIZE+1];

int answer = 9000000;
int SIZE;


void Print(){
    for(int i=1; i<=SIZE; ++i){
        for(int j=1; j<=SIZE; ++j){
            printf("%d ", arr0[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=1; i<=SIZE; ++i){
        for(int j=1; j<=SIZE; ++j){
            printf("%d ", arr1[i][j]);
        }
        printf("\n");
    }
}

void Reverse(int position){
    for(int i=1; i<=SIZE; ++i){
        swap(arr0[position][i], arr0[position][i])
    }
}

void DFS(int position, int t, int end){
    printf("Enter %d %d %d %d %d\n", position, isTrap[position], t, end, visited0[position]);

    if(isTrap[position] >= 0 && visited0[position]) return;
    else if(isTrap[position] < 0 && visited1[position]) return;

    if(position == end){
        if(answer > t) answer = t;
        return ;
    }

    if(isTrap[position] >= 0){
        visited0[position] = 1;
        for(int i=1; i<=SIZE; ++i){
            if(arr0[position][i]){
                t += arr0[position][i];
                printf("debug %d %d %d\n", position, isTrap[position], i);
                if(!isTrap[i])
                    DFS(i, t, end);
                else{
                    isTrap[i] *= -1;
                    DFS(i, t, end);
                    isTrap[i] *= -1;
                }
                t -= arr0[position][i];
            }
        }
        visited0[position] = 0;
    }
    else{
        visited1[position] = 1;
        for(int i=1; i<=SIZE; ++i){
            if(arr1[position][i]){
                t += arr1[position][i];
                printf("debug %d %d %d\n", position, isTrap[position], i);
                if(!isTrap[i])
                    DFS(i, t, end);
                else{
                    isTrap[i] *= -1;
                    DFS(i, t, end);
                    isTrap[i] *= -1;
                }
                t -= arr1[position][i];
            }
        }
        visited1[position] = 0;
    }
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    SIZE = n;

    for(auto trp:traps)
        isTrap[trp] = 1;

    for(auto road:roads){
        arr0[road[0]][road[1]] = road[2];
        arr1[road[1]][road[0]] = road[2];
    }

    Print();

    DFS(start, 0, end);

    return answer;
}

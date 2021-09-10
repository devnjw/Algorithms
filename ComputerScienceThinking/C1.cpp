#include <iostream>
#define MAXNUM 2000

using namespace std;

int cntFriends[MAXNUM+1];
int arr[MAXNUM+1][MAXNUM+1];
int N, K, F;

int main(){
  cin >> N >> K >> F;

  int a, b;
  for(int i=0; i<F; ++i){
    cin >> a >> b;
    arr[a][b]++;
    arr[b][a]++;
    cntFriends[a]++;
    cntFriends[b]++;
  }

  int flag;
  do{
    flag = 0;
    for(int i=1; i<=N; ++i){
      if(cntFriends[i] > 0 && cntFriends[i] < K){
        flag = 1;
        cntFriends[i] = 0;
        for(int j=1; j<=N; ++j){
          if(arr[i][j]){
            cntFriends[j]--;
            arr[i][j] = 0;
          }
        }
      }
    }
  }while(flag);

  int answer = 0;
  for(int i=1; i<=N; ++i)
    if(cntFriends[i] >= K)
      answer++;

  cout << answer;

  return 0;
}

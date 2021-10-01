#include <iostream>
#define SIZE 50

using namespace std;

int N, K;
long long hanoi[SIZE];
int curr_rod[SIZE+1];

long long gather(int disk, int dest){
  if(disk==0)
    return 0;
  if(curr_rod[disk]==dest)
    return gather(disk-1, dest);

  int rest;
  for(rest=0; rest<3; ++rest)
    if(rest!=dest && rest!=curr_rod[disk])
      break;

  return gather(disk-1, rest) + 1 + hanoi[disk-1];
}

int main(){
  cin >> N >> K;

  hanoi[0] = 0;
  for(int i=1; i<=N; ++i)
    hanoi[i] = (hanoi[i-1]+1)*2 - 1;

  int n, tmp;
  for(int i=0; i<3; ++i){
    cin >> n;
    for(int j=0; j<n; ++j){
      cin >> tmp;
      curr_rod[tmp] = i;
    }
  }

  cout << gather(N, K-1);

  return 0;
}

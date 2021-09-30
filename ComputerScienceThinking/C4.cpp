#include <iostream>
#define SIZE 50

using namespace std;

struct Stack{
  int arr[SIZE];
  int tp;
  bool empty(){
    if(tp==0)
      return true;
    else
      return false;
  }
  void init(){
    tp = 0;
  }
  void push(int data){
    arr[tp] = data;
    tp++;
  }
  void pop(){
    tp--;
  }
  int top(){
    return arr[tp-1];
  }
};

int N, K;
long long answer;
long long hanoi[SIZE];
int curr_rod[SIZE+1];
Stack rods[3];

void move(int tar_rod, int disk);
void gather(int tar_rod, int dist);
void moveOne(int tar_rod, int disk);
void moveAll(int curr_rod, int tar_rod, int disk);
void Print();

int main(){
  for(int i=0; i<3; ++i){
    rods[i].init();
  }

  cin >> N >> K;

  hanoi[0] = 1;
  for(int i=1; i<=N; ++i)
    hanoi[i] = hanoi[i-1]*2;

  int n, tmp;
  for(int i=0; i<3; ++i){
    cin >> n;
    for(int j=0; j<n; ++j){
      cin >> tmp;
      rods[i].push(tmp);
      curr_rod[tmp] = i;
    }
  }

  gather(K-1, N);

  cout << answer;

  return 0;
}

void move(int tar_rod, int disk){
  if(curr_rod[disk]==tar_rod)
    return;
  if(disk==1){
    moveOne(tar_rod, disk);
    return;
  }

  int tmp_rod;
  for(tmp_rod=0; tmp_rod<3; tmp_rod++)
    if(tmp_rod!=curr_rod[disk] && tmp_rod!=tar_rod)
      break;

  gather(tmp_rod, disk-1);
  moveOne(tar_rod, disk);
  moveAll(tmp_rod, tar_rod, disk-1);
}

void gather(int tar_rod, int disk){
  for(int d=disk; d>=1; --d){
    move(tar_rod, d);
  }
}

void moveOne(int tar_rod, int disk){
  answer++;
  rods[tar_rod].push(disk);
  rods[curr_rod[disk]].pop();
  curr_rod[disk] = tar_rod;
}

void moveAll(int c_rod, int tar_rod, int disk){
  answer += hanoi[disk] - 1;

  for(int i=rods[c_rod].tp - disk; i<rods[c_rod].tp; ++i){
    rods[tar_rod].push(rods[c_rod].arr[i]);
    curr_rod[rods[c_rod].arr[i]] = tar_rod;
  }

  for(int i=0; i<disk; ++i){
    rods[c_rod].pop();
  }
}

void Print(){
  printf("-------------\n");
  for(int i=0; i<3; ++i){
    for(int j=0; j<rods[i].tp; ++j){
      cout << rods[i].arr[j] << " " ;
    }
    cout << endl;
  }
  printf("-------------\n");
}

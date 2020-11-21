#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int origin;
int maxmin = 999999;

void func(int num, int index, int len);
int swap_int(int num, int p1, int p2);
void check(int num, int len);

int main() {
  int N;
  cin >> N;
  origin = N;

  int len = 0;
  while(N>0){
    len++;
    N /= 10;
  }

  func(origin, 0, len);

  if(maxmin==999999) cout << 0;
  else cout << maxmin;
}

void func(int num, int index, int len){
  if(index==len-1){
    check(num, len);
  }
  else{
    for(int i=index; i<len; i++){
      num = swap_int(num, i, index);
      func(num, index+1, len);
    }
  }
}

int swap_int(int num, int p1, int p2){
  int n1 = int(num/pow(10, p1))%10;
  int n2 = int(num/pow(10, p2))%10;
  //cout << "p1: " << p1 << " p2: " << p2 << endl;
  //cout << "n1: " << n1 << " n2: " << n2 << endl;

  num = num - n1*pow(10,p1) + n2*pow(10,p1);
  num = num - n2*pow(10,p2) + n1*pow(10,p2);

  return num;
}

void check(int num, int len){
  //cout << "Compare " << num << " with " << maxmin << endl;
  if(num > origin)
    if(num < maxmin){
      maxmin = num;
    }
}

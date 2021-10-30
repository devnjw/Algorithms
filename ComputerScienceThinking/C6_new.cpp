#include <iostream>

using namespace std;

int N;
int numbers[50000];
int numbers_desc[50000];
int maxnum[50000];
int maxnum_desc[50000];

int LIS[50000];

int main(){
  cin >> N;
  for(int i=0; i<N; ++i){
    cin >> numbers[i];
    numbers_desc[N-i-1] = numbers[i];
  }

  LIS[0] = numbers[0];
  maxnum[0] = 1;
  int sz = 1;

  for(int i=1; i<N; ++i){
    if(numbers[i] > LIS[sz-1]){
      LIS[sz] = numbers[i];
      sz++;
      maxnum[i] = sz;
    }
    else{
      int l=0, r=sz-1;
      int mid = (l+r)/2;
      while(l<r){
        if(numbers[i] < LIS[mid]){
          r = mid;
          mid = (l+r)/2;
        }
        else if(numbers[i] > LIS[mid]){
          l = mid+1;
          mid = (l+r)/2;
        }
        else{
          break;
        }
      }
      LIS[mid] = numbers[i];
      maxnum[i] = mid+1;
    }
  }

  LIS[0] = numbers_desc[0];
  maxnum_desc[0] = 1;
  sz = 1;

  for(int i=1; i<N; ++i){
    if(numbers_desc[i] > LIS[sz-1]){
      LIS[sz] = numbers_desc[i];
      sz++;
      maxnum_desc[i] = sz;
    }
    else{
      int l=0, r=sz;
      int mid = (l+r)/2;
      while(l<r){
        if(numbers_desc[i] < LIS[mid]){
          r = mid;
          mid = (l+r)/2;
        }
        else if(numbers_desc[i] > LIS[mid]){
          l = mid+1;
          mid = (l+r)/2;
        }
        else{
          break;
        }
      }
      LIS[mid] = numbers_desc[i];
      maxnum_desc[i] = mid+1;
    }
  }

  int answer = 0;
  for(int i=0; i<N; ++i){
    int tmp = maxnum[i] + maxnum_desc[N-1-i] - 1;
    if(answer < tmp) answer = tmp;
  }

  cout << answer;


  return 0;
}

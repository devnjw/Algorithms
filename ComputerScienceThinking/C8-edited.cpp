#include <iostream>
#include <algorithm>
#include <cmath>

#define SIZE 10000

using namespace std;

pair<int, int> arr[SIZE];

pair<int, int> get_range(int x, int y, int d){
  pair<int, int> result;
  result.first = x - sqrt(d*d - y*y);
  result.second = x + sqrt(d*d - y*y);
  return result;
}

int main(){
  int N, d;
  cin >> N >> d;

  int x, y;
  for(int i=0; i<N; ++i){
    cin >> x >> y;
    arr[i] = get_range(x, y, d);
  }

  sort(arr, arr+N);

  int min_out = 20000;
  int answer = 0;
  int last_idx = 0;
  for(int i=0; i<N; ++i){
    if(min_out < arr[i].first){
      answer++;
      last_idx = i;
      min_out = arr[i].second;
    }
    else if(arr[i].second < min_out)
      min_out = arr[i].second;
    if(arr[i].first == arr[i].second){
      answer++;
      last_idx = i;
      min_out = 20000;
    }
  }

  if(last_idx < N-1)
    answer++;

  cout << answer;

  return 0;
}

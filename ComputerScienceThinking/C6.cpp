#include <iostream>
#include <vector>
#include <stack>

#define MAXSIZE 50000

using namespace std;

stack<int> s;
int numbers[MAXSIZE];
int connection[MAXSIZE]={-1};
int maxnum[MAXSIZE];
int maxnum_desc[MAXSIZE];
int N;

int main(){
  cin >> N;
  for(int i=0; i<N; ++i)
    cin >> numbers[i];

  connection[0] = -1;
  maxnum[0] = 1;

  for(int i=1; i<N; ++i){
    s.push(i-1);
    while(!s.empty() && numbers[s.top()] < numbers[i]){
      if(maxnum[s.top()] > maxnum[i]){
        maxnum[i] = maxnum[s.top()];
        connection[i] = s.top();
      }
      s.pop();
    }
    if(!s.empty()){
      int next = s.top();
      while(next>=0 && numbers[next] >= numbers[i]){
        next = connection[next];
      }
      if(next>=0 && maxnum[next] > maxnum[i]){
        maxnum[i] = maxnum[next];
        connection[i] = next;
      }
    }
    maxnum[i]++;
  }

  while(!s.empty()) s.pop();
  for(int i=0; i<N; ++i) connection[i] = -1;

  connection[N-1] = -1;
  maxnum_desc[N-1] = 1;

  for(int i=N-2; i>=0; --i){
    s.push(i+1);
    while(!s.empty() && numbers[s.top()] < numbers[i]){
      if(maxnum_desc[s.top()] > maxnum_desc[i]){
        maxnum_desc[i] = maxnum_desc[s.top()];
        connection[i] = s.top();
      }
      s.pop();
    }
    if(!s.empty()){
      int next = s.top();
      while(next>=0 && numbers[next] >= numbers[i]){
        next = connection[next];
      }
      if(next>=0 && maxnum_desc[next] > maxnum_desc[i]){
        maxnum_desc[i] = maxnum_desc[next];
        connection[i] = next;
      }
    }
    maxnum_desc[i]++;
  }

  int answer = 0;
  for(int i=0; i<N; ++i){
    if(maxnum[i]+maxnum_desc[i] > answer){
      answer = maxnum[i]+maxnum_desc[i];
    }
  }
  cout << answer-1;

  return 0;
}

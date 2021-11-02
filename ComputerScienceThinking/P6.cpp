#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int pieces[500][500];
queue<pair<int, int> > q;

int main(){
  cin >> N;
  for(int i=0; i<N; ++i){
    cin >> pieces[i][i];
  }

  for(int i=0; i<N-1; ++i){
    for(int c=i+1; c<N; ++c){
      int r = c-i-1;
      pieces[r][c] = pieces[r][r] + pieces[r+1][c];
    }
  }

  long long answer = 0;

  q.push(make_pair(0, N-1));

  while(!q.empty()){
    int r = q.front().first;
    int c = q.front().second;
    q.pop();
    answer += pieces[r][c];

    int mn = 5000000;
    int x1, x2, y1, y2;
    for(int k=0; k<c-r+1; ++k){
      if(abs(pieces[r][r+k]-pieces[r+1+k][c]) <= mn){
        y1 = r;
        x1 = r+k;
        y2 = r+1+k;
        x2 = c;
        mn = abs(pieces[r][r+k]-pieces[r+1+k][c]);
      }
    }
    if(x1!=y1)
      q.push(make_pair(y1, x1));
    if(x2!=y2)
      q.push(make_pair(y2, x2));
  }

  cout << answer;

  return 0;
}

#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int> > q1;
queue<pair<int, int> > q2;

int main(){
  int answer = 0;
  int F, G, a, c, p, q;

  cin >> F;
  for(int i=0; i<F; ++i){
    cin >> a >> c;
    q1.push(make_pair(a, c));
  }

  cin >> G;
  for(int i=0; i<G; ++i){
    cin >> a >> c;
    q2.push(make_pair(a, c));
  }

  cin >> p >> q;
  int f=0, g=0;
  for(a=p; a<=q; ++a){
    if(!q1.empty() && q1.front().first <= a){
      f = q1.front().second;
      q1.pop();
    }
    if(!q2.empty() && q2.front().first <= a){
      g = q2.front().second;
      q2.pop();
    }
    c = f;
    if(g>f) c = g;
    answer += c;
  }

  cout << answer;

  return 0;
}

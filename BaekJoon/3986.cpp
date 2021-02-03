#include <iostream>
#include <stack>

using namespace std;

int N, cnt;
stack<int> s;

int main() {
  cin >> N;
  for(int i=0;i<N;i++)
  {
    string str;
    cin >> str;
    for(int i=0;i<str.length();i++)
    {
      if(s.empty()) s.push(str.at(i));
      else{
        if(s.top()==str.at(i)) s.pop();
        else s.push(str.at(i));
      }
    }
    if(s.empty()) cnt++;
    while(!s.empty()) s.pop();
  }
  cout << cnt;
}

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Word{
  char s;
  char e;
  int i;
  int used;
}

int N;
string arr[1000];
vector<pair<string, int> > words[26];
stack<string> answer;

bool DFS(int n, int depth){
  if(depth==N)
    return true;

  string str;
  for(int i=0; i<(int)words[n].size(); ++i){
    if(words[n][i].second == 0){
      words[n][i].second = 1;
      str = words[n][i].first;
      answer.push(str);

      if(DFS(str[str.size()-1]-'a', depth+1))
        return true;

      answer.pop();
      words[n][i].second = 0;
    }
  }

  return false;
}

int main(){
  cin >> N;

  for(int i=0; i<N; ++i){
    cin >> arr[i];
  }

  sort(arr, arr+N);

  string tmp;
  for(int i=0; i<N; ++i){
    tmp = "";
    tmp += arr[i][0];
    tmp += arr[i][arr[i].size()-1];
    words[arr[i][0]-'a'].push_back(make_pair(tmp, 0));
  }

  int st;
  for(st=0; st<26; ++st)
    if(DFS(st, 0))
      break;

  if(st==26){
    cout << 0;
    return 0;
  }

  stack<string> temp_st;
  while(!answer.empty()){
    temp_st.push(answer.top());
    answer.pop();
  }
  while(!temp_st.empty()){
    cout << temp_st.top() << "\n";
    temp_st.pop();
  }

  return 0;
}

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int start_chars[26];
int end_chars[26];
queue<string> words[26];

int main(){
  cin >> N;

  string tmp;
  for(int i=0; i<N; ++i){
    cin >> tmp;
    start_chars[tmp[0]-'a']++;
    end_chars[tmp[tmp.size()-1]-'a']++;
    words[tmp[0]-'a'].push(tmp);
  }

  int st = -1, end = -1;
  for(int i=0; i<26; ++i){
    if(start_chars[i] > end_chars[i]){
      if(st!=-1){
        cout << 0;
        return 0;
      }
      else
        st = i;
    }
    else if(start_chars[i] < end_chars[i]){
      if(end!=-1){
        cout << 0;
        return 0;
      }
      else
        end = i;
    }
  }

  while(!words[st].empty()){
    tmp = words[st].front();
    words[st].pop();
    cout << tmp << "\n";
    st = tmp[tmp.size() - 1] - 'a';
  }

  return 0;
}

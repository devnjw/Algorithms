#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int N;
string arr[1000];
vector<pair<string, int> > words[26];
vector<string> answer;

int start_c_cnt[26];
int end_c_cnt[26];

bool DFS(int e, int n, int depth){
  if(depth==N)
    return true;
  else if(end_c_cnt[e]==0)
    return false;

  string str;
  for(int i=0; i<(int)words[n].size(); ++i){
    if(words[n][i].second == 0){
      words[n][i].second = 1;
      str = words[n][i].first;
      answer.push_back(str);
      end_c_cnt[str[str.size()-1]-'a']--;

      if(DFS(e, str[str.size()-1]-'a', depth+1))
        return true;

      end_c_cnt[str[str.size()-1]-'a']++;
      answer.pop_back();
      words[n][i].second = 0;
    }
  }

  return false;
}

int main(){
  cin >> N;

  for(int i=0; i<N; ++i){
    cin >> arr[i];
    start_c_cnt[arr[i][0]-'a']++;
    end_c_cnt[arr[i][arr[i].size()-1]-'a']++;
  }

  sort(arr, arr+N);

  for(int i=0; i<N; ++i){
    words[arr[i][0]-'a'].push_back(make_pair(arr[i], 0));
  }

  int s = -1, e = -1;
  for(int i=0; i<26; ++i){
    if(start_c_cnt[i] > end_c_cnt[i]){
      if(s!=-1){
        cout << 0;
        return 0;
      }
      else
        s = i;
    }
    else if(start_c_cnt[i] < end_c_cnt[i]){
      if(e!=-1){
        cout << 0;
        return 0;
      }
      else
        e = i;
    }
  }

  int result;
  if(e==-1){
    result = DFS(arr[0][0]-'a', arr[0][0]-'a', 0);
  }
  else{
    result = DFS(e, s, 0);
  }

  if(result == 0){
    cout << 0;
    return 0;
  }

  for(int i=0; i<(int)answer.size(); ++i)
    cout << answer[i] << "\n";

  return 0;
}

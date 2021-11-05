#include <iostream>
#include <vector>

#define SIZE 10000

using namespace std;

int group[SIZE+1];
int day[SIZE+1];
int N, M;

vector<vector<int> > group_member;

int find(int x){
  if (x==group[x]){
    return x;
  }
  else{
    int y = find(group[x]);
    group[x] = y;
    return y;
  }
}

void Print(){
  for(int i=1; i<=N; ++i){
    cout << i << ": ";
    for(int j=0; j<group_member[i].size(); ++j){
      cout << group_member[i][j] << "(" << day[group_member[i][j]] << ") - " ;
    }
    cout << endl;
  }
  cout << endl;
}

void merge(int x, int y){
  int tmp;
  int day_x = day[x];
  int day_y = day[y];
  x = find(x);
  y = find(y);
  while(group_member[x].size() > 0){
    tmp = group_member[x].back();
    group_member[y].push_back(tmp);
    group[tmp] = y;
    if(day_x == day_y)
      day[tmp] = (day[tmp]%2)+1;
    group_member[x].pop_back();
  }
}

int main(){
  cin >> N >> M;

  for(int i=0; i<=N; ++i){
    vector<int> tmp;
    group_member.push_back(tmp);
  }

  int a, b;
  for(int i=0; i<M; ++i){
    cin >> a >> b;

    if(group[a]==0 && group[b]==0){
      group[a] = a;
      day[a] = 1;
      group[b] = a;
      day[b] = 2;
      group_member[a].push_back(a);
      group_member[a].push_back(b);
    }
    else if(group[a]!=0 && group[b]==0){
      group[b] = find(a);
      group_member[find(a)].push_back(b);
      day[b] = (day[a]%2)+1;
    }
    else if(group[b]!=0 && group[a]==0){
      group[a] = find(b);
      group_member[find(b)].push_back(a);
      day[a] = (day[b]%2)+1;
    }
    else{ // If Both Has Group
      if(find(a) == find(b)){
        if(day[a] == day[b]){
          cout << i+1;
          break;
        }
      }
      else{
        merge(b, a);
      }
    }
  }

  return 0;
}

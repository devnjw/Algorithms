#include <iostream>
#define SIZE 10000

using namespace std;

int group_connection[SIZE][SIZE];
int group[SIZE+1];
int day[SIZE+1];
int num_groups=1;
int N, M;

bool check_the_case_both_has_group(int a, int b){
  if(group[a] == group[b]){
    if(day[a] == day[b])
      return false;
  }
  else{
    if(group_connection[group[a]][group[b]] == 0){
      if(day[a] == day[b]){
        group_connection[group[a]][group[b]] = -1;
        group_connection[group[b]][group[a]] = -1;
      }
      else{
        group_connection[group[a]][group[b]] = 1;
        group_connection[group[b]][group[a]] = 1;
      }
    }
    else if(group_connection[group[a]][group[b]] == 1){
      if(day[a] == day[b])
        return false;
    }
    else if(group_connection[group[a]][group[b]] == -1){
      if(day[a] != day[b])
        return false;
    }
  }
  return true;
}

int main(){
  cin >> N >> M;

  int a, b;
  for(int i=1; i<=M; ++i){
    cin >> a >> b;
    if(group[a] == 0 && group[b] == 0){
      group[a] = num_groups;
      group[b] = num_groups;
      num_groups++;
      day[a] = 1;
      day[b] = 2;
    }
    else if(group[a] * group[b] == 0){
      if(group[a] > 0 && group[b] == 0){
        group[b] = group[a];
        day[b] = (day[a]%2)+1;
      }
      else if(group[b] > 0 && group[a] == 0){
        group[a] = group[b];
        day[a] = (day[b]%2)+1;
      }
    }
    else{
      if(check_the_case_both_has_group(a, b) == false){
        cout << i;
        return 0;
      }
    }
  }

  return 0;
}

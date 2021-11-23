#include <iostream>

using namespace std;

int scores[8001][2];
int group[8001];

int find_group(int num){
  if(group[num] == num)
    return num;
  group[num] = find_group(group[num]);
  return group[num];
}

bool check_rules(int a, int b){
  if(scores[a][0] < scores[b][0] && scores[a][1] > scores[b][1])
    return true;
  if(scores[a][0] > scores[b][0] && scores[a][1] < scores[b][1])
    return true;
  return false;
}

int main(){
  int groups = 0;
  int N;
  cin >> N;

  for(int i=1; i<=N; ++i){
    cin >> scores[i][0] >> scores[i][1];
    group[i] = i;
    groups++;

    for(int j=1; j<i; ++j){
      if(find_group(i) != find_group(j) && check_rules(i, j)){
        group[find_group(i)] = find_group(j);
        groups--;
      }
    }
  }

  cout << groups;

  return 0;
}

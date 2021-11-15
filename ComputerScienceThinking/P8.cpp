#include <iostream>
#include <vector>
#include <algorithm>
#define TYPE long long

using namespace std;

vector<pair<TYPE, TYPE> > people;

bool cmp(pair<TYPE, TYPE> a, pair<TYPE, TYPE> b){
  if(a.first > b.first) return true;
  else if(a.first == b.first){
    if(a.second < b.second){
      return true;
    }
  }
  return false;
}

int N, T;
int main(){
  cin >> N >> T;
  TYPE p, v;
  for(int i=0; i<N; ++i){
    cin >> p >> v;
    people.push_back(make_pair(p, v));
  }

  sort(people.begin(), people.end(), cmp);

  int groups = N;
  for(int i=1; i<N; ++i){
    if(people[i].first + people[i].second * T >= people[i-1].first + people[i-1].second * T){
      people[i].first = people[i-1].first;
      people[i].second =  people[i-1].second;
      groups--;
    }
  }

  cout << groups;

  return 0;
}
